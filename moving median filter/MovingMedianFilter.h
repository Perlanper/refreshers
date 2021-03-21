#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

class MovingMedianFilter{
    public:
    MovingMedianFilter(int k, const std::vector<double> inputVector);
    
    int getKSize();
    std::vector<double> getInputVector();
    std::vector<double> getMovingVector();
    std::vector<double> getMedianVector();
    void setMovingVector(std::vector<double>::iterator it_input, std::vector<double>::iterator head,std::vector<double>::iterator tail);
    void calcMedian();
    void filter();
    void printMedian();

    ~MovingMedianFilter(){};

    private:
    int m_kSize;
    std::vector<double> m_inputVector;
    std::vector<double> m_movingVector;
    std::vector<double> m_medianVector;
};