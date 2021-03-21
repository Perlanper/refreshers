#include <iostream>
#include <vector>

#include "inputVector.h"
#include "MovingMedianFilter.h"
#include "RealTimeMovingMedianFilter.h"
#include "Tests.h"
#include "AlexMedian.h"

//MovingMedianFilter.cpp: Filter for predefined arrays, first attempt
//RealTimeMovingMedianFilter.cpp: Filter for real time values, input from keyboard
//AlexMedian.cpp: Code review with Alex with an alternative solution for real time values

int main(){
    //--------------------------MovingMedianFilter-------------------------

    //std::vector<double> testVector = takeInput(6);
    //auto a = MovingMedianFilter(3,testVector);
    //std::vector<double>::iterator it = a.getInputVector().begin();
    //a.filter();
    //a.printMedian();

    //---------------------------------------------------------------------

    //----------------------RealTimeMovingMedianFilter---------------------

    auto b = RealTimeMovingMedianFilter(3);
    b.filter();

    //---------------------------------------------------------------------

    //------------------------------MedianAlex-----------------------------

//    auto alex = AlexMedian(3);
//    double x;
//    double median;
//    while(true)
//    {
//         std::cin >> x;
//         median = alex.filter(x);
//         std::cout << median << std::endl;
//    }

    //---------------------------------------------------------------------
    
     return 0;
}
