#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <iostream>
#include <map>
#include <string>
#include <unistd.h>
#include <utility>
#include <vector>

class Worker {
  public:
    std::string m_name;
    int m_salary;
    Worker(std::string name, int salary) {
        m_name = name;
        m_salary = salary;
    }
};
void creat_worker(std::vector<Worker> &v_worker) {
    srand((unsigned int)time(NULL));
    std::string letters = "ABCDEFGHIJKL";
    std::string name = "worker_";
    for (int i = 0; i < 10; i++) {
        Worker *worker = new Worker(name + letters[i], rand() % 20000);
        v_worker.push_back(*worker);
    }
}
void test_display_vector(const std::vector<Worker> v_worker) {
    for (std::vector<Worker>::const_iterator i = v_worker.begin();
         i != v_worker.end(); i++) {
        std::cout << "name = " << i->m_name;
        std::cout << "  salary = " << i->m_salary << std::endl;
    }
}
void set_group(std::vector<Worker> &v_worker,
               std::multimap<int, Worker> &map_worker) {
    srand((unsigned int)time(NULL));
    for (std::vector<Worker>::const_iterator i = v_worker.begin();
         i != v_worker.end(); i++) {
        map_worker.insert(std::pair<int, Worker>(rand() % 3, *i));
    }
}
void test_display_multimap(const std::multimap<int, Worker> map_worker) {
    for (std::multimap<int, Worker>::const_iterator i = map_worker.begin();
         i != map_worker.end(); i++) {
        std::cout << "Worker = " << i->second.m_name
                  << " Salary = " << i->second.m_salary;
        std::cout << " Group = " << i->first << std::endl;
    }
}
void show_worker_by_group(const std::multimap<int, Worker> map_worker) {
    std::multimap<int, Worker>::const_iterator pos = map_worker.find(0);
    int cout = map_worker.count(0);
    int index = 0;
    for (; pos != map_worker.end() && index < cout; pos++, index++) {
        std::cout << "Worker = " << pos->second.m_name
                  << " Salary = " << pos->second.m_salary;
        std::cout << " Group = " << pos->first << std::endl;
    }
}
int main(int argc, char *argv[]) {
    std::vector<Worker> vw;
    std::multimap<int, Worker> m_worker;
    creat_worker(vw);
    // test_display_vector(vw);
    set_group(vw, m_worker);
    // test_display_multimap(m_worker);
    show_worker_by_group(m_worker);

    return 0;
}
