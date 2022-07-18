#include <iostream>
#include <string>

// 仿函数 函数对象
class my_add {
  public:
    int operator()(int a, int b) {
        return a + b;
    }
};
class my_print {
  public:
    void operator()(std::string s) {
        std::cout << s << std::endl;
        index++;
    }
    int index;
    my_print() {
        index = 0;
    }
};
void do_print(my_print &mp, std::string s) {
    mp(s);
}
int main(int argc, char *argv[]) {
    int c;
    my_add myAdd;
    c = myAdd(1, 2);
    std::cout << "c = " << c << std::endl;

    my_print mp;
    mp("hello");
    mp("hello");
    mp("hello");
    mp("hello");
    mp("hello");
    std::cout << "mp.index = " << mp.index << std::endl;
    std::cout << "" << std::endl;

    do_print(mp, "world");
    std::cout << "mp.index = " << mp.index << std::endl;

    my_print *p = new my_print;
    (*p)("dff");
    (*p)("dff");
    (*p)("dff");
    std::cout << "p.index = " << p->index << std::endl;
    delete p;

    return 0;
}
