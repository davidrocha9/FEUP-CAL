/*
 * Factorial.cpp
 */

#include "Factorial.h"

int factorialRecurs(int n){
    if (n > 0)
        return factorialRecurs(n-1) * n;
    else return 1;
}

int factorialDinam(int n){
    int result = 1;
    for (int x = 1; x <= n; x++)
        result *= x;
    return result;
}