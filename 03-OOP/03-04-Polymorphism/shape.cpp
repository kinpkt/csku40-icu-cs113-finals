#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Shape
{
    public:
        virtual double getArea() = 0;
};

class Circle : public Shape
{
    private:
        double radius;
    public:
        Circle()
        {
            radius = 0;
        }

        Circle(double radius)
        {
            this->radius = radius;
        }

        virtual double getArea()
        {
            return acos(-1)*radius*radius;
        }
};

class Rectangle : public Shape
{
    private:
        double width, height;
    public:
        Rectangle()
        {
            width = height = 0;
        }
        
        Rectangle(double width, double height)
        {
            this->width = width;
            this->height = height;
        }

        virtual double getArea()
        {
            return width*height;
        }
};

int main()
{
    vector<Shape*> shapes;

    Circle c1 = Circle(7);
    Rectangle r1 = Rectangle(15, 2);

    shapes.push_back(&c1);
    shapes.push_back(&r1);

    for (auto shape : shapes)
    {
        cout << "Area of the shape = " << shape->getArea() << " unit^2." << endl;
    }

    return 0;
}