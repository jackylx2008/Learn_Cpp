#include <algorithm>
#include <iostream>
#include <list>
#include <string>

// list 自定义 数据类型 排序
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

bool my_compare(Person &p1, Person &p2) {
    if (p1.m_height == p2.m_height)
        return p1.m_age > p2.m_age;
    else
        return p1.m_age < p2.m_age;
}

void print_list(std::list<Person> &l) {
    for (std::list<Person>::iterator i = l.begin(); i != l.end(); i++) {
        std::cout << "Name = " << i->m_name << "  Age = " << i->m_age
                  << " height = " << i->m_height << std::endl;
    }
}

void test01() {
    Person p1("liu", 20, 10);
    Person p2("xin", 30, 10);
    Person p3("luo", 50, 15);
    Person p4("ya", 10, 14);
    Person p5("yizhuo", 3, 13);
    std::list<Person> l;
    l.push_back(p1);
    l.push_back(p2);
    l.push_back(p3);
    l.push_back(p4);
    l.push_back(p5);
    print_list(l);
    std::cout << "" << std::endl;
    l.sort(my_compare);
    print_list(l);
}
int main(int argc, char *argv[]) {
    test01();
    return 0;
}
