#include <fstream>
#include <iostream>
#include <string>

// ASCII文件读写
int main(int argc, char *argv[]) {
    // 文件打开
    std::ofstream ofs;
    ofs.open("README.md", std::ios::out);
    ofs << "# 2022-02-27" << std::endl;
    ofs << "# 2022-02-28" << std::endl;
    ofs << "# 2022-02-29" << std::endl;
    ofs << "# 2022-02-30" << std::endl;
    ofs.close();
    system("cat README.md");
    // 文件读取
    char buf[1000] = {0};

    std::ifstream ifs1;
    ifs1.open("README.md", std::ios::in);
    if (!ifs1.is_open()) {
        std::cout << "file open error" << std::endl;
        return 0;
    }
    while (ifs1 >> buf) {
        std::cout << "buf = " << buf << std::endl;
    }
    ifs1.close();

    std::ifstream ifs2;
    ifs2.open("README.md", std::ios::in);
    while (ifs2.getline(buf, sizeof(buf))) {
        std::cout << "buf = " << buf << std::endl;
    }
    ifs2.close();

    std::string buffer;
    std::ifstream ifs3;
    ifs3.open("README.md", std::ios::in);
    while (std::getline(ifs3, buffer)) {
        std::cout << "buffer = " << buffer << std::endl;
    }
    ifs3.close();

    std::ifstream ifs4;
    ifs4.open("README.md", std::ios::in);
    char c;
    while ((c = ifs4.get()) != EOF) {
        // std::cout << "char = " << c << std::endl;
        std::cout << c;
    }
    ifs4.close();

    return 0;
}
