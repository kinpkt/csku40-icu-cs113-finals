#include <iostream>
#include <cmath>

using namespace std;

struct Point
{
    double x, y;
};

class Vector
{
    private:
        Point start, end;
    public:
        Vector(Point start, Point end)
        {
            this->start = start;
            this->end = end;
        }

        Point getStart()
        {
            return start;
        }

        Point getEnd()
        {
            return end;
        }

        double getMagnitude()
        {
            return sqrt(pow(start.x-end.x, 2)+pow(start.y-end.y, 2));
        }

        friend Vector normalize(Vector);
};

Vector normalize(Vector vec)
{
    double magnitude = vec.getMagnitude();

    if (magnitude == 0)
    {
        return vec; 
    }

    // ฟังก์ชัน normalize เป็น friend เลยทำให้สามารถเข้าถึง data member ของคลาสได้โดยตรง
    Point newEnd;
    newEnd.x = vec.start.x+(vec.end.x-vec.start.x)/magnitude;
    newEnd.y = vec.start.y+(vec.end.y-vec.start.y)/magnitude;

    return Vector(vec.start, newEnd);
}

int main()
{
    Point p1 = {0.0, 0.0};
    Point p2 = {3.0, 4.0};

    Vector v1(p1, p2);

    cout << "Original Magnitude: " << v1.getMagnitude() << endl;

    Vector vUnit = normalize(v1);

    cout << "Normalized Magnitude: " << vUnit.getMagnitude() << " (Should be 1)" << endl;
    cout << "New End Point: (" << vUnit.getEnd().x << ", " << vUnit.getEnd().y << ")" << endl;

    return 0;
}