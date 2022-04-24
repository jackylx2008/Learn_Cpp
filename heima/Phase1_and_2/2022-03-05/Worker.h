#pragma once
#include "Employee.h"

class Worker : public Employee {
  public:
    Worker(std::string name, int Id, int position);
    ~Worker();
    virtual void show_info();

  private:
    virtual std::string get_position();
};
