#include "MovingMedianFilter.h"

MovingMedianFilter::MovingMedianFilter(int k, const std::vector<double> inputVector)
    : m_kSize(k)
    , m_inputVector(inputVector)
    {}

int MovingMedianFilter::getKSize(){
    return m_kSize;
}
std::vector<double> MovingMedianFilter::getInputVector(){
    return m_inputVector; 
}

std::vector<double> MovingMedianFilter::getMovingVector(){
    return m_movingVector;
}

std::vector<double> MovingMedianFilter::getMedianVector(){
    return m_medianVector;
}

void MovingMedianFilter::setMovingVector(std::vector<double>::iterator it_input,std::vector<double>::iterator head,std::vector<double>::iterator tail){
        //std::vector<double>::iterator poop = this->m_inputVector.end();
        int stepFront = ceil(this->m_kSize/2); 
        m_movingVector.clear(); 
        
        if (it_input < head + floor(this->m_kSize/2)){ // in begining
            for(int i = 0; i <= stepFront; i++){
                m_movingVector.push_back(*it_input);
                it_input++;
            }
        }
        else if (it_input < tail){
            it_input--;
            for (int k = 0; k < this->m_kSize; k++){ //middle
                m_movingVector.push_back(*it_input);
                it_input++;
            }
            
        }
        else{
            for(int j = 0; j <= stepFront; j++){  //at end
                m_movingVector.push_back(*it_input);
                it_input--;
            }
        }
        
        
        
    //for (int i = 0; i < this->m_kSize; i++){  
       // m_movingVector.push_back(this->m_inputVector.at(i));
}


void MovingMedianFilter::calcMedian(){
    std::sort(this->m_movingVector.begin(),this->m_movingVector.end());
    if (this->m_movingVector.size() % 2 == 1){ //odd windowsize
        m_medianVector.push_back(this->m_movingVector.at(floor(this->m_kSize/2)));
    }
    else{ //even wondowsize
        double meanValue = (this->m_movingVector.at(this->m_kSize/2) + this->m_movingVector.at((this->m_kSize/2)-1))/2;
        m_medianVector.push_back(meanValue);
    }
}
 
void MovingMedianFilter::filter(){
    std::vector<double>::iterator it, head, tail;
    it = this->m_inputVector.begin();
    head = this->m_inputVector.begin();
    tail = this->m_inputVector.end() - 1;
    for (it; it != this->m_inputVector.end(); it++){
        this->setMovingVector(it, head, tail);
        calcMedian();
    }
}
void MovingMedianFilter::printMedian(){
    for (int i = 0 ; i < this->m_medianVector.size();i++){
            std::cout << this->m_medianVector.at(i) << " ";
        }
        std::cout << std::endl;
}
    // array -> [3 6 2 1 7 6 7 5 9] -> [3 2 2 6 7 6 7 7 9]
    // k=3        [6 2 1]
    // sort     [1 2 6] -> 2
    // sort     [2 3 6] -> 3
    // Median   [3 2 2 6 7 6 7 7 9]

    //iterate over inputvector
    //check if close to end
    //call setMovingVector and calcMedian


    //[4 1 4 2 5]

    //it = array.begin()
    //while(it !=array.end())
        //if (it == it.begin()){
            //do_something()
        //}
        //else
            // doSomethingElse()
        //it++


