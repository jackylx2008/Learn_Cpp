#include <iostream>
#include <string>
#define TRUE 1
#define MAX 10
using namespace std;
// 通讯录增删改查
struct Person {
    string name;
    string gender;
    int age;
    string tel;
    string addr;
};

struct Contact {
    struct Person person[MAX];
    int numbers;
};

int find_pos(struct Contact *contact, string keyword) {
    for (int i = 0; i < contact->numbers; i++) {
        if (contact->person[i].name == keyword) {
            return i;
        }
    }
    return -1;
}
void add_contact(struct Contact *contact) {
    if (contact->numbers == MAX) {
        cout << "up to limit of contact" << endl;
        return;
    }
    cout << "name: ";
    cin >> contact->person[contact->numbers].name;
    cout << "gender: ";
    cin >> contact->person[contact->numbers].gender;
    cout << "age: ";
    cin >> contact->person[contact->numbers].age;
    cout << "tel: ";
    cin >> contact->person[contact->numbers].tel;
    cout << "addr: ";
    cin >> contact->person[contact->numbers].addr;
    contact->numbers++;
    system("clear");
}
void show_contact(struct Contact *contact) {
    string c;
    if (contact->numbers == 0) {
        cout << "contact is empty" << endl;
        cin >> c;
        system("clear");
        return;
    }
    else {
        for (int i = 0; i < contact->numbers; i++) {
            cout << "name: ";
            cout << contact->person[i].name << "    ";
            cout << "gender: ";
            cout << contact->person[i].gender << "    ";
            cout << "age: ";
            cout << contact->person[i].age << "    ";
            cout << "tel: ";
            cout << contact->person[i].tel << "    ";
            cout << "addr: ";
            cout << contact->person[i].addr << "    ";
            cout << endl;
        }
        cout << "any key continue" << endl;
        cin >> c;
        system("clear");
    }
}
void del_contact(struct Contact *contact) {
    int position;
    cout << "del who?";
    string del_name;
    cin >> del_name;
    position = find_pos(contact, del_name);
    if (position < 0) {
        cout << "not match" << endl;
        return;
    }
    if (position < contact->numbers) {
        for (int j = position; j < contact->numbers; j++) {
            contact->person[j].name = contact->person[j + 1].name;
            contact->person[j].gender = contact->person[j + 1].gender;
            contact->person[j].age = contact->person[j + 1].age;
            contact->person[j].tel = contact->person[j + 1].tel;
            contact->person[j].addr = contact->person[j + 1].addr;
        }
    }
    contact->person[contact->numbers].name = "";
    contact->person[contact->numbers].gender = "";
    contact->person[contact->numbers].age = 0;
    contact->person[contact->numbers].tel = "";
    contact->person[contact->numbers].addr = "";
    contact->numbers--;
    cout << "delete finished" << endl;
}
void search_contact(struct Contact *contact) {
    int position;
    char c;
    cout << "find who?";
    string name;
    cin >> name;
    position = find_pos(contact, name);
    if (position < 0) {
        cout << "not match" << endl;
        return;
    }
    else {
        cout << "name: ";
        cout << contact->person[position].name << "    ";
        cout << "gender: ";
        cout << contact->person[position].gender << "    ";
        cout << "age: ";
        cout << contact->person[position].age << "    ";
        cout << "tel: ";
        cout << contact->person[position].tel << "    ";
        cout << "addr: ";
        cout << contact->person[position].addr << "    ";
        cout << endl;
        cout << "any key continue" << endl;
        cin >> c;
        system("clear");
    }
}
void change_contact(struct Contact *contact) {
    int position;
    char c;
    cout << "find who?";
    string name;
    cin >> name;
    position = find_pos(contact, name);
    if (position < 0) {
        cout << "not match" << endl;
        return;
    }
    else {
        cout << "name: ";
        cout << contact->person[position].name;
        cout << "  gender: ";
        cin >> contact->person[position].gender;
        cout << "age: ";
        cin >> contact->person[position].age;
        cout << "tel: ";
        cin >> contact->person[position].tel;
        cout << "addr: ";
        cin >> contact->person[position].addr;
        system("clear");
    }
}
void clear_contact(struct Contact *contact) {
    contact->numbers = 0;
    cout << "clear contact finished" << endl;
}
void show_menu() {
    cout << "******************" << endl;
    cout << "1. add contact" << endl;
    cout << "2. show contact" << endl;
    cout << "3. del contact" << endl;
    cout << "4. search contact" << endl;
    cout << "5. change contact" << endl;
    cout << "6. clear contact" << endl;
    cout << "0. exit" << endl;
    cout << "******************" << endl;
}
int main(void) {
    int choice;
    struct Contact contact1;
    contact1.numbers = 0;
    system("clear");
    while (TRUE) {
        show_menu();
        cin >> choice;
        switch (choice) {
        case 1: {
            add_contact(&contact1);
            break;
        }
        case 2: {
            show_contact(&contact1);
            break;
        }
        case 3: {
            del_contact(&contact1);
            break;
        }
        case 4: {
            search_contact(&contact1);
            break;
        }
        case 5: {
            change_contact(&contact1);
            break;
        }
        case 6: {
            clear_contact(&contact1);
            break;
        }
        case 0:
            return 0;
        default:
            cout << "出错啦！" << endl;
        }
    }

    return 0;
}
