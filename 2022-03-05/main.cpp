#include "Employee.h"
#include "Manager.h"
#include "Worker.h"
#include "worker_manager.h"
#include <iostream>

int main(int argc, char *argv[]) {
    WorkerManager *wm = new WorkerManager;
    char choice;
    while (true) {
        wm->ShowMenu();
        std::cout << "Input a number" << std::endl;
        std::cin >> choice;
        switch (choice) {
        case '0':
            wm->Exit();
        case '1':
            wm->AddWorker();
            break;
        case '2':
            wm->ShowInfo();
            break;
        case '3':
            wm->DelWorker();
            break;
        case '4':
            wm->ModifWorker();
            break;
        case '5':
            wm->FindWorkerByName();
            break;
        case '6':
            wm->SortWorkerByID();
            break;
        case '7':
            wm->ClearWorkerData();
            break;
        default:
            system("clear");
            break;
        }
    }
    // delete wm;
    return 0;
}
