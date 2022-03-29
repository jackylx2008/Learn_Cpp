#include <iostream>
#include <string>

// 继承
class Grandad {
  public:
    void name() {
        std::cout << "I am Grandad. " << std::endl;
    }
    int age = 90;
    static int weight;
};
int Grandad::weight = 500;

class Father : virtual public Grandad {
  public:
    void name() {
        std::cout << "I am father. " << std::endl;
    }
    void name(int a) {
        std::cout << "I am father. And a = " << a << std::endl;
    }
    Father() {
        std::cout << "Father()" << std::endl;
    }
    ~Father() {
        std::cout << "~Father()" << std::endl;
    }
    int age = 70;
    static int weight;
};
int Father::weight = 300;

class Son : public Father {
  public:
    void name() {
        std::cout << "I am son. " << std::endl;
    }
    void name(int a) {
        std::cout << "I am son. And a = " << a << std::endl;
    }
    // 子类中的构造和析够顺序
    Son() {
        std::cout << "Son()" << std::endl;
    }
    ~Son() {
        std::cout << "~Son()" << std::endl;
    }
    int age = 40;
    static int weight;
};
int Son::weight = 150;

int main(int argc, char *argv[]) {
    // Father father;
    Son son;

    // 子类和父类中同名成员属性如何访问
    std::cout << "son.age = " << son.age << std::endl;
    std::cout << "son.Father::age = " << son.Father::age << std::endl;
    std::cout << "son.Grandad::age = " << son.Grandad::age << std::endl;

    // 子类和父类中同名函数属性如何访问
    son.name();
    son.Son::name(100);
    son.Father::name();
    son.Grandad::name();

    // 类名访问静态成员
    std::cout << "Son 访问 Father weight = " << Son::Father::weight
              << std::endl;
    std::cout << "Son 访问 Grandad weight = " << Son::Grandad::weight
              << std::endl;
    return 0;
}
