#include <iostream>

using namespace std;

class Numbers
{
private:
    int a = 0;
    int b = 0;
public:
    void set(int first, int second);
    void Print();
};

class Ball
{
private:
    string m_color;
    float m_radius;
public:
    void Print();
    void setcolor(string);
    void setradius(float);
    void setradius_and_color(string, float);
    Ball();
};


int main(void)
{
    Numbers number;
    number.Print();
    cout << "-----------------------------------------"<< endl;
    number.set(3,4);
    number.Print();

    Ball first;

    first.setcolor("Yellow");
    first.setradius(20.7);
    
    Ball second;

    second.setradius_and_color("Red", 15.3);

    first.Print();
    cout << "-------------------------" << endl;
    second.Print();
    cout << endl;

    Ball third;

    third.Print();
    return 0;
}

void Numbers::set(int first, int second)
{
    a = first;
    b = second;
}

void Numbers::Print()
{
    cout << "a is " << a << endl;
    cout << "b is " << b << endl;
}

void Ball::setcolor(string str)
{
    m_color = str;
}

void Ball::setradius(float a)
{
    m_radius = a;
}

void Ball::setradius_and_color(string str, float a)
{
    m_color = str;
    m_radius = a;
}

void Ball::Print()
{
    cout << "Color of this ball is " << m_color << endl;
    cout << "Radius of this ball is " << m_radius << endl;
}

Ball::Ball()
{
    m_color = "Red";
    m_radius = 20.0;
}