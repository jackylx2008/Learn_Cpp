#include <iostream>
#include <string>

// 类模板 类模板和函数模板的区别
template <typename AgeType = int, typename NameType = std::string>
class Person {
  public:
    AgeType m_age;
    NameType m_name;
    Person(AgeType age, NameType name) {
        m_age = age;
        m_name = name;
    }
    void show_info() {
        std::cout << "name =" << this->m_name << std::endl;
        std::cout << "age =" << this->m_age << std::endl;
    }
};
int main(int argc, char *argv[]) {
    // 类模板可以设置默认数据类型,如果没有默认数据类型那么必须在声明的时候显式定义数据类型,类模板无法自动推导数据类型
    Person<> p1(10, "liu");
    char t[10] = "liuliu";
    Person<double, char *> p2(10.1, t);
    p1.show_info();
    p2.show_info();
    return 0;
}
