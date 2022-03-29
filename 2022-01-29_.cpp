#include <iostream>
#include <string>
#define TRUE 1
#define MAX 10
using namespace std;
// 计算点和圆的关系
class Point {
  private:
    int x, y;

  public:
    void set_x(int p_x) {
        x = p_x;
    }
    void set_y(int p_y) {
        y = p_y;
    }
    int get_x() {
        return x;
    }
    int get_y() {
        return y;
    }
    Point() {
        std::cout << "hello" << std::endl;
    }
};
class Circle {
  private:
    Point center;
    int r;
    double calc_distance(Point p) {
        return (p.get_x() - center.get_x()) * (p.get_x() - center.get_x()) +
               (p.get_y() - center.get_y()) * (p.get_y() - center.get_y());
    }

  public:
    void set_center(int p_x, int p_y) {
        center.set_x(p_x);
        center.set_y(p_y);
    }
    void set_r(int m_r) {
        r = m_r;
    }
    void pos_point(Point p) {
        std::cout << calc_distance(p) << std::endl;
        std::cout << r * r << std::endl;
        if (calc_distance(p) - r * r < 0.01 &&
            calc_distance(p) - r * r > -0.01) {
            std::cout << "on circle" << std::endl;
        }
        if (calc_distance(p) - r * r > 0.01) {
            std::cout << "outside circle" << std::endl;
        }
        if (r * r - calc_distance(p) > 0.01) {
            std::cout << "inside circle" << std::endl;
        }
    }
};
int main(void) {
    system("clear");
    Circle c;
    Point p;
    c.set_r(10);
    c.set_center(10, 0);
    p.set_x(10);
    p.set_y(9);
    c.pos_point(p);

    return 0;
}
