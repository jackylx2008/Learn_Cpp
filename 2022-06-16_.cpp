#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <iostream>
#include <string>
#include <unistd.h>
#include <vector>

/* string vector deque 练习题 :
1. 10个人 存到vector里面 2. 打分存到deque里面,
2. 去掉最高分和最低分,计算平均分
3. 答应每个人的名字和平均分
*/
class Person {
  public:
    double m_average_score;
    std::string m_name;
    Person(std::string name, double average_score) {
        m_name = name;
        m_average_score = average_score;
    }
    Person() {
        m_name = "User ";
        m_average_score = 0.0;
    }
};
void set_person(std::vector<Person> &v) {
    for (int i = 0; i < 10; i++) {
        Person p;
        p.m_name += 'A' + i;
        v.push_back(p);
    }
}
// 下面两个函数都可以,差别其实是随机数种子是否包含在函数内
double set_average() {
    std::cout << "return average_score" << std::endl;
    // srand((unsigned int)time(NULL));
    double average_score = 0.0;
    std::deque<double> d;
    for (int i = 0; i < 10; i++) {
        double tmp = rand() % 1000 / 10.0;
        d.push_back(tmp);
        // std::cout << "tmp = " << tmp << std::endl;
    }
    std::sort(d.begin(), d.end());
    d.pop_back();
    d.pop_front();
    double sum = 0.0;
    for (std::deque<double>::const_iterator i = d.begin(); i != d.end(); i++) {
        // std::cout << "d = " << *i;
        sum += *i;
    }
    average_score = sum / d.size();
    // std::cout << "avg = " << average_score << std::endl;
    // sleep(1); 不睡1s随机数一样

    return average_score;
}
void set_average_score(std::vector<Person> &v) {
    std::cout << " avg =  vector" << std::endl;
    srand((unsigned int)time(NULL));
    for (std::vector<Person>::iterator i = v.begin(); i != v.end(); i++) {
        double average_score = 0.0;
        std::deque<double> d;
        for (int j = 0; j < 10; j++) {
            double tmp = rand() % 1000 / 10.0;
            d.push_back(tmp);
            // std::cout << "tmp = " << tmp << std::endl;
        }
        std::sort(d.begin(), d.end());
        d.pop_back();
        d.pop_front();
        double sum = 0.0;
        for (std::deque<double>::const_iterator i = d.begin(); i != d.end();
             i++) {
            // std::cout << "d = " << *i;
            sum += *i;
        }
        average_score = sum / d.size();
        // std::cout << "avg = " << average_score << std::endl;
        i->m_average_score = average_score;
    }
}
void print_vector(std::vector<Person> &v) {
    for (std::vector<Person>::const_iterator i = v.begin(); i != v.end(); i++) {
        std::cout << "name = " << i->m_name << " avg = " << i->m_average_score
                  << std::endl;
    }
}
int main(int argc, char *argv[]) {
    std::vector<Person> v;

    set_person(v);

    // 随机数种子如果设置在循环体内,因为srand()函数是时间,会生成相同的随机数
    // srand((unsigned int)time(NULL));
    // for (std::vector<Person>::iterator i = v.begin(); i != v.end(); i++) {
    //     (*i).m_average_score = set_average();
    // }
    set_average_score(v);

    print_vector(v);

    return 0;
}
