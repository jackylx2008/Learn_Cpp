#include <iostream>
#include <string>

// 类模板的构造函数和成员函数的类外实现
template <class NameType, class AgeType> class Person {
  public:
    NameType m_name;
    AgeType m_age;
    Person(NameType name, AgeType age);
    void show_person();
};
template <class NameType, class AgeType>
Person<NameType, AgeType>::Person(NameType name, AgeType age) {
    this->m_name = name;
    this->m_age = age;
};
template <class NameType, class AgeType>
void Person<NameType, AgeType>::show_person() {
    std::cout << "name = " << this->m_name << std::endl;
    std::cout << "age = " << this->m_age << std::endl;
}

int main(int argc, char *argv[]) {
    Person<std::string, int> *p1 = new Person<std::string, int>("liu", 40);
    p1->show_person();

    return 0;
}
