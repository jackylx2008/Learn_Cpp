#include <iostream>
#include <map>
#include <string>
#include <utility>

// map 容器
int main(int argc, char *argv[]) {
    std::map<int, int> m;
    m.insert(std::pair<int, int>(1, 111));
    m.insert(std::pair<int, int>(6, 211));
    m.insert(std::pair<int, int>(3, 311));
    for (std::map<int, int>::iterator i = m.begin(); i != m.end(); i++) {
        std::cout << "key = " << i->first;
        std::cout << "  val = " << i->second << std::endl;
    }

    return 0;
}
