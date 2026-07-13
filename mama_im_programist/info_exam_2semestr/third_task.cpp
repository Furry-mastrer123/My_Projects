#include <iostream>
#include <stdlib.h>
#include <time.h>


template <typename T> void show(T* arr,int elements)
{
    if(elements <= 0) std::exit(1);
    else
    for (int a = 0; a<elements; a++)
    {
        std::cout << arr[a] << " ";
    }
    std::cout << std::endl;
}



template <typename T> T* find_biggest(T* arr,int elements)
{
    if(elements <= 0) std::exit(1);
    T* max = arr;
    for (int a = 0; a<elements; a++)
    {
        if(*max < arr[a]) *max = arr[a];
    }
    return max;
}


template <typename T> T* find_smallest(T* arr,int elements)
{
if(elements <= 0) std::exit(1);
    T* min = arr;
    for (int a = 0; a < elements; a++)
    {
        if(*min > arr[a]) *min = arr[a];
    }
    return min;
}

template <typename T> int how_many_beetween(T* begin_ptr, T* end_ptr)
{
    T* now = begin_ptr;
    int elements = 0;
    while(now != end_ptr)
    {
        elements ++;
        now = now +1;
    }
    return elements;
}

int main(int argc, char* argv[] )
{
    srand(time(0));
    int N = rand()%100;
    int *arr = new int[N];
    for (int a = 0; a<N; a++)
    {
        arr[a] = rand()%100;
    }
    show(arr, N);
    std::cout << *find_biggest(arr, N) << " ";
    std::cout<< *find_smallest(arr, N) << std::endl;
    std::cout<< how_many_beetween(find_biggest(arr, N), find_smallest(arr, N));
    delete[] arr;
    return 0;
}