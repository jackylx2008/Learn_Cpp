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

// for_each 使用的两种方法
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

// transform 使用方法
class Transform_person {
  public:
    Person operator()(Person p) { // 不能采用引用的方式, 会把源自定义数据给改了
        p.m_age += 10;
        return p;
    }
};
void test02() {
    std::vector<Person> v1;
    std::vector<Person> v2;
    v1.push_back(Person("liu", 10));
    v1.push_back(Person("xin", 20));
    v1.push_back(Person("luo", 50));
    v1.push_back(Person("ya", 90));
    v2.resize(v1.size());
    std::for_each(v1.begin(), v1.end(), Show_person());
    std::cout << "" << std::endl;
    std::transform(v1.begin(), v1.end(), v2.begin(), Transform_person());
    std::for_each(v2.begin(), v2.end(), Show_person());
    std::cout << "" << std::endl;
    std::for_each(v1.begin(), v1.end(), Show_person());
}
int main(int argc, char *argv[]) {
    // test01();
    test02();

    return 0;
}
