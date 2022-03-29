#include <iostream>
#include <string>

// 多态 虚函数 纯虚函数 纯虚析构函数

class Cpu {
  public:
    virtual void cpu_work() = 0;
    virtual ~Cpu() = 0;
};
Cpu::~Cpu() {}

class VideoCard {
  public:
    virtual void video_card_work() = 0;
    virtual ~VideoCard() = 0;
};
VideoCard::~VideoCard() {}

class Memory {
  public:
    virtual void memory_work() = 0;
    virtual ~Memory() = 0;
};
Memory::~Memory() {}

class Intel : public Cpu {
  public:
    virtual void cpu_work() {
        std::cout << "Intel cpu works" << std::endl;
    }
};
class AMD : public Cpu {
  public:
    virtual void cpu_work() {
        std::cout << "AMD cpu works" << std::endl;
    }
};
class Nvidia : public VideoCard {
  public:
    virtual void video_card_work() {
        std::cout << "Nvidia works" << std::endl;
    }
};
class ATI : public VideoCard {
  public:
    virtual void video_card_work() {
        std::cout << "ATI works" << std::endl;
    }
};
class Summang : public Memory {
  public:
    virtual void memory_work() {
        std::cout << "Summang works" << std::endl;
    }
};
class Sandisk : public Memory {
  public:
    virtual void memory_work() {
        std::cout << "Sandisk works" << std::endl;
    }
};
class Computer {
  public:
    std::string brand_cpu, brand_video_card, brand_memory;
    Cpu *cpu = NULL;
    VideoCard *video_card = NULL;
    Memory *memory = NULL;

    Computer(Cpu &brand_cpu, VideoCard &brand_video_card,
             Memory &brand_memory) {
        cpu = &brand_cpu;
        video_card = &brand_video_card;
        memory = &brand_memory;
    }
    // 推荐用下面的方法
    Computer(Cpu *brand_cpu, VideoCard *brand_video_card, Memory *brand_memory,
             int tmp) {
        cpu = brand_cpu;
        video_card = brand_video_card;
        memory = brand_memory;
    }

    ~Computer() {
        if (cpu != NULL) {
            delete cpu;
            cpu = NULL;
            std::cout << "delete cpu" << std::endl;
        }
        if (video_card != NULL) {
            delete video_card;
            video_card = NULL;
            std::cout << "delete video_card" << std::endl;
        }
        if (memory != NULL) {
            delete memory;
            memory = NULL;
            std::cout << "delete memory" << std::endl;
        }
    }
    void computer_work() {
        cpu->cpu_work();
        video_card->video_card_work();
        memory->memory_work();
    }
};

int main(int argc, char *argv[]) {
    Cpu *intel = new Intel;
    Cpu *amd = new AMD;
    VideoCard *nvidia = new Nvidia;
    VideoCard *ati = new ATI;
    Memory *sandisk = new Sandisk;
    Memory *summang = new Summang;
    Computer c1(*intel, *nvidia, *sandisk);
    c1.computer_work();
    Computer c2(amd, ati, summang, 10);
    c2.computer_work();

    Cpu *intel1 = new Intel;
    Cpu *amd1 = new AMD;
    VideoCard *nvidia1 = new Nvidia;
    VideoCard *ati1 = new ATI;
    Memory *sandisk1 = new Sandisk;
    Memory *summang1 = new Summang;
    Computer *c3 = new Computer(*amd1, *ati1, *sandisk1);
    c3->computer_work();
    delete c3;

    Computer *c4 = new Computer(new Intel, new Nvidia, new Summang, 10);
    c4->computer_work();
    delete c4;

    return 0;
}
