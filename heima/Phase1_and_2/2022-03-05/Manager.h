#pragma once
#include "Employee.h"

class Manager : public Employee {
  public:
    Manager(std::string name, int Id, int position);
    ~Manager();
    virtual void show_info();

  private:
    virtual std::string get_position();
};
