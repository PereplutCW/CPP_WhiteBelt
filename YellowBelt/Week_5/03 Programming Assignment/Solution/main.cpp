#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <memory>
#include <cmath>

using namespace std;

class Figure {
public:
    virtual string Name() const = 0;
    virtual double Perimeter() const = 0;
    virtual double Area() const = 0;
};

class Triangle : public Figure {
public:
    Triangle(const double& side_a, const double& side_b, const double& side_c) 
            : side_a_(side_a), side_b_(side_b), side_c_(side_c) {}
    virtual string Name() const override {
        return "TRIANGLE";
    }
    virtual double Perimeter() const override {
        return side_a_ + side_b_ + side_c_;
    }
    virtual double Area() const override {
        double p = (side_a_ + side_b_ + side_c_) / 2;
        return sqrt(p * (p - side_a_) * (p - side_b_) * (p - side_c_));
    }
private:
    double side_a_, side_b_, side_c_;
};

class Rect : public Figure {
public:
    Rect(const double& width, const double& height) : width_(width), height_(height) {}
    virtual string Name() const override {
        return "RECT";
    }
    virtual double Perimeter() const override {
        return (width_ + height_) * 2;
    }
    virtual double Area() const override {
        return width_ * height_;
    }
private:
    double width_, height_;
};

class Circle : public Figure {
public:
    Circle(const double& radius) : radius_(radius) {}
    virtual string Name() const override {
        return "CIRCLE";
    }
    virtual double Perimeter() const override {
        return 2 * 3.14 * radius_;
    }
    virtual double Area() const override {
        return 3.14 * radius_ * radius_;
    }
private:
    double radius_;
};

shared_ptr<Figure> CreateFigure(istringstream& is) {
    string figure_type;
    is >> figure_type;

    if (figure_type == "TRIANGLE") {
        double side_a, side_b, side_c;
        is >> side_a >> side_b >> side_c;
        return make_shared<Triangle>(side_a, side_b, side_c);
    } else if (figure_type == "RECT") {
        double width, height;
        is >> width >> height;
        return make_shared<Rect>(width, height);
    } else if (figure_type == "CIRCLE") {
        double radius;
        is >> radius;
        return make_shared<Circle>(radius);
    }
}

int main() {
    vector<shared_ptr<Figure>> figures;
    for (string line; getline(cin, line); ) {
        istringstream is(line);

        string command;
        is >> command;
        if (command == "ADD") {
            is >> ws;
            figures.push_back(CreateFigure(is));
        } else if (command == "PRINT") {
            for (const auto& current_figure : figures) {
                cout << fixed << setprecision(3) << 
                current_figure->Name() << " " <<
                current_figure->Perimeter() << " " <<
                current_figure->Area() << endl;
            }
        }

    }
    return 0;
}