#include <fstream>
#include <iostream>
#include <string>

// 二进制文件读写

class Person {
  public:
    std::string m_name;
    int m_age;
    Person() {}
    Person(std::string name, int age) {
        m_name = name;
        m_age = age;
    }
};

int main(int argc, char *argv[]) {
    std::ofstream ofs("person.txt", std::ios::out | std::ios::binary);
    Person p("liu", 44);
    ofs.write((const char *)&p, sizeof(p));
    ofs.close();

    std::ifstream ifs;
    ifs.open("person.txt", std::ios::binary | std::ios::in);
    if (!ifs.is_open()) {
        std::cout << "file open error" << std::endl;
    }
    Person p1;
    ifs.read((char *)&p1, sizeof(Person));
    std::cout << "p1 = " << p1.m_name << std::endl;
    std::cout << "p1 = " << p1.m_age << std::endl;

    ifs.close();

    return 0;
}
