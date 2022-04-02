#include <iostream>

// 泛型编程 模板
template <typename R, typename T1, typename T2>
void swap(T1 a, T2 b, R &r) {
    r = a * b;
    return;
}

template <typename T>
void func() {
    std::cout << "haha" << std::endl;
}

int main(int argc, char *argv[]) {
    int a = 13;
    float b = 2.1;
    double r = 0.0;
    swap(a, b, r);  // 自动推导调用,需要保证推导的一致性
    std::cout << "r = " << r << std::endl;
    func<int>(); // 显式数据类型

    return 0;
}
