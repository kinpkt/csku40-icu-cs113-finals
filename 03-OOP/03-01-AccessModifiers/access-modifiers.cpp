#include <iostream>

using namespace std;

class PublicPoint
{
    public:
        int x, y;

        PublicPoint(int x, int y)
        {
            this->x = x;
            this->y = y;
        }
};

class PrivatePoint
{
    private:
        int x, y;

    public:
        PrivatePoint(int x, int y)
        {
            this->x = x;
            this->y = y;
        }
};

int main()
{
    PublicPoint pt1 = PublicPoint(6, 8);
    PrivatePoint pt2 = PrivatePoint(6, 8);

    // ทดลองเข้าถึง x, y ของ pt1
    cout << pt1.x << " " << pt1.y << endl;

    // ทดลองเข้าถึง x, y ของ pt2 (ทำไม่ได้)
    cout << pt2.x << " " << pt2.y << endl;

    return 0;
}