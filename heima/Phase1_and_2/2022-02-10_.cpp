#include <iostream>
#include <string>
#define NLLL 0

using namespace std;
// this 指针
class Person {
  public:
    Person(int age) {
        this->age = age;
    }
    int age;
    string str;
    Person &PersonAdd(Person &p) {
        this->age += p.age;
        return *this;
    }
};

void test(Person *p) {
    p->age = 10;
    p->str = "hello";
}
void test1(Person &p) {
    p.str = "world";
    p.age = 20;
}
int main(int argc, char *argv[]) {
    system("clear");
    Person p1(10);
    Person p2(20);
    p1.PersonAdd(p2).PersonAdd(p2);
    Person p3(0);
    // test(&p3);
    test1(p3);
    std::cout << "p3 = " << p3.age << std::endl;
    return 0;
}
