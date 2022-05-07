#include <iostream>

#include <string>

// 关系运算符重载 ==
// 函数运算符重载 () 仿函数
class Liu {
  public:
    int my_age;
    Liu(int age) {
        this->my_age = age;
    }
    bool operator==(Liu &l) {
        if (my_age == l.my_age)
            return true;
        else {
            return false;
        }
    }
    void operator()(std::string str) {
        std::cout << str << std::endl;
    }
};
// 关系运算符重载 ==
void test1() {
    Liu l1(10);
    Liu l2(10);
    if (l1 == l2) {
        std::cout << "equel" << std::endl;
    } else {
        std::cout << "unequel" << std::endl;
    }
}
// 函数运算符重载 ()
void test2() {
    Liu l(10);
    l.operator()("hello");
    l("world");
}
int main(int argc, char *argv[]) {
    system("clear");

    // test1();
    test2();

    return 0;
}
