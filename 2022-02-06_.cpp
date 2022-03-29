#include <iostream>
#include <string>

using namespace std;
// 构造函数
class Person {
  private:
    int age;

  public:
    Person() {}
    Person(int m_age) { age = m_age; }
    Person(const Person &p) { age = p.age; }
    void get_age(const string str) {
        std::cout << str;
        std::cout << age << std::endl;
    }
};
int main(int argc, char *argv[]) {
    system("clear");
    Person p;
    Person p1(10);
    Person p2(p1);
    p1.get_age("p1  ");
    p2.get_age("p2  ");
    std::cout << (int *)&p1 << std::endl;
    return 0;
}
