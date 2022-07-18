#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <iostream>
#include <string>
#include <unistd.h>
#include <vector>

// 学习STL--3 vector 容器
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

// size and capacity
void test01() {
    std::vector<Person> v;
    v.push_back(Person("liu", 10));
    v.push_back(Person("xin", 20));
    v.push_back(Person("luo", 50));
    v.push_back(Person("ya", 90));
    Person temp = Person("NO", 100);
    std::vector<Person>::iterator v_begin = v.begin();
    std::vector<Person>::iterator v_end = v.end();

    // v.resize(10);
    v.resize(10, temp);

    for (std::vector<Person>::const_iterator i = v.begin(); i != v.end(); i++) {
        std::cout << "v[i] = " << (*i).m_name << std::endl;
        std::cout << "v[i] = " << (*i).m_age << std::endl;
    }
    std::cout << "v.capacity" << v.capacity() << std::endl;
    std::cout << "v.size" << v.size() << std::endl;
}

// insert
void test02() {
    std::vector<Person> v;
    v.push_back(Person("liu", 10));
    v.push_back(Person("xin", 20));
    v.push_back(Person("luo", 50));
    v.push_back(Person("ya", 90));
    Person temp = Person("NO", 100);
    v.insert(v.begin() + 2, 2, temp);
    for (std::vector<Person>::iterator i = v.begin(); i != v.end(); i++) {
        std::cout << "v[i] = " << (*i).m_name << std::endl;
        std::cout << "v[i] = " << (*i).m_age << std::endl;
    }
}

// 读取元素 at []
void test03() {
    std::vector<Person> v;
    v.push_back(Person("liu", 10));
    v.push_back(Person("xin", 20));
    v.push_back(Person("luo", 50));
    v.push_back(Person("ya", 90));
    for (int i = 0; i < v.size(); i++) {
        std::cout << "v.name = " << v[i].m_name << std::endl;
    }
    for (int i = 0; i < v.size(); i++) {
        std::cout << "v.age = " << v.at(i).m_age << std::endl;
    }
}

// swap
void test04() {
    std::vector<int> v;
    for (int i = 0; i < 100000; i++) {
        v.push_back(i);
    }
    std::cout << "v.size = " << v.size() << std::endl;
    std::cout << "v.capacity = " << v.capacity() << std::endl;

    v.resize(3);

    std::cout << "v.size = " << v.size() << std::endl;
    std::cout << "v.capacity = " << v.capacity() << std::endl;

    // 利用swap收缩内存.先构造匿名函数,进行swap后收缩内存,匿名函数语句结束后被系统自动回收
    std::vector<int>(v).swap(v);
    // std::vector<int> t(v);
    // v.swap(t);
    // std::cout << "v.size = " << v.size() << std::endl;
    // std::cout << "v.capacity = " << v.capacity() << std::endl;
}
int main(int argc, char *argv[]) {
    // test01();
    // test02();
    // test03();
    test04();

    return 0;
}
