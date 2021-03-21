#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

class AlexMedian{
    public:
    AlexMedian(int k);

    double filter(double x);

    ~AlexMedian(){};

    private:
    double m_y;
    int m_size;
    int m_head;
    std::vector<double> m_buffer;
    std::vector<double> m_sortedBuffer;

};