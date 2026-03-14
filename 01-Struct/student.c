#include <stdio.h>

struct Student
{
    char nickname[101];
    int age;
    char student_id[6];
    char classroom[5];
};

int main()
{
    struct Student std1 = {"Kin", 17, "42560", "6/15"};
    struct Student *ptr = &std1;

    // ขนาดของ struct จะเท่ากับผลรวมของขนาดของสมาชิกทั้งหมดใน struct
    printf("Size of student struct = %d\n", sizeof(std1)); 

    // เข้าถึงสมาชิกของ struct ได้จาก dot operator (.)
    printf("ID: %s\n", std1.student_id);
    printf("Student's name is %s.\n", std1.nickname);
    printf("Student's age is %d year(s) old.\n", std1.age);

    // ถ้าตัวแปรเป็น pointer ที่ชี้ไปหา struct จะใช้ arrow operator (->) แทน dot operator (.)

    printf("Accessing classroom by pointer: %s\n", ptr->classroom);

    // สามารถแก้ไขค่าใน struct ได้
    std1.age++;
    printf("Student's new age is %d year(s) old.\n", std1.age);

    return 0;
}