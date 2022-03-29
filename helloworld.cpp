#include <iostream>
#define DAY 7

using namespace std;

int main(void) {
    string s;
    int arr1[] = {1, 3, 2, 5, 6, 34, 346, 34523, 76, 264, 2347, 234};
    int num = sizeof(arr1) / sizeof(int);
    int temp = 0;
    for (int i = 0; i < num - 1; i++) {
        for (int j = 0; j < num - 1 - i; j++) {
            if (arr1[j] < arr1[j + 1]) {
                temp = arr1[j + 1];
                arr1[j + 1] = arr1[j];
                arr1[j] = temp;
            }
        }
    }
    for (int i = 0; i < num; i++) {
        cout << arr1[i] << endl;
    }
    return 0;
}
