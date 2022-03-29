#include "Manager.h"

void Manager ::show_info() {
    std::cout << "name = " << m_name << "\tID = " << m_Id
              << "\tposition = " << get_position() << std::endl;
}

std::string Manager::get_position() {
    return "Manager";
}
Manager::Manager(std::string name, int Id, int position) {
    this->m_name = name;
    this->m_Id = Id;
    this->m_position = position;
}
Manager::~Manager() {
    std::cout << "Manager destroyed" << std::endl;
}
