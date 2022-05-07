#pragma once
#include <iostream>
#include <string>

class Employee {
  public:
    std::string m_name;
    int m_Id;
    int m_position;
    virtual void show_info() = 0;
    virtual std::string get_position() = 0;
    virtual ~Employee() = 0;
};
