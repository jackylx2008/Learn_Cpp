#pragma once
#include "Boss.h"
#include "Employee.h"
#include "Manager.h"
#include "Worker.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class WorkerManager {
  public:
    WorkerManager();
    ~WorkerManager();
    void ShowMenu();
    void Exit();
    void AddWorker();
    void ShowInfo();
    void DelWorker();
    void ModifWorker();
    void FindWorkerByID();
    void FindWorkerByName();
    void SortWorkerByID();
    void ClearWorkerData();
    Employee **m_worker_arr;
    int m_num_worker_arr;
    bool m_is_file_empty;

  private:
    void get_worker_info(std::string &name, int &id, int &position);
    void save_file();
};
