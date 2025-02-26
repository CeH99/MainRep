#include <iostream>
#include <cmath>

using namespace std;

class Area{
    public:
    double height;
    double width;
};

class Rectangle : Area{
    public:
    Rectangle(double h, double w) {
        height = h;
        width = w;
    };   
    double area()
    {
        return height * width;
    };
};

class Isosceles : Area{
    public:
    Isosceles(double h, double w) {
        height = h;
        width = w;
    };   
    double area()
    {
        return height * width / 2;
    }
};

class Cylinder : Area{
    public:
    Cylinder(double h, double w) {
        height = h;
        width = w;
    };   
    double area()
    {
        return 2 * 3.14 * height * (width/2) + 2 * 3.14 * pow((width/2), 2);
    }
};

int main() {

    Rectangle r(10, 5);
    Isosceles i(7, 7);
    Cylinder c(15, 3);
    cout << r.area() << endl;
    cout << i.area() << endl;
    cout << c.area() << endl;
    return 0;
}