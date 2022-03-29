#include <iostream>
#include <string>

// 动态多态需要有继承关系,子类重写父类同名函数
class Father {
  public:
    // 虚函数实习地址晚绑定,实现子类成员函数多态
    virtual void speak() {
        std::cout << "Father speaks" << std::endl;
    }
};

class Son : public Father {
  public:
    void speak() {
        std::cout << "Son speaks" << std::endl;
    }
};
class Daughter : public Father {};

void to_speak(Father &father) {
    father.speak();
}
int main(int argc, char *argv[]) {
    Son son;
    Daughter daughter;
    to_speak(son);
    to_speak(daughter);

    return 0;
}
