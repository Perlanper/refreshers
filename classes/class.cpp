#include <iostream>
#include <string>
#include <memory>
//Interface IPerson.h-------------------------------------------------
class IPerson{
    public:
        virtual std::string getName() = 0;
        virtual int getAge() = 0;
        virtual std::string getCountry() = 0;
        ~IPerson(){};
    
};
//---------------------------------------------------------------------

//header Person.h------------------------------------------------------

class Person : public IPerson{
    public:

    Person(std::string name, int age, std::string country);
    std::string getName();
    std::string getCountry();
    int getAge();

    ~Person(){};

    private:
    class Impl;
    std::unique_ptr<Impl> m_upImpl;

};
//--------------------------------------------------------------------

// Person.cpp---------------------------------------------------------
class Person::Impl{
    public:

    Impl(std::string name, int age, std::string country)
    : m_name(name)
    , m_age(age)
    , m_country(country)
    {}

    std::string getName(){
        return m_name;
    }

    int getAge(){
        return m_age;
    }

    std::string getCountry(){
        return m_country;
    }

   

    private:
    std::string m_name;
    int m_age;
    std::string m_country;


};

Person::Person(std::string name, int age, std::string country)
    :m_upImpl(std::make_unique<Impl>(name,age,country))
    {}

std::string Person::getName()
{
    return m_upImpl->getName();
}

int Person::getAge()
{
    return m_upImpl->getAge();
}

std::string Person::getCountry()
{
    return m_upImpl->getCountry();
}
//--------------------------------------------------------------------------

//PersonFactory.h-----------------------------------------------------------
//#include "Person.h"
std::unique_ptr<IPerson> createPerson(std::string name, int age, std::string country);

//PersonFactory.cpp----------------------------------------------------------
//include "PersonFactory.h"
std::unique_ptr<IPerson> createPerson(std::string name, int age, std::string country){
    std::unique_ptr<IPerson> person(std::make_unique<Person>(name,age,country));
    return person;
}

// main.cpp-----------------------------------------------------------------
int main(){
    auto person = createPerson("Per", 25, "Sweden");
    auto person2 = createPerson("Alex", 29,"Serbia");
    std::cout << person->getName() << " " << person->getAge() << " "  << person->getCountry() << std::endl;

    return 0;
}
//--------------------------------------------------------------------------