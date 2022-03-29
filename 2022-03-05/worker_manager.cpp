#include "worker_manager.h"
#include "Boss.h"
#include "Employee.h"
#include "Manager.h"
#include "Worker.h"
#include <fstream>
#include <iostream>
#include <ostream>
#include <string>

WorkerManager::WorkerManager() {
    this->m_worker_arr = NULL;
    this->m_num_worker_arr = 0;
    this->m_is_file_empty = true;
    // 文件不存在
    std::ifstream ifs;
    ifs.open("worker.txt", std::ios::in);
    if (!ifs.is_open()) {
        std::cout << "No file" << std::endl;
        ifs.close();
        return;
    }

    // 文件存在但是为空文件
    char ch;
    ifs >> ch;
    if (ifs.eof()) {
        std::cout << "file exit but it is empty" << std::endl;
        ifs.close();
        return;
    }
    ifs.seekg(0, std::ios::beg); //文件指针归零

    // 文件存在且有数据
    if (ifs.is_open()) {
        std::cout << "open file with data" << std::endl;
        std::string line;
        this->m_is_file_empty = false;
        this->m_num_worker_arr = 0;

        // 获取总人数,并开辟堆区空间
        while (std::getline(ifs, line)) {
            this->m_num_worker_arr++;
        }
        this->m_worker_arr = new Employee *[this->m_num_worker_arr];
        ifs.close();
        // WARN: 需要重新开一遍文件,否则读不到数据

        // 读取文件数据到内存
        std::ifstream ifs;
        ifs.open("worker.txt", std::ios::in);
        int index = 0;
        while (std::getline(ifs, line)) {
            std::stringstream ss(line);
            std::string name, tmp;
            int id, position;
            std::getline(ss, name, ';');
            std::getline(ss, tmp, ';');
            id = std::stoi(tmp);
            std::getline(ss, tmp, ';');
            position = std::stoi(tmp);
            // std::cout << "name = " << name << " ";
            // std::cout << "id = " << id << " ";
            // std::cout << "position = " << position << " ";
            // std::cout << "\n";
            switch (position) {
            case 1: {
                *(this->m_worker_arr + index) = new Worker(name, id, position);
                break;
            }
            case 2: {
                *(this->m_worker_arr + index) = new Manager(name, id, position);
                break;
            }
            case 3: {
                *(this->m_worker_arr + index) = new Boss(name, id, position);
                break;
            }
            }
            index++;
        }
        ifs.close();
        return;
    }
}

WorkerManager::~WorkerManager() {
    if (this->m_worker_arr != NULL) {
        for (int i = 0; i < this->m_num_worker_arr; i++) {
            if (this->m_worker_arr[i] != NULL) {
                delete this->m_worker_arr[i];
            }
        }
        delete[] this->m_worker_arr;
        this->m_worker_arr = NULL;
    }
    std::cout << "西沟完成" << std::endl;
}

void WorkerManager::ShowMenu() {
    std::cout << std::endl;
    std::cout << "Worker Manager System" << std::endl;
    std::cout << "0. Exit" << std::endl;
    std::cout << "1. Add Worker" << std::endl;
    std::cout << "2. Show Worker" << std::endl;
    std::cout << "3. Del Worker" << std::endl;
    std::cout << "4. Modify Worker" << std::endl;
    std::cout << "5. Search Worker" << std::endl;
    std::cout << "6. Sort Worker" << std::endl;
    std::cout << "7. Delete All Worker" << std::endl;
    std::cout << std::endl;
}

void WorkerManager::AddWorker() {
    int add_worker_num = 0;
    std::string name;
    int id = 0;
    int position = -1;
    std::cout << "How many people do you want to add" << std::endl;
    std::cin >> add_worker_num;
    while (add_worker_num <= 0) {
        std::cout << "must bigger than 0" << std::endl;
        std::cin >> add_worker_num;
    }
    std::cout << "m_worker_arr = " << this->m_worker_arr << std::endl;
    if (this->m_worker_arr == NULL) {
        this->m_worker_arr = new Employee *[add_worker_num];
        Employee *tmp = NULL;
        for (int i = 0; i < add_worker_num; i++) {
            WorkerManager::get_worker_info(name, id, position);
            switch (position) {
            case 1: {
                // *(this->m_worker_arr + i) = new Worker(name, id, position);
                this->m_worker_arr[i] = new Worker(name, id, position);
                // tmp = new Worker(name, id, position);
                break;
            }
            case 2: {
                // *(this->m_worker_arr + i) = new Manager(name, id, position);
                this->m_worker_arr[i] = new Manager(name, id, position);
                break;
            }
            case 3: {
                // *(this->m_worker_arr + i) = new Boss(name, id, position);
                this->m_worker_arr[i] = new Boss(name, id, position);
                break;
            }
            }
        }
    }
    else {
        // 我的解法是建立了一个临时的指针从新存储原始的数据和新增加的数据
        Employee **tmp = NULL;
        tmp = new Employee *[this->m_num_worker_arr + add_worker_num];
        for (int i = 0; i < this->m_num_worker_arr; i++) {
            *(tmp + i) = *(this->m_worker_arr + i);
            // tmp[i] = this->m_worker_arr[i]; 与上面语句等价
        }
        for (int i = this->m_num_worker_arr;
             i < this->m_num_worker_arr + add_worker_num; i++) {
            WorkerManager::get_worker_info(name, id, position);
            switch (position) {
            case 1: {
                *(tmp + i) = new Worker(name, id, position);
                break;
            }
            case 2: {
                *(tmp + i) = new Manager(name, id, position);
                break;
            }
            case 3: {
                *(tmp + i) = new Boss(name, id, position);
                break;
            }
            }
        }
        // 释放原有空间
        delete[] this->m_worker_arr;
        // 更改新空间指向
        this->m_worker_arr = tmp;
        tmp = NULL;
    }
    // 更新总数
    this->m_num_worker_arr += add_worker_num;
    this->save_file();
}

void WorkerManager::ShowInfo() {
    if (this->m_worker_arr != NULL) {
        for (int i = 0; i < m_num_worker_arr; i++) {
            this->m_worker_arr[i]->show_info();
            // (*(*(m_worker_arr + i))).show_info();
        }
    }
    else {
        std::cout << "file is empty or not exist" << std::endl;
    }
}

void WorkerManager::DelWorker() {
    std::cout << "Which worker to del" << std::endl;
    int del_worker_id = 0;
    int del_index = -1;
    std::cin >> del_worker_id;
    if (this->m_worker_arr != NULL) {
        for (int i = 0; i < this->m_num_worker_arr; i++) {
            if (this->m_worker_arr[i]->m_Id == del_worker_id) {
                // std::cout << "name = " << this->m_worker_arr[i]->m_name << "
                // "; std::cout << "id = " << this->m_worker_arr[i]->m_Id << "
                // "; std::cout << "position = " <<
                // this->m_worker_arr[i]->m_position
                //           << " ";
                // std::cout << "\n";
                del_index = i;
                std::cout << "del del_index = " << del_index << std::endl;
                break;
            }
        }
        if (del_index < 0) {
            std::cout << "Wrong index number" << std::endl;
            return;
        }
        // 我的解法是建立了一个临时的指针从新存储原始的数据和新增加的数据
        Employee **tmp = NULL;
        tmp = new Employee *[this->m_num_worker_arr - 1];
        for (int i = 0; i < del_index; i++) {
            *(tmp + i) = *(this->m_worker_arr + i);
            // tmp[i] = this->m_worker_arr[i]; 与上面语句等价
        }
        for (int i = del_index + 1; i < m_num_worker_arr; i++) {
            *(tmp + i - 1) = *(this->m_worker_arr + i);
            // tmp[i] = this->m_worker_arr[i]; 与上面语句等价
        }
        // 释放原有空间
        delete[] this->m_worker_arr;
        // 更改新空间指向
        this->m_worker_arr = tmp;
        tmp = NULL;
        delete[] tmp;
        // 更新总数
        this->m_num_worker_arr--;
        this->save_file();
    }
    else {
        std::cout << "Nothing to del" << std::endl;
    }
}

void WorkerManager::ModifWorker() {
    std::cout << "Which worker to Modified" << std::endl;
    int modify_worker_id = 0;
    int modify_index = -1;
    std::cin >> modify_worker_id;
    if (this->m_worker_arr != NULL) {
        for (int i = 0; i < this->m_num_worker_arr; i++) {
            if (this->m_worker_arr[i]->m_Id == modify_worker_id) {
                // std::cout << "name = " << this->m_worker_arr[i]->m_name << "
                // "; std::cout << "id = " << this->m_worker_arr[i]->m_Id << "
                // "; std::cout << "position = " <<
                // this->m_worker_arr[i]->m_position
                //           << " ";
                // std::cout << "\n";
                modify_index = i;
                std::cout << "modify_index = " << modify_index << std::endl;
                break;
            }
        }
        if (modify_index < 0) {
            std::cout << "Wrong id number" << std::endl;
            return;
        }
        std::string name;
        int position = 0;
        int id = 0;
        std::cout << "What name it is " << std::endl;
        std::cin >> name;
        std::cout << "What position it is" << std::endl;
        std::cin >> position;
        std::cout << "ID ?" << std::endl;
        std::cin >> id;
        delete this->m_worker_arr[modify_index];
        switch (position) {
        case 1: {
            // *(this->m_worker_arr + i) = new Worker(name, id, position);
            this->m_worker_arr[modify_index] = new Worker(name, id, position);
            break;
        }
        case 2: {
            // *(this->m_worker_arr + i) = new Manager(name, id, position);
            this->m_worker_arr[modify_index] = new Manager(name, id, position);
            break;
        }
        case 3: {
            // *(this->m_worker_arr + i) = new Boss(name, id, position);
            this->m_worker_arr[modify_index] = new Boss(name, id, position);
            break;
        }
        }
        this->save_file();
    }
    else {
        std::cout << "Nothing to Modified" << std::endl;
    }
}

void WorkerManager::FindWorkerByID() {
    std::cout << "Finding worker ID" << std::endl;
    int find_worker_id = 0;
    int find_index = -1;
    std::cin >> find_worker_id;
    if (this->m_worker_arr != NULL) {
        for (int i = 0; i < this->m_num_worker_arr; i++) {
            if (this->m_worker_arr[i]->m_Id == find_worker_id) {
                // std::cout << "name = " << this->m_worker_arr[i]->m_name << "
                // "; std::cout << "id = " << this->m_worker_arr[i]->m_Id << "
                // "; std::cout << "position = " <<
                // this->m_worker_arr[i]->m_position
                //           << " ";
                // std::cout << "\n";
                find_index = i;
                std::cout << "find_index = " << find_index << std::endl;
                break;
            }
        }
        if (find_index < 0) {
            std::cout << "Wrong id number" << std::endl;
            return;
        }
        this->m_worker_arr[find_index]->show_info();
    }
    else {
        std::cout << "Nothing to find" << std::endl;
    }
}

void WorkerManager::FindWorkerByName() {
    std::cout << "Finding worker name" << std::endl;
    std::string name = "";
    int find_index = -1;
    std::cin >> name;
    if (this->m_worker_arr != NULL) {
        for (int i = 0; i < this->m_num_worker_arr; i++) {
            if (this->m_worker_arr[i]->m_name == name) {
                // std::cout << "name = " << this->m_worker_arr[i]->m_name << "
                // "; std::cout << "id = " << this->m_worker_arr[i]->m_Id << "
                // "; std::cout << "position = " <<
                // this->m_worker_arr[i]->m_position
                //           << " ";
                // std::cout << "\n";
                find_index = i;
                std::cout << "find_index = " << find_index << std::endl;
                break;
            }
        }
        if (find_index < 0) {
            std::cout << "No worker's name is " << name << std::endl;
            return;
        }
        this->m_worker_arr[find_index]->show_info();
    }
    else {
        std::cout << "Nothing to find" << std::endl;
    }
}

void WorkerManager::SortWorkerByID() {
    if (this->m_worker_arr != NULL) {
        Employee *tmp;
        for (int i = 0; i < this->m_num_worker_arr; i++) {
            for (int j = 0; j < this->m_num_worker_arr - 1; j++) {
                if (this->m_worker_arr[j]->m_Id <
                    this->m_worker_arr[j + 1]->m_Id) {
                    tmp = this->m_worker_arr[j + 1];
                    this->m_worker_arr[j + 1] = this->m_worker_arr[j];
                    this->m_worker_arr[j] = tmp;
                    break;
                }
            }
        }
        tmp = NULL;
        this->save_file();
    }
    else {
        std::cout << "Nothing to sort" << std::endl;
    }
}

void WorkerManager::ClearWorkerData() {
    if (this->m_worker_arr != NULL) {
        for (int i = 0; i < this->m_num_worker_arr; i++) {
            if (this->m_worker_arr[i] != NULL) {
                delete this->m_worker_arr[i];
                this->m_worker_arr[i] = NULL;
            }
        }
        delete[] this->m_worker_arr;
        this->m_num_worker_arr = 0;
        this->m_worker_arr = NULL;
        this->save_file();
        std::cout << "Clear all worker" << std::endl;
    }
    else {
        std::cout << "Nothing to clear" << std::endl;
        return;
    }
}
void WorkerManager::Exit() {
    system("clear");
    // 为了调用析构函数
    delete this;
    std::cout << "Byebye" << std::endl;
    exit(0);
}

void WorkerManager::save_file() {
    std::ofstream ofs;
    ofs.open("worker.txt", std::ios::out);
    for (int i = 0; i < this->m_num_worker_arr; i++) {
        ofs << this->m_worker_arr[i]->m_name << ";"
            << this->m_worker_arr[i]->m_Id << ";"
            << this->m_worker_arr[i]->m_position << std::endl;
    }
    this->m_is_file_empty = false;
    ofs.close();
}

void WorkerManager::get_worker_info(std::string &name, int &id, int &position) {
    std::cout << "name" << std::endl;
    std::cin >> name;
    std::cout << "ID" << std::endl;
    std::cin >> id;
    std::cout << "position: 1 for Worker, 2 for Manager, 3 for Boss"
              << std::endl;
    std::cin >> position;
}
