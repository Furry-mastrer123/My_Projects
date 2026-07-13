#include <iostream>
#include "random.h"


void show(int* arr, int el_num)
{
    for (int a = 0; a < el_num; a++)
    {std::cout <<  arr[a] << " ";}
    std::cout << std::endl;   
}

void Quick_sort(int* arr, int left_index, int right_index)
{  
    int pivot = arr[left_index + (right_index - left_index)/2+1];
    int i = left_index;
    int j = right_index;            //v main kolvo elementov-1 sdelal
    if(i != j)
    {
    while(i <=j )
    {
        while(arr[i]< pivot && i <= right_index) i++;
        while(arr[j] > pivot && j >= left_index) j--;
        if ( i<=j )
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }
    
       if (j > left_index) Quick_sort(arr, left_index, j);
       if (i < right_index) Quick_sort(arr, i, right_index);
    }
    return;
}




int main(int argc, char* argv[])
{  
    srand(time(0));
    int N = random_polosh(12);
    int* arr = new int[N];
    for(int a = 0; a < N; a++)
    {
        arr[a] = random(N);
    }
    show(arr,N);
    Quick_sort(arr, 0, N-1);
    show(arr, N);
    int a;
    std::cin>> a;
    return 0;
}
