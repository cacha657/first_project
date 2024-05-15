#include <stdio.h>
#include <stdlib.h>
#include "lr.h"

int main()
{
    int num;
    scanf_s("%d", &num);
    switch (num) {

    case 1:
        labl1();
        break;
    case 11:
        labl1dop();
        break;
    case 2:
        labl2();
        break;
    case 22:
        labl2dop();
        break;
    case 3:
        labl3();
        break;
    case 33:
        labl3dop();
        break;
    case 4:
        labl4();
        break;
    case 44:
        labl4dop();
        break;
    case 5:
        labl5();
        break;
    case 55:
        labl5dop();
        break;
    case 6:
        labl6();
        break;
    case 7:
        labl7();
    }
    return 0;
}
