#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

// 学习STL--3 vector 容器
class Person {
  public:
    // Person() {
    //     this->m_name = "None";
    //     this->m_age = 0;
    // }
    Person(std::string name, int age) {
        this->m_name = name;
        this->m_age = age;
    }
    std::string m_name;
    int m_age;
};
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

    for (std::vector<Person>::iterator i = v.begin(); i != v.end(); i++) {
        std::cout << "v[i] = " << (*i).m_name << std::endl;
        std::cout << "v[i] = " << (*i).m_age << std::endl;
    }
    std::cout << "v.capacity" << v.capacity() << std::endl;
    std::cout << "v.size" << v.size() << std::endl;
}
int main(int argc, char *argv[]) {
    test01();

    return 0;
}
