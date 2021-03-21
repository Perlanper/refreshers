#include <iostream>
#include <vector>

#include "inputVector.h"

void printVector(std::vector<double> vector){
    for (int i = 0; i < vector.size(); i++){
        if (i == 0){
            std::cout << "[ ";
        }
        std::cout << vector[i] << " ";
    }
    std::cout << "]";
}

std::vector<double> takeInput(int entrys){
    std::vector<double> inputVector;
    std::vector<double>::iterator it;
    double placeHolder;
    for (int i = 0; i < entrys; i++){
        std::cin >> placeHolder;
        it = inputVector.begin();
        inputVector.insert(it,placeHolder);
        printVector(inputVector);
        std::cout << std::endl;
    }
    return inputVector;
}
