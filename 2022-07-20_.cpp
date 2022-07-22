#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

// 常用算法 find find_if
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
        if (p.m_age > 30) {
            return true;
        }
        else {
            return false;
        }
    }
};
void test01() {
    std::vector<Person> v;
    v.push_back(Person("liu", 10));
    v.push_back(Person("xin", 20));
    v.push_back(Person("luo", 50));
    v.push_back(Person("ya", 90));

    Person v_target = Person("ya1", 90);

    std::for_each(v.begin(), v.end(), Show_person());
    std::cout << "" << std::endl;
    std::vector<Person>::iterator v_pos =
        std::find(v.begin(), v.end(), v_target);
    if (v_pos == v.end())
        std::cout << "test01 find " << std::endl;
    else
        std::cout << "test01 find" << std::endl;
}
void test02() {
    std::vector<Person> v;
    v.push_back(Person("liu", 10));
    v.push_back(Person("xin", 20));
    v.push_back(Person("luo", 50));
    v.push_back(Person("yi", 40));
    v.push_back(Person("ya", 90));
    std::vector<Person>::iterator v_pos =
        std::find_if(v.begin(), v.end(), OldPerson());
    if (v_pos == v.end())
        std::cout << "test02 find " << std::endl;
    else
        std::cout << "test02 find" << std::endl;
    while (v_pos != v.end()) {
        std::cout << "v_pos = " << (*v_pos).m_name << std::endl;
        v_pos++;
        v_pos = std::find_if(v_pos, v.end(), OldPerson());
    }
}

int main(int argc, char *argv[]) {
    // test01();
    test02();

    return 0;
}
