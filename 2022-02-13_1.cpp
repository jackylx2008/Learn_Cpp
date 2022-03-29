#include <iostream>
#include <string>

// 赋值符重载 等号 =
class Liu {
  public:
    int *my_age;
    Liu(int age) {
        my_age = new int(age);
    }
    ~Liu() {
        if (my_age != NULL) {
            delete my_age;
            my_age = NULL;
        }
    }
    /* my answer
    Liu &operator=(Liu &l) {
        int *temp_age;
        int temp = *l.my_age;
        temp_age = new int();
        l.my_age = temp_age;
        *my_age = temp;
        *l.my_age = temp;
        return *this;
    } */
    Liu &operator=(Liu &l) {
        if (my_age != NULL) {
            delete my_age;
            my_age = NULL;
        }
        my_age = new int();
        *my_age = *l.my_age;
        return *this;
    }
};
void test1() {
    Liu l1(10);
    Liu l2(20);
    Liu l3(30);
    std::cout << "l1 = " << *l1.my_age << std::endl;
    std::cout << "l2 = " << *l2.my_age << std::endl;
    std::cout << "l3 = " << *l3.my_age << std::endl;
    l3 = l2 = l1;
    std::cout << "l1 = " << *l1.my_age << std::endl;
    std::cout << "l2 = " << *l2.my_age << std::endl;
    std::cout << "l3 = " << *l3.my_age << std::endl;
}
int main(int argc, char *argv[]) {
    system("clear");

    test1();

    return 0;
}
