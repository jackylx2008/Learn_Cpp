#include <iostream>
#include <string>

// 动态多态
class Calc {
  public:
    int num1, num2;
    Calc() {
        num1 = 0;
        num2 = 0;
    }
    virtual int get_result() {
        return 0;
    }
    // virtual int get_result_() = 0;
};
class Add : public Calc {
  public:
    virtual int get_result() {
        return num1 + num2;
    }
};
class Minus : public Calc {
  public:
    virtual int get_result() {
        return num1 - num2;
    }
};
void do_calc(Calc &c, int n1, int n2) {
    c.num1 = n1;
    c.num2 = n2;
    int result = c.get_result();
    std::cout << "result = " << result << std::endl;
}

int main(int argc, char *argv[]) {
    // 通过引用使用多态
    Add add;
    Minus minus;
    do_calc(add, 10, 5);
    do_calc(minus, 10, 5);

    // 通过指针使用多态
    Calc *calc = NULL;
    Add aaa;
    calc = new Add;
    // calc = &aaa;
    calc->num1 = 20;
    calc->num2 = 10;
    int r = calc->get_result();
    std::cout << "add result = " << r << std::endl;
    delete calc;
    calc = new Minus;
    calc->num1 = 30;
    calc->num2 = 10;
    r = calc->get_result();
    std::cout << "minus result = " << r << std::endl;
    delete calc;
    return 0;
}
