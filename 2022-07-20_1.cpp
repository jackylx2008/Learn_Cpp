#include <algorithm>
#include <iostream>
#include <list>
#include <vector>

// 常用算法 find_if 容器内为指针的用法
// 构造函数初始化列表方式
// for循环的auto用法
class Person {
  public:
    Person(std::string name) {
        this->m_name = name;
    }
    ~Person(void) {}

  public:
    std::string m_name; // 姓名
};

//函数对象
// typedef struct fun {
//     fun(std::string name) : m_name(name){};
//     bool operator()(Person *rhs) const {
//         return (m_name == rhs->m_name);
//     }
//
//   private:
//     std::string m_name;
// } fun;

class fun {
  public:
    fun(std::string name) {
        this->m_name = name;
    };
    bool operator()(const Person *rhs) {
        return (m_name == rhs->m_name);
    }

  private:
    std::string m_name;
};

void test02() {
    std::list<Person *> lst{new Person("Mike"), new Person("John"),
                            new Person("Bobby")};

    std::list<Person *>::iterator it = find_if(
        lst.begin(), lst.end(),
        fun("John")); // 查找std::list中是否有元素能够使得fun(*it)返回true

    if (it != lst.end()) // 找到了
    {
        std::cout << "test02 find it" << std::endl;
    }
    else // 没找到
    {
        std::cout << "test02 not find" << std::endl;
    }

    //释放内存
    for (auto &i : lst) {
        delete i;
        i = nullptr;
    }
}
void test01() {
    std::vector<Person *> v;
    v.push_back(new Person("liu"));
    v.push_back(new Person("xin"));
    v.push_back(new Person("luo"));
    v.push_back(new Person("ya"));
    std::vector<Person *>::iterator v_pos =
        std::find_if(v.begin(), v.end(), fun("liu"));
    if (v_pos == v.end())
        std::cout << "test01 find " << std::endl;
    else
        std::cout << "test01 find" << std::endl;
    for (auto &i : v) {
        delete i;
        i = nullptr;
    }
}
int main() {
    test01();
    // test02();
    return 0;
}
