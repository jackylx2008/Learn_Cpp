#include <iostream>
#include <string>

// 类模板与继承
template <class T> class Base {
  public:
    T m;
    void show_m() {
        std::cout << "T = " << this->m << std::endl;
        std::cout << "typeid of T  " << typeid(T).name() << std::endl;
    }
};

// 子类继承父类模板声明父类模板中的数据类型
class Son1 : public Base<int> {
  public:
    Son1(int n) {
        this->m = n;
    }
};
// 子类可以用模板进行定义,在实例化的时候指定数据类型,传递给父类模板中的数据类型
template <class T2> class Son2 : public Base<T2> {
  public:
    // T1 obj;
    Son2(T2 n) {
        this->m = n;
    }
};

int main(int argc, char *argv[]) {
    Son1 s(10);
    s.show_m();

    Son2<std::string> s2("liuliu");
    s2.show_m();

    return 0;
}
