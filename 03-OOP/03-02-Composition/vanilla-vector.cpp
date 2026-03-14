#include <iostream>
#include <cmath>

using namespace std;

class Vector
{
    private:
        double xStart, yStart, xEnd, yEnd;

    public:
        Vector(double x1, double y1, double x2, double y2)
        {
            this->xStart = x1;
            this->yStart = y1;
            this->xEnd = x2;
            this->yEnd = y2;
        }

        double getMagnitude() const
        {
            return sqrt(pow(xEnd - xStart, 2) + pow(yEnd - yStart, 2));
        }

        double getXEnd()
        { 
            return xEnd; 
        }

        double getYEnd() 
        { 
            return yEnd; 
        }

        friend Vector normalize(const Vector&);
};

Vector normalize(const Vector& vec)
{
    double magnitude = vec.getMagnitude();

    if (magnitude == 0)
    {
        return vec;
    }

    double newXEnd = vec.xStart + (vec.xEnd - vec.xStart) / magnitude;
    double newYEnd = vec.yStart + (vec.yEnd - vec.yStart) / magnitude;

    return Vector(vec.xStart, vec.yStart, newXEnd, newYEnd);
}

int main()
{
    Vector v1(0.0, 0.0, 3.0, 4.0);

    cout << "Original Magnitude: " << v1.getMagnitude() << endl;

    Vector vUnit = normalize(v1);

    cout << "Normalized Magnitude: " << vUnit.getMagnitude() << endl;
    cout << "New End Point: (" << vUnit.getXEnd() << ", " << vUnit.getYEnd() << ")" << endl;

    return 0;
}