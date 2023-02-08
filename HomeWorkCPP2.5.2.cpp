#include <iostream>
#include <locale.h>


class Triangle{
public:
    void get_name() {
        std::cout << _name << std::endl;
    }
    void get_side() {
        std::cout << "Стороны: a=" << _side_a << " b=" << _side_b << " c=" << _side_c;
    }
    void get_angle() {
        std::cout << "Углы: A=" << _angle_a << " B=" << _angle_b << " C=" << _angle_c;
    }
    void print_info() {
        get_name();
        get_side();
        std::cout << std::endl;
        get_angle();
        std::cout << "\n" << std::endl;
    }
    Triangle() :Triangle("Треугольник:", 10, 20, 30, 50, 60, 70) {}
protected:
    Triangle(std::string name_, int side_a_, int side_b_, int side_c_, int angle_a_, int angle_b_, int angle_c_) {
        _side_a = side_a_;
        _side_b = side_b_;
        _side_c = side_c_;
        _angle_a = angle_a_;
        _angle_b = angle_b_;
        _angle_c = angle_c_;
        _name = name_;
    }
private:
    int _side_a = 0;
    int _side_b = 0;
    int _side_c = 0;
    int _angle_a = 0;
    int _angle_b = 0;
    int _angle_c = 0;
    std::string _name;
};

class TriangleRight :public Triangle {
public:
    void print_info() {
        get_name();
        get_side();
        std::cout << std::endl;
        get_angle();
        std::cout << "\n" << std::endl;
    }
    TriangleRight() :TriangleRight("Прямоугольный треугольник:", 10, 20, 30, 30, 60){}
private:
    TriangleRight(std::string name_, int side_a_, int side_b_, int side_c_, int angle_a_, int angle_b_) :Triangle(name_, side_a_, side_b_, side_c_, angle_a_, angle_b_, 90) {
    }
};

class TriangleIsos :public Triangle {
public:
    void print_info() {
        get_name();
        get_side();
        std::cout <<  std::endl;
        get_angle();
        std::cout << "\n" << std::endl;
    }
    TriangleIsos() :TriangleIsos("Равнобедренный треугольник:", 10, 20, 50, 60) {}
private:
    TriangleIsos(std::string name_, int side_a_c_, int side_b_, int angle_a_c_, int angle_b_) :Triangle(name_, side_a_c_, side_b_, side_a_c_, angle_a_c_, angle_b_, angle_a_c_) {
    }
};

class TriangleEquil :public Triangle {
public:
    void print_info() {
        get_name();
        get_side();
        std::cout <<  std::endl;
        get_angle();
        std::cout << "\n" << std::endl;
    }
    TriangleEquil() :TriangleEquil("Равносторонний треугольник:", 30) {}
private:
    TriangleEquil(std::string name_, int side_a_b_c_) :Triangle(name_, side_a_b_c_, side_a_b_c_, side_a_b_c_, 60, 60, 60) {
    }
};

class Quadrilateral :Triangle {
public:
    void get_side_d() {
        get_name();
        get_side();
        std::cout << " d=" << _side_d << std::endl;
    }
    void get_angle_d() {
        get_angle();
        std::cout << " D=" << _angle_d << "\n" << std::endl;
    }
    void print_info() {
        get_side_d();
        get_angle_d();
    }
    Quadrilateral() :Quadrilateral("Четырехугольник:",10, 20, 30, 40, 50, 60, 70 ,80) {}
protected:
    Quadrilateral(std::string name_, int side_a_, int side_b_, int side_c_, int side_d_, int angle_a_, int angle_b_, int angle_c_, int angle_d_) :Triangle(name_, side_a_, side_b_, side_c_, angle_a_, angle_b_, angle_c_) {
        _side_d = side_d_;
        _angle_d = angle_d_;
    }
private:
    int _side_d = 0;
    int _angle_d = 0;
};

class Parallelogram :public Quadrilateral {
public:
    void print_info() {
        get_side_d();
        get_angle_d();
    }
    Parallelogram() :Parallelogram("Параллелограмм:", 20, 30, 30, 40) {}
protected:
    Parallelogram(std::string name_, int side_a_c_, int side_b_d_, int angle_a_c_, int angle_b_d_) :Quadrilateral(name_, side_a_c_, side_b_d_, side_a_c_, side_b_d_, angle_a_c_, angle_b_d_, angle_a_c_, angle_b_d_) {
    }
};

class Rhombus :public Parallelogram {
public:
    void print_info() {
        get_side_d();
        get_angle_d();
    }
    Rhombus() :Rhombus("Ромб:", 30, 30, 40) {}
private:
    Rhombus(std::string name_, int side_a_b_c_d_, int angle_a_c_, int angle_b_d_) :Parallelogram(name_, side_a_b_c_d_, side_a_b_c_d_, angle_a_c_, angle_b_d_) {
    }
};

class Rectrangle :public  Parallelogram{
public:
    void print_info() {
        get_side_d();
        get_angle_d();
    }
    Rectrangle() :Rectrangle("Прямоугольник:", 10, 20) {}
protected:
    Rectrangle(std::string name_, int side_a_c_, int side_b_d_) :Parallelogram(name_, side_a_c_, side_b_d_, 90, 90) {
    }
};

class Square :public Rectrangle{
public:
    void print_info() {
        get_side_d();
        get_angle_d();
    }
    Square() :Square("Квадрат:", 20) {}
private:
    Square(std::string name_, int side_a_b_c_d_) :Rectrangle(name_, side_a_b_c_d_, side_a_b_c_d_) {
    }
 };

int main()
{
    setlocale(LC_ALL, "Russian");
    Triangle triangle;
    TriangleRight triangleRight;
    TriangleIsos triangleIsos;
    TriangleEquil triangleEquil;
    Quadrilateral quadrilateral;
    Parallelogram parallelogram;
    Rhombus rhombus;
    Rectrangle rectrangle;
    Square square;
    triangle.print_info();
    triangleRight.print_info();
    triangleIsos.print_info();
    triangleEquil.print_info();
    quadrilateral.print_info();
    parallelogram.print_info();
    rhombus.print_info();
    rectrangle.print_info();
    square.print_info();
}