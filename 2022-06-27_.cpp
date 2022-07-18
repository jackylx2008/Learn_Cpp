#include <iostream>
#include <set>
#include <string>

// multiset
void test01() {
    std::multiset<int> mset;
    std::multiset<int>::iterator it = mset.insert(10);
    std::cout << "*it = " << *it << std::endl;

    it = mset.insert(10);
    std::cout << "*it = " << *it << std::endl;
    for (std::multiset<int>::iterator i = mset.begin(); i != mset.end(); i++) {
        std::cout << "*mset = " << *i << std::endl;
    }
}
int main(int argc, char *argv[]) {
    test01();

    return 0;
}
