#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

// 常用算法 count count_if
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
    bool operator==(const Person &p) {
        if (this->m_age == p.m_age && this->m_name == p.m_name) {
            return true;
        }
        else {
            return false;
        }
    }
};
class Show_person {
  public:
    void operator()(Person &p) {
        std::cout << "m_name = " << p.m_name << " m_age = " << p.m_age
                  << std::endl;
    }
};
class OldPerson {
  public:
    bool operator()(const Person &p) {
        if (p.m_age > m_age) {
            return true;
        }
        else {
            return false;
        }
    }
    int m_age;
    void set_age(int age) {
        m_age = age;
    }
};
void test01() {
    std::vector<Person> v;
    v.push_back(Person("liu", 10));
    v.push_back(Person("xin", 20));
    v.push_back(Person("luo", 50));
    v.push_back(Person("ya", 90));
    v.push_back(Person("ya", 90));
    v.push_back(Person("ya", 90));

    std::for_each(v.begin(), v.end(), Show_person());
    int n = std::count(v.begin(), v.end(), Person("ya", 90));
    std::cout << "Count n = " << n << std::endl;
}
void test02() {
    std::vector<Person> v;
    v.push_back(Person("liu", 10));
    v.push_back(Person("xin", 20));
    v.push_back(Person("luo", 50));
    v.push_back(Person("yi", 40));
    v.push_back(Person("ya", 90));

    std::for_each(v.begin(), v.end(), Show_person());
    OldPerson old;
    old.set_age(30);
    int n = std::count_if(v.begin(), v.end(), OldPerson());
    std::cout << "OldPerson n = " << n << std::endl;
}

int main(int argc, char *argv[]) {
    test01();
    test02();

    return 0;
}
