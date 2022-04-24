#include "Boss.h"

void Boss ::show_info() {
    std::cout << "name = " << m_name << "\tID = " << m_Id
              << "\tposition = " << this->get_position() << std::endl;
}

std::string Boss::get_position() {
    return "Boss";
}
Boss::Boss(std::string name, int Id, int position) {
    this->m_name = name;
    this->m_Id = Id;
    this->m_position = position;
}
Boss::~Boss() {
    std::cout << "Boss destroyed" << std::endl;
}
