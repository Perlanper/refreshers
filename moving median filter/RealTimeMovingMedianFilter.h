#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

class RealTimeMovingMedianFilter{
    public:
    RealTimeMovingMedianFilter(int k);

    void takeInput();
    void calcMedian();
    void printMedian();
    void filter();

    ~RealTimeMovingMedianFilter(){};

    private:
    int m_windowSize;
    std::vector<double> m_window;
    std::vector<double> m_medianVector;
};