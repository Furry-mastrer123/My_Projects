#include <iostream>
#include "random.h"

template <typename T> void show(T* arr, int el_num)
{
    for (int a = 0; a < el_num; a++)
    {std::cout <<  arr[a] << " ";}
    std::cout << std::endl;   
}



template <typename T> void Quick_sort(T* arr, int left_index, int right_indeex, int el_num)
{
    if(right_indeex == left_index) return;
    T pivot = arr[left_index + (right_indeex-left_index)/2];
    int i = left_index;
    int j = right_indeex;
    while (i <= j)
    {
        while(arr[i]< pivot)i++;
        while(arr[j] > pivot) j--;
        if( i <= j){    
        std::swap(arr[i], arr[j]);
        show(arr, el_num );
        i++;
        j--;
        }
    }
    if (j > left_index) Quick_sort(arr, left_index, j, el_num);
    if (i < right_indeex) Quick_sort(arr, i, right_indeex, el_num);
    return;    
}



int main(int argc, char* argv[])
{
    srand(time(0));
    int N = random_polosh(20);


    int* arr = new int[N];
    for (int a = 0; a < N; a++)
    {
        arr[a] = random(N);
    }


    show(arr, N);
    Quick_sort(arr, 0 , N-1, N);
    show(arr,N);


    int a;
    std::cin >> a;
    return 0;
}