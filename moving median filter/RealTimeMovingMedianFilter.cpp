#include "RealTimeMovingMedianFilter.h"

RealTimeMovingMedianFilter::RealTimeMovingMedianFilter(int k)
:m_windowSize(k)
{
    m_window.resize(k, 0);
}

using doubleV_it = std::vector<double>::iterator;

void RealTimeMovingMedianFilter::takeInput(){
    while(true){
    double x;

    if (std::cin >> x){
        if (this->m_window.size() == this->m_windowSize){
            doubleV_it it = this->m_window.begin();
            this->m_window.erase(it);
        }

    this->m_window.push_back(x);
    break;

    }
    else{
        std::cout << "Invalid input! Enter a numerical value." << std::endl;
        std::cin.clear();
        while(std::cin.get() != '\n');
    }
    }   
}

void RealTimeMovingMedianFilter::calcMedian(){
    std::vector<double> windowCpy = m_window;
    doubleV_it itBegin = windowCpy.begin();
    doubleV_it itEnd = windowCpy.end();

    std::sort(itBegin,itEnd);

    if (this->m_window.size() % 2 == 1){ //odd num of elements
        int medianIndex = floor(this->m_windowSize/2);
        m_medianVector.push_back(windowCpy.at(medianIndex));
    }
    else{ //even num of elements
        int upperIndex = this->m_windowSize/2;
        int lowerIndex = upperIndex - 1;
        double meanValue = (windowCpy.at(upperIndex) + windowCpy.at(lowerIndex))/2;
        m_medianVector.push_back(meanValue);
    }
}

void RealTimeMovingMedianFilter::printMedian(){
    doubleV_it it = this->m_medianVector.begin();

    if (this->m_medianVector.empty()){
        std::cout << "[]" << std::endl;
    }
    else{
        std::cout << "[ ";
        for(it; it != this->m_medianVector.end(); it++){
            std::cout << *it << " ";
        }

        std::cout << "]" << std::endl;
    }        
}

void RealTimeMovingMedianFilter::filter(){
    while(true){
        this->takeInput();
        doubleV_it it = this->m_window.begin();

        for (it; it < this->m_window.end(); it++){
            std::cout << *it << " ";
        }

        std:: cout << std::endl;

        if (this->m_window.size() >= 2){
            this->calcMedian();           
        }

        this->printMedian();
    }
}