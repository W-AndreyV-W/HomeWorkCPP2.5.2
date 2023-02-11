#include <iostream>
#include <locale.h>


class Triangle{
public:
    std::string get_name() {
        return _name;
    }
    int get_side_a() {
        return _side_a;
    }
    int get_side_b() {
        return _side_b;
    }
    int get_side_c() {
        return _side_c;
    }
    int get_side_d() {
        return _side_d;
    }
    int get_angle_a() {
        return _angle_a;
    }
    int get_angle_b() {
        return _angle_b;
    }
    int get_angle_c() {
        return _angle_c;
    }
    int get_angle_d() {
        return _angle_d;
    }
    int get_quanfig() {
        return _quanfig;
    }
    Triangle() :Triangle("Треугольник:", 3, 10, 20, 30, 50, 60, 70) {}
protected:
    Triangle(std::string name_, int quanfig_, int side_a_, int side_b_, int side_c_, int angle_a_, int angle_b_, int angle_c_) {
        _side_a = side_a_;
        _side_b = side_b_;
        _side_c = side_c_;
        _angle_a = angle_a_;
        _angle_b = angle_b_;
        _angle_c = angle_c_;
        _quanfig = quanfig_;
        _name = name_;
    }
    Triangle(std::string name_, int quanfig_, int side_a_, int side_b_, int side_c_, int side_d_, int angle_a_, int angle_b_, int angle_c_, int angle_d_) {
        _side_a = side_a_;
        _side_b = side_b_;
        _side_c = side_c_;
        _side_d = side_d_;
        _angle_a = angle_a_;
        _angle_b = angle_b_;
        _angle_c = angle_c_;
        _angle_d = angle_d_;
        _quanfig = quanfig_;
        _name = name_;
    }
private:
    int _side_a = 0;
    int _side_b = 0;
    int _side_c = 0;
    int _side_d = 0;
    int _angle_a = 0;
    int _angle_b = 0;
    int _angle_c = 0;
    int _angle_d = 0;
    int _quanfig = 0;
    std::string _name;
};

class TriangleRight :public Triangle {
public:
    TriangleRight() :TriangleRight("Прямоугольный треугольник:", 3, 10, 20, 30, 30, 60){}
private:
    TriangleRight(std::string name_, int quanfig_, int side_a_, int side_b_, int side_c_, int angle_a_, int angle_b_) :Triangle(name_, quanfig_, side_a_, side_b_, side_c_, angle_a_, angle_b_, 90) {
    }
};

class TriangleIsos :public Triangle {
public:
    TriangleIsos() :TriangleIsos("Равнобедренный треугольник:", 3, 10, 20, 50, 60) {}
private:
    TriangleIsos(std::string name_, int quanfig_, int side_a_c_, int side_b_, int angle_a_c_, int angle_b_) :Triangle(name_, quanfig_, side_a_c_, side_b_, side_a_c_, angle_a_c_, angle_b_, angle_a_c_) {
    }
};

class TriangleEquil :public Triangle {
public:
    TriangleEquil() :TriangleEquil("Равносторонний треугольник:",3,  30) {}
private:
    TriangleEquil(std::string name_, int quanfig_, int side_a_b_c_) :Triangle(name_, quanfig_, side_a_b_c_, side_a_b_c_, side_a_b_c_, 60, 60, 60) {
    }
};

class Quadrilateral :public Triangle {
public:
    Quadrilateral() :Quadrilateral("Четырехугольник:", 4, 10, 20, 30, 40, 50, 60, 70 ,80) {}
protected:
    Quadrilateral(std::string name_, int quanfig_, int side_a_, int side_b_, int side_c_, int side_d_, int angle_a_, int angle_b_, int angle_c_, int angle_d_) :Triangle(name_, quanfig_, side_a_, side_b_, side_c_, side_d_, angle_a_, angle_b_, angle_c_, angle_d_) {
    }
};

class Parallelogram :public Quadrilateral {
public:
    Parallelogram() :Parallelogram("Параллелограмм:", 4, 20, 30, 30, 40) {}
protected:
    Parallelogram(std::string name_, int quanfig_, int side_a_c_, int side_b_d_, int angle_a_c_, int angle_b_d_) :Quadrilateral(name_, quanfig_, side_a_c_, side_b_d_, side_a_c_, side_b_d_, angle_a_c_, angle_b_d_, angle_a_c_, angle_b_d_) {
    }
};

class Rhombus :public Parallelogram {
public:
    Rhombus() :Rhombus("Ромб:", 4, 30, 30, 40) {}
private:
    Rhombus(std::string name_, int quanfig_, int side_a_b_c_d_, int angle_a_c_, int angle_b_d_) :Parallelogram(name_, quanfig_, side_a_b_c_d_, side_a_b_c_d_, angle_a_c_, angle_b_d_) {
    }
};

class Rectrangle :public  Parallelogram{
public:
    Rectrangle() :Rectrangle("Прямоугольник:", 4, 10, 20) {}
protected:
    Rectrangle(std::string name_, int quanfig_, int side_a_c_, int side_b_d_) :Parallelogram(name_, quanfig_, side_a_c_, side_b_d_, 90, 90) {
    }
};

class Square :public Rectrangle{
public:
    Square() :Square("Квадрат:", 4, 20) {}
private:
    Square(std::string name_, int quanfig_, int side_a_b_c_d_) :Rectrangle(name_, quanfig_, side_a_b_c_d_, side_a_b_c_d_) {
    }
 };

void print_info(Triangle* triangle) {
    if (triangle->get_quanfig() < 4) {
        std::cout << triangle->get_name() << std::endl;
        std::cout << "Стороны: a=" << triangle->get_side_a() << " b=" << triangle->get_side_b() << " c=" << triangle->get_side_c() << std::endl;
        std::cout << "Углы: A=" << triangle->get_angle_a() << " B=" << triangle->get_angle_b() << " C=" << triangle->get_angle_c() << std::endl;
        std::cout << std::endl;
    }
    else {
        std::cout << triangle->get_name() << std::endl;
        std::cout << "Стороны: a=" << triangle->get_side_a() << " b=" << triangle->get_side_b() << " c=" << triangle->get_side_c() << " d=" << triangle->get_side_d() << std::endl;
        std::cout << "Углы: A=" << triangle->get_angle_a() << " B=" << triangle->get_angle_b() << " C=" << triangle->get_angle_c() << " D=" << triangle->get_angle_d() << std::endl;
        std::cout << std::endl;
    }
}

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
    Triangle* par_triangle = &triangle;
    Triangle* par_triangleRight = &triangleRight;
    Triangle* par_triangleIsos = &triangleIsos;
    Triangle* par_triangleEquil = &triangleEquil;
    Triangle* par_quadrilateral = &quadrilateral;
    Triangle* par_parallelogram = &parallelogram;
    Triangle* par_rhombus = &rhombus;
    Triangle* par_rectrangle = &rectrangle;
    Triangle* par_square = &square;
    print_info(par_triangle);
    print_info(par_triangleRight);
    print_info(par_triangleIsos);
    print_info(par_triangleEquil);
    print_info(par_quadrilateral);
    print_info(par_rectrangle);
    print_info(par_square);
    print_info(par_parallelogram);
    print_info(par_rhombus);
}