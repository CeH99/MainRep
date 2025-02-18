#include <iostream>

using namespace std;

class mybox {
private:
    double a, b, c, v;

public:
    mybox(double a, double b, double c) : a(a), b(b), c(c), v(a*b*c) { }

    void volume() {
        cout << "Volume of this object is " << v << endl;
    }
};

int main() {
    mybox a(5.0, 5.4, 5.6);
    a.volume(); 

    mybox b(34.64, 0.4, 25.6);
    b.volume(); 

    return 0;
}
