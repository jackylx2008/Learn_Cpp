#include <iostream>
#include <iterator>
#include <string>

// using namespace std;

// 运算符加法和左移重载 + <<
class Person {
  public:
    int age;
    Person &operator+(Person &p) {
        age = age + p.age;
        return *this;
    }
    Person &add(Person &p) {
        age = age + p.age;
        return *this;
    }
    Person operator*(Person &p) {
        Person temp;
        temp.age = age + p.age;
        return temp;
    }
    std::ostream &operator<<(std::ostream &cout) {
        cout << "in class " << age;
        return cout;
    }
};
std::ostream &operator<<(std::ostream &cout, Person &p) {
    cout << p.age;
    return cout;
}
int main(int argc, char *argv[]) {
    system("clear");
    Person p1, p2;
    Person p3;
    p1.age = 100;
    p2.age = 12;
    p1.add(p2);
    std::cout << "p1.age = " << p1.age << std::endl;
    std::cout << "p1 + p2 addr = " << &(p1.add(p2)) << std::endl;
    std::cout << "p1 addr = " << &p1 << std::endl;
    p3 = p1 + p2;

    std::cout << "p3.age = " << p3.age << std::endl;
    std::cout << p1 << p1 << std::endl;
    // p1 << std::cout << p1;
    // p1.operator<<(std::cout) << std::endl;

    return 0;
}
