#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Hero {
    string name;
    int age;
    string gender;
};
int main(void) {
    struct Hero people[5];
    string name[5] = {"刘备", "关羽", "张飞", "赵云", "黄忠"};
    int age[5] = {23, 45, 21, 67, 32};
    string gender[5] = {"F", "M", "F", "M", "F"};
    for (int i = 0; i < 5; i++) {
        people[i].name = name[i];
        people[i].age = age[i];
        people[i].gender = gender[i];
    }
    for (int i = 0; i < 5; i++) {
        cout << people[i].name << people[i].age << people[i].gender << endl;
    }
    cout << endl;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            if (people[j].age < people[j + 1].age) {
                Hero temp = people[j];
                people[j] = people[j + 1];
                people[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < 5; i++) {
        cout << people[i].name << people[i].age << people[i].gender << endl;
    }

    return 0;
}
