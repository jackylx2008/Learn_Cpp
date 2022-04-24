#include "Worker.h"

void Worker ::show_info() {
    std::cout << "name = " << m_name << "\tID = " << m_Id
              << "\tposition = " << get_position() << std::endl;
}

std::string Worker::get_position() {
    return "Worker";
}
Worker::Worker(std::string name, int Id, int position) {
    this->m_name = name;
    this->m_Id = Id;
    this->m_position = position;
}
Worker::~Worker() {
    std::cout << "Worker destroyed" << std::endl;
}
