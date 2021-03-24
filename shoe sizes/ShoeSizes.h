#include <iostream>
#include <vector>
#include <string>

class ShoeSizes{
    public:
    ShoeSizes(std::vector<int> sizes, std::vector<std::string> names);
    int mostPopularSize();
    std::string mostPopularName();

    private:
    std::vector<int> m_shoeSizes;
    std::vector<std::string> m_names;
};
