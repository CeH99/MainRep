#include <iostream>

class planet {
    int moons;
    
    double dist_from_sun; 
    double diameter;
    double mass;
    public:
    double get_miles () { return dist_from_sun; }
    void set_miles (double a) { 
        dist_from_sun = a;
        }
    };

double light(planet a)
{
    return a.get_miles() / 186000;
}

int main() {  
    planet earth;
    earth.set_miles(93000000);
    std::cout << "Light will travel " << light(earth) << " seconds" << std::endl;

    return 0;
}