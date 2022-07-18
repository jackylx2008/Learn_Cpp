#include <iostream>
#include <set>
#include <string>

// set 仿函数排序

// 内置数据类型仿函数
class Compare {
  public:
    bool operator()(int a, int b) {
        if (a > b) {
            return true;
        }
        else {
            return false;
        }
    }
};
void test01() { // 默认自动排序
    std::set<int> s1;
    for (int i = 0; i < 5; i++) {
        s1.insert(i);
    }
    for (std::set<int>::iterator i = s1.begin(); i != s1.end(); i++) {
        std::cout << "s = " << *i << std::endl;
    }
}
void test02() { // 使用仿函数排序
    std::set<int, Compare> s2;
    for (int i = 0; i < 5; i++) {
        s2.insert(i);
    }
    for (std::set<int>::iterator i = s2.begin(); i != s2.end(); i++) {
        std::cout << "s = " << *i << std::endl;
    }
}

// 自定义数据类型排序
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
class Person_Compare {
  public:
    bool operator()(const Person &p1, const Person &p2) {
        if (p1.m_height == p2.m_height)
            return p1.m_age > p2.m_age;
        else
            return p1.m_age < p2.m_age;
    }
};
void test03() {
    std::set<Person, Person_Compare> s3;
    Person p1("liu", 20, 10);
    Person p2("xin", 30, 10);
    Person p3("luo", 50, 15);
    Person p4("ya", 10, 14);
    Person p5("yizhuo", 3, 13);
    s3.insert(p1);
    s3.insert(p2);
    s3.insert(p3);
    s3.insert(p4);
    s3.insert(p5);
    for (std::set<Person, Person_Compare>::iterator i = s3.begin();
         i != s3.end(); i++) {
        std::cout << "Name = " << i->m_name << "  Age = " << i->m_age
                  << " height = " << i->m_height << std::endl;
    }
}
int main(int argc, char *argv[]) {
    test03();
    return 0;
}
