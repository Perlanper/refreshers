#include"ShoeSizes.h"

std::vector <int> sizesVector = {36,365,38,39,4,38,40};
std::vector <std::string> namesvector = {"Per", "Alex", "John", "Thomas", "Daniel", "Per", "Dick"};

int main(){
    auto a = ShoeSizes(sizesVector, namesvector);

    int popularSize = a.mostPopularSize();
    std::string popularName = a.mostPopularName();
    
    std::cout << popularSize << " " << popularName;

    return 0;
}