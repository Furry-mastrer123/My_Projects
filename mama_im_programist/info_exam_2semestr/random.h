#pragma once
#include <stdlib.h>
#include <time.h>

inline int random(int N)
{
    return rand()%(2*N+1) -N;
}


inline int random_polosh(int N)
{
    return rand()%N;
}