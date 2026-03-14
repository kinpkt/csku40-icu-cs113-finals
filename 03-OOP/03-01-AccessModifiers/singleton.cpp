#include <iostream>

using namespace std;

/*
    Singleton Pattern เป็นหนึ่งใน Design Pattern ในการทำซอฟต์แวร์
    โดยจะอนุญาตให้สร้าง instance ของคลาสที่เป็น Singleton เพียงตัวเดียวตลอดการทำงาน
    (จะได้เรียนอีกทีในวิชา 01418211 - Software Construction)
*/

class Database
{
    private:
        Database()
        {
            cout << "Database connection established." << endl;
        }

    public:
        Database(const Database&) = delete;
        void operator=(const Database&) = delete;

        static Database& getInstance()
        {
            static Database instance; 
            return instance;
        }

        void query(string sql)
        {
            cout << "Executing: " << sql << endl;
        }
};

int main()
{
    Database& db = Database::getInstance();
    db.query("SELECT * FROM users");

    Database::getInstance().query("DROP TABLE cache");

    return 0;
}