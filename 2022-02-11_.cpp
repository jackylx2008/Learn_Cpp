#include <iostream>
#include <string>

using namespace std;

class Liu;
class Xin {
  public:
    Xin();
    void member_func();
    Liu *liu;
};
class Liu {
    friend void friend_func(Liu &l); // 全局函数作为友元
    friend class Luo;                // 类作为友元
    friend void Xin::member_func(); // 类成员函数作为友元，必须现声明后定义

  public:
    Liu() {
        private_str = "private";
        public_str = "public";
    }
    string public_str;

  private:
    string private_str;
};

Xin::Xin() {
    liu = new Liu;
}

void Xin::member_func() {
    std::cout << "liu private = " << liu->private_str << std::endl;
}
class Luo { // 类作为友元
  public:
    Luo() {
        l = new Liu;
    }
    void look(Liu *l) {
        std::cout << "l.str = " << l->private_str << std::endl;
        std::cout << "l.public = " << l->public_str << std::endl;
    }
    ~Luo() {
        delete l;
    }

  private:
    Liu *l;
};

void friend_func(Liu &l) {
    std::cout << l.private_str << std::endl;
}
void globl_func_as_friend(void) {
    Liu liu;
    friend_func(liu);
}
void class_as_friend() {
    Liu liu;
    Luo luo;
    luo.look(&liu);
}
void member_func_as_friend() {
    Liu liu;
    Xin xin;
    xin.member_func();
}
int main(int argc, char *argv[]) {
    system("clear");
    globl_func_as_friend();
    std::cout << "" << std::endl;
    class_as_friend();
    std::cout << "" << std::endl;
    member_func_as_friend();

    return 0;
}
