#include <iostream>
#include <stdlib.h>
#include <time.h>

template <typename T> int func (T* arr, int & width)
{
    if (width == 0) 
    {std::cout << "there is no elements in the array";
        return 0;}

    T* last_min = arr;


    for(int a = 0; a <width; a++)
    {
        if(arr[a] < T()) last_min = (arr+a);
    }

    if(last_min == (arr + width -1 )) return 0;
    int func = 0;
    do
    {
        func++;
        last_min++;
    }
    while (last_min != (arr +width -1 ));
    return func;
}


int main (int argc, char* argv [])
{
    srand(time(0));
    int N = rand()%20;
    if(N<=0){do{N=rand();}while(N<=0);}
    float* arr = new float[N];
    for (int a = 0; a != N; a++)
    {
        arr[a] = rand()%199 -100;
        std::cout << arr[a] << " ";
    }
    std::cout << "there is " << func(arr, N) <<" positive elements after last signed" << std::endl;
    delete[] arr;
    return 0;
}