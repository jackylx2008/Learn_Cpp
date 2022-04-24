#include <iostream>
#include <string>

// 类模板对象做函数参数
template <class NameType, class AgeType> class Person {
  public:
    NameType m_name;
    AgeType m_age;
    Person(NameType name, AgeType age) {
        this->m_name = name;
        this->m_age = age;
    }
    void show_person() {
        std::cout << "name = " << this->m_name << std::endl;
        std::cout << "age = " << this->m_age << std::endl;
    }
};

void func_call_class(Person<std::string, int> *p) {
    // 类模板的对象作为函数参数,直接传值,引用 指针 复制参数都都可以
    p->show_person();
}

template <typename NameType, typename AgeType>
void func_call_class2(Person<NameType, AgeType> p) {
    // 参数模板化
    p.show_person();
    std::cout << "typeid of NameType  " << typeid(NameType).name() << std::endl;
    std::cout << "typeid of AgeType  " << typeid(AgeType).name() << std::endl;
}

template <class PersonType> void func_call_class3(PersonType &p) {
    // 整个类模板化
    p.show_person();
    std::cout << "typeid of PersonType  " << typeid(PersonType).name()
              << std::endl;
}

int main(int argc, char *argv[]) {
    Person<std::string, int> *p1 = new Person<std::string, int>("liu", 40);
    func_call_class(p1);
    delete p1;

    Person<std::string, int> p2("xin", 20);
    func_call_class2(p2);

    Person<std::string, int> p3("luoluo", 30);
    func_call_class3(p3);

    return 0;
}
