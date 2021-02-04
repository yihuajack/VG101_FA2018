#include <stdio.h>
enum Days{Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday};

int main()
{
    enum Days day;
    day = Monday;
    printf("day = %d\n", day);
    day = day + 2;
    printf("day = %d\n", day);
    return 0;
}
