#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

// 常用算法 for_each transform
class Person {
  public:
    Person() {
        this->m_name = "None";
        this->m_age = 0;
    }
    Person(std::string name, int age) {
        this->m_name = name;
        this->m_age = age;
    }
    std::string m_name;
    int m_age;
};
class Show_person {
  public:
    void operator()(Person &p) {
        std::cout << "m_name = " << p.m_name << " m_age = " << p.m_age
                  << std::endl;
    }
};

void show_person(Person &p) {
    std::cout << "m_name = " << p.m_name << " m_age = " << p.m_age << std::endl;
};

void test01() {
    std::vector<Person> v;
    v.push_back(Person("liu", 10));
    v.push_back(Person("xin", 20));
    v.push_back(Person("luo", 50));
    v.push_back(Person("ya", 90));

    std::for_each(v.begin(), v.end(), Show_person());
    std::cout << "" << std::endl;
    std::for_each(v.begin(), v.end(), show_person);
}

int main(int argc, char *argv[]) {
    test01();

    return 0;
}
