#pragma once
#include "Employee.h"

class Boss : public Employee {
  public:
    Boss(std::string name, int Id, int position);
    ~Boss();
    virtual void show_info();

  private:
    virtual std::string get_position();
};
