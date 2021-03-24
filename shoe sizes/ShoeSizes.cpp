#include "ShoeSizes.h"
#include <map>

ShoeSizes::ShoeSizes(std::vector<int> sizes, std::vector<std::string> names)
:m_shoeSizes(sizes)
,m_names(names)
{};

int ShoeSizes::mostPopularSize(){

    std::map<int,int> mapSizes;
    for (int i = 0; i < m_shoeSizes.size(); i++){
        
        if (m_shoeSizes[i] == mapSizes.find(m_shoeSizes[i])->first && mapSizes.find(m_shoeSizes[i]) != mapSizes.end()){
            mapSizes.find(m_shoeSizes[i])->second++;
        }

        else{
            mapSizes.insert(std::pair<int, int>(m_shoeSizes[i], 1));
        }
    }

    int isUnique = 0;
    int uniqueValue = 0;
    int uniqueKey = 0;

    for(std::map<int,int>::iterator it = mapSizes.begin(); it != mapSizes.end(); it++){

        if (it->second > uniqueValue){
            isUnique = 1;
            uniqueValue = it->second;
            uniqueKey = it->first;
        }
        else if (it->second == uniqueValue){
            isUnique++;
            uniqueValue = it->second;
            uniqueKey = it->first;
        }
    }

    if (isUnique > 1){
        return -1;
    }

    else {
        return uniqueKey;}
}

std::string ShoeSizes::mostPopularName(){

    int mostPopularSize = this->mostPopularSize();
    if (mostPopularSize == -1){
        return "";
    }

    std::map<std::string, int> mapNames;
    std::vector<std::string>::iterator it;
    std::vector<int>::iterator size_it = m_shoeSizes.begin();

    for (it = m_names.begin(); it < m_names.end();it++){

        if (*it == mapNames.find(*it)->first && *size_it == mostPopularSize){
            mapNames.find(*it)->second++;
        }
        else if(*size_it == mostPopularSize){

            mapNames.insert(std::pair<std::string,int>(*it, 1));
        }
        size_it++;
    }

    int isUnique = 0;
    int uniqueValue = 0;
    std::string uniqueKey = "";

    std::map<std::string, int>::iterator map_it;

    for (map_it = mapNames.begin(); map_it != mapNames.end(); map_it++){

        if (map_it->second > uniqueValue){
            isUnique = 1;
            uniqueValue = map_it->second;
            uniqueKey = map_it->first;
        }

        else if (map_it->second == uniqueValue){
            isUnique++;
            uniqueValue = map_it->second;
            uniqueKey = map_it->first;
        }
    }

    if (isUnique > 1){
        return "";
    }

    else{
        return uniqueKey;
    }

}