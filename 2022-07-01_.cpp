#include <iostream>
#include <map>
#include <string>
#include <utility>

// map 容器
class Person {
  public:
    int m_age;
    int m_height;
    std::string m_name;
    Person(std::string name, int age, int height) {
        m_name = name;
        m_age = age;
        m_height = height;
    }
    Person() {
        m_name = "None";
        m_age = 0;
    }
};
//仿函数
class my_compare {
  public:
    bool operator()(const Person &p1, const Person &p2) {
        if (p1.m_height == p2.m_height)
            return p1.m_age > p2.m_age;
        else
            return p1.m_age < p2.m_age;
    }
};
int main(int argc, char *argv[]) {
    std::map<double, double> m;
    m[234] = 34;
    m.insert({34, 3434});
    m.insert({34.34, 343.4});
    m.insert(std::pair<int, int>(1, 111));
    m.insert(std::pair<int, int>(6, 211));
    m.insert(std::pair<int, int>(3, 311));
    for (std::map<double, double>::iterator i = m.begin(); i != m.end(); i++) {
        std::cout << "key = " << i->first;
        std::cout << "  val = " << i->second << std::endl;
    }

    // key为内置数据类型排序
    std::map<int, Person> m1;
    Person p1("liu", 20, 10);
    Person p2("xin", 30, 10);
    m1.insert({3, p1});
    m1.insert(std::pair<int, Person>(5, p2));
    m1.insert({6, Person("luo", 3, 5)});
    for (std::map<int, Person>::iterator i = m1.begin(); i != m1.end(); i++) {
        std::cout << "key = " << i->first;
        std::cout << "  val = " << i->second.m_name << std::endl;
    }
    std::map<Person, Person, my_compare> m2;
    m2.insert({Person("liu", 1, 2), Person("xin", 3, 5)});
    m2.insert({Person("luo", 4, 2), Person("ya", 7, 8)});
    std::cout << " " << std::endl;

    // key为自定义数据类型排序
    for (std::map<Person, Person, my_compare>::iterator i = m2.begin();
         i != m2.end(); i++) {
        std::cout << "key = " << i->first.m_name;
        std::cout << "  val = " << i->second.m_name << std::endl;
    }

    return 0;
}
