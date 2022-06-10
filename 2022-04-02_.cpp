#include <fstream>
#include <iostream>

// 泛形编程 函数模板案例: 不同数据类型数组排序

// 排序函数
void sort(int list[], int num_list) {
    for (int i = 0; i < num_list; i++) {
        for (int j = 0; j < num_list - 1; j++) {
            if (list[j] < list[j + 1]) {
                int tmp = list[j + 1];
                list[j + 1] = list[j];
                list[j] = tmp;
            }
        }
    }
}

// 泛型编程 模板排序
template <typename L, typename N> void template_sort(L list[], N num_list) {
    for (int i = 0; i < num_list; i++) {
        for (int j = 0; j < num_list - 1; j++) {
            if (list[j] < list[j + 1]) {
                L tmp = list[j + 1];
                list[j + 1] = list[j];
                list[j] = tmp;
            }
        }
    }
}

int main(int argc, char *argv[]) {
    int l[] = {3, 6, 2, 76, 23, 34, 7};
    char c[] = {'A', 'B', '4', '3', 'd', 'q'};
    double d[] = {34.43, 34234.234, 3.434, 312.3, 546.98};
    int len_l = sizeof(l) / sizeof(l[0]);
    int len_c = sizeof(c) / sizeof(c[0]);
    int len_d = sizeof(d) / sizeof(d[0]);

    for (int i = 0; i < len_l; i++) {
        std::cout << "l[] = " << l[i] << std::endl;
    }
    std::cout << "---------" << std::endl;
    // sort(l, len_l);
    template_sort(l, len_l);
    for (int i = 0; i < len_l; i++) {
        std::cout << "l[] = " << l[i] << std::endl;
    }

    std::cout << " " << std::endl;
    std::cout << " " << std::endl;

    for (int i = 0; i < len_c; i++) {
        std::cout << "c[] = " << c[i] << std::endl;
    }
    std::cout << "---------" << std::endl;
    // sort(l, len_l);
    template_sort(c, len_c);
    for (int i = 0; i < len_c; i++) {
        std::cout << "c[] = " << c[i] << std::endl;
    }

    std::cout << " " << std::endl;
    std::cout << " " << std::endl;

    for (int i = 0; i < len_d; i++) {
        std::cout << "d[] = " << d[i] << std::endl;
    }
    std::cout << "---------" << std::endl;
    // sort(l, len_l);
    template_sort(d, len_d);
    for (int i = 0; i < len_d; i++) {
        std::cout << "d[] = " << d[i] << std::endl;
    }
    return 0;
}
