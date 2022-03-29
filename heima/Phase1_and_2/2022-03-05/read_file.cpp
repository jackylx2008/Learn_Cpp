#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int main(int argc, char *argv[]) {
    std::ifstream ifs;
    ifs.open("worker.txt", std::ios::out);
    std::string name = "";
    int Id, position;
    int num_file = 0;
    char c1, c2, c3;

    // while (ifs >> name && ifs >> Id && ifs >> position) {
    //     std::cout << "name = " << name << std::endl;
    //     num_file++;
    // }
    // while (getline(ifs, name, ';')) {
    //     std::cout << name << std::endl;
    //     num_file++;
    // }
    // ifs.close();

    std::ifstream inFile("worker.txt");
    if (inFile.is_open()) {
        std::string line;
        while (std::getline(inFile, line)) {
            std::stringstream ss(line);
            std::string name, tmp;
            int id, pos;
            std::getline(ss, name, ';');
            std::cout << "name = " << name << " ";
            std::getline(ss, tmp, ';');
            id = std::stoi(tmp);
            std::cout << "id = " << id << " ";
            std::getline(ss, tmp, ';');
            pos = std::stoi(tmp);
            std::cout << "pos = " << pos << " ";

            // std::vector<std::string> enrolled;
            // std::string course;
            // while (std::getline(ss, course, ',')) {
            //     enrolled.push_back(course);
            //     std::cout << ", \"" << course << "\"";
            // }
            std::cout << "\n";
            num_file++;
        }
    }
    std::cout << "num_file = " << num_file << std::endl;
    return 0;
}
