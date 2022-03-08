#include "common.h"

void swap(int &A, int &B)
{
    int temp = A;
    A = B;
    B = temp;
}

int abs(const int &A)
{
    return (A>0) ? A : -A;
}