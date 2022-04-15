#include <iostream>
#include <string>
//普通函数与模板同名的调用
void test_template(int a) {
    std::cout << "func is running" << std::endl;
}
template <typename T> void test_template(T a) {
    std::cout << "template is running" << std::endl;
}

// 模板的重载
class Person {
  public:
    int m_age;
    std::string m_name;

  public:
    Person(int age, std::string name) {
        m_age = age;
        m_name = name;
    }
    bool operator==(Person &p) {
        if (this->m_age == p.m_age) {
            return true;
        }
        else
            return false;
    }
};
template <typename T> bool template_compare(T &a, T &b) {
    std::cout << "template_compare int" << std::endl;
    if (a == b) {
        return true;
    }
    else {
        return false;
    }
}
template <> bool template_compare(Person &p1, Person &p2) {
    std::cout << "template_compare Person" << std::endl;
    if (p1.m_age == p2.m_age) {
        return true;
    }
    else {
        return false;
    }
}
int main(int argc, char *argv[]) {
    test_template<>(10);
    int a = 10, b = 20;
    Person p1(20, "xin");
    Person p2(20, "liu");
    bool t1, t2, t3;
    t1 = template_compare(a, b);
    t2 = template_compare(p1, p2);
    std::cout << "t1 = " << t1 << std::endl;
    std::cout << "t2 = " << t2 << std::endl;
    t3 = (p1 == p2);
    std::cout << "t3 = " << t3 << std::endl;

    return 0;
}
