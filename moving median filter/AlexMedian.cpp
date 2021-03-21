#include "AlexMedian.h"

AlexMedian::AlexMedian(int k)
:m_size(k)
,m_head(0)
{
    m_buffer.resize(k, 0);
}

double AlexMedian::filter(double x)
{
    m_buffer[m_head] = x;

    m_head++;

    if (m_head == m_size)
    {
        m_head = 0;
    }

    m_sortedBuffer = m_buffer;

    std::sort(m_sortedBuffer.begin(), m_sortedBuffer.end());

    int middle = m_size/2;

    if (middle % 2 == 1) //Median
    { 
        m_y = m_sortedBuffer[middle];
    }
    else //Mean
    {
        m_y = 0.5*(m_sortedBuffer[middle - 1] + m_sortedBuffer[middle]);
    }
    return m_y;
}