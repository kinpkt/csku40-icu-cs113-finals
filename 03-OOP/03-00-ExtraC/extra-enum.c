#include <stdio.h>

/*
    enum เป็น keyword สำหรับประกาศค่าคงที่พิเศษที่สามารถตั้งชื่อได้
    โดยจะมีค่าเป็นจำนวนเต็ม แต่ในขณะเดียวกันก็สามารถกำหนดชื่อให้กับค่าคงที่เหล่านั้นได้
*/

enum dayOfWeek
{
    MONDAY = 1,
    TUESDAY = 2,
    WEDNESDAY = 3,
    THURSDAY = 4,
    FRIDAY = 5,
    SATURDAY = 0,
    SUNDAY = -1
};

int main()
{
    enum dayOfWeek today = SUNDAY;

    printf("%d", today); // -1 (ถ้าไม่ได้กำหนดค่าไว้ จะเรียงลำดับตามการประกาศค่า)
    printf("%s", today); // ไม่แสดงค่า

    return 0;
}