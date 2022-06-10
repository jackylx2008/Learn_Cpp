#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

// 学习STL--1 以Vector为例介绍STL -容器存放内置数据类型
void print_vector_int(int val) {
    std::cout << "v[i] =" << val << std::endl;
}
void test01() {
    std::vector<int> v;
    v.push_back(10);
    v.push_back(13);
    v.push_back(40);
    v.push_back(50);
    v.push_back(66);
    std::vector<int>::iterator v_begin = v.begin();
    std::vector<int>::iterator v_end = v.end();
    while (v_begin != v_end) {
        std::cout << "v[i] = " << *v_begin << std::endl;
        v_begin++;
    }

    std::cout << "-------------" << std::endl;

    for (std::vector<int>::iterator i = v.begin(); i != v.end(); i++) {
        std::cout << "v[i] = " << *i << std::endl;
    }

    std::cout << "-------------" << std::endl;

    std::for_each(v.begin(), v.end(), print_vector_int);
}

// 学习STL--1 Vector容器存放自定义数据类型
class Person {
  public:
    Person(std::string name, int age) {
        this->m_name = name;
        this->m_age = age;
    }
    std::string m_name;
    int m_age;
};
void print_vector_class(Person p);
void test02() {
    std::vector<Person> v;
    v.push_back(Person("liu", 10));
    v.push_back(Person("xin", 20));
    v.push_back(Person("luo", 50));
    v.push_back(Person("ya", 90));
    std::vector<Person>::iterator v_begin = v.begin();
    std::vector<Person>::iterator v_end = v.end();

    while (v_begin != v_end) {
        std::cout << "v[i] = " << (*v_begin).m_name << std::endl;
        std::cout << "v[i] = " << v_begin->m_name << std::endl;
        std::cout << "v[i] = " << (*v_begin).m_age << std::endl;
        std::cout << "-------------" << std::endl;
        v_begin++;
    }

    std::cout << std::endl;

    for (std::vector<Person>::iterator i = v.begin(); i != v.end(); i++) {
        std::cout << "v[i] = " << (*i).m_name << std::endl;
        std::cout << "v[i] = " << (*i).m_age << std::endl;
    }

    std::cout << std::endl;

    // std::for_each(v.begin(), v.end(), print_vector_int);
}
void print_vector_class(Person p) {
    std::cout << "v[i] = " << p.m_name << std::endl;
    std::cout << "v[i] = " << p.m_age << std::endl;
}

// 学习STL--1 Vector容器存放自定义数据类型指针
void test03() {
    std::vector<Person *> v;
    Person *p1 = new Person("liu", 10);
    v.push_back(p1);
    v.push_back(new Person("xin", 20));
    v.push_back(new Person("yi", 20));
    v.push_back(new Person("zhuo", 99));
    std::vector<Person *>::iterator v_begin = v.begin();
    std::vector<Person *>::iterator v_end = v.end();

    while (v_begin != v_end) {
        std::cout << "v[i] = " << (*v_begin)->m_name << std::endl;
        std::cout << "v[i] = " << (*v_begin)->m_age << std::endl;
        std::cout << "-------------" << std::endl;
        v_begin++;
    }

    for (std::vector<Person *>::iterator i = v.begin(); i != v.end(); i++) {
        std::cout << "v[i] = " << (*i)->m_name << std::endl;
        std::cout << "v[i] = " << (*i)->m_age << std::endl;
    }
}

// 学习STL--1 Vector容器嵌套容器
void test04() {
    std::vector<std::vector<int>> v;
    std::vector<int> v1, v2, v3;

    v1.push_back(10);
    v1.push_back(11);
    v1.push_back(12);
    v1.push_back(13);

    v2.push_back(20);
    v2.push_back(22);
    v2.push_back(23);
    v2.push_back(22);

    v3.push_back(30);
    v3.push_back(32);
    v3.push_back(33);
    v3.push_back(32);

    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);

    for (std::vector<std::vector<int>>::iterator i = v.begin(); i != v.end();
         i++) {
        for (std::vector<int>::iterator j = (*i).begin(); j != (*i).end();
             j++) {
            std::cout << "j = " << (*j) << std::endl;
        }
        std::cout << "-------------" << std::endl;
    }
}

int main(int argc, char *argv[]) {
    // test01();
    // test02();
    // test03();
    test04();

    return 0;
}
