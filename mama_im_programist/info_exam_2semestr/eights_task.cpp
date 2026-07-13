#include <iostream>
#include "random.h"


template <typename T> double func (T arr[], int size, T& min, T& max)
{
    double srednee = 0;
    
    
    for(int a = 0; a < size; a++)
    {
    double element = *(arr+a);
    srednee = srednee+element;
    if(element > max) max = element;
    if(element < min) min = element;
    std::cout<< min << " " << max << " " << srednee << std::endl; 
    }


    srednee = srednee/size;
    return srednee;
}

template <typename T>void show(T arr[], int size)                 //dlya proverki
{
    for (int a = 0; a < size; a++)
    {std::cout <<  arr[a] << " ";}
    std::cout << std::endl;   
}




int main (int atrgc, char* argv[])
{
srand(time(0));
int elem_num = 20;              //for generation restrictions (ogranisheniye po shislu elementov)

int el_num_1 = random_polosh(elem_num);

int *arr_1 = new int[el_num_1];
for (int a = 0; a < el_num_1; a++)
{
    arr_1[a] = random(elem_num);
}
show(arr_1, el_num_1);

int el_num_2 = random_polosh(elem_num);
float *arr_2 = new float[el_num_2];
for (int a = 0; a < el_num_2; a++)
{
    arr_2[a] = random(elem_num)/1.1;
}
show(arr_2, el_num_2);

int el_num_3 = random_polosh(elem_num);
double *arr_3 = new double[el_num_3];
for (int a = 0; a < el_num_3; a++)
{
    arr_3[a] = random(elem_num)/2.5;
}
show(arr_3, el_num_3);
int min_1 =0, max_1 = 0;
float min_2 = 0, max_2 = 0;
double min_3 = 0, max_3 = 0;


int srednee_1 = func(arr_1, el_num_1, min_1, max_1);
float srednee_2 = func(arr_2, el_num_2, min_2, max_2);
double srednee_3 = func(arr_3, el_num_3, min_3, max_3);
std::cout << "int arr srendee is: " << srednee_1 << " int arr min element is: " << min_1 << " int element max is: " << max_1 << std::endl;
std::cout << "float arr srendee is: " << srednee_2 << " float arr min element is: " << min_2 << " float element max is: " << max_2 << std::endl;
std::cout << "double arr srendee is: " << srednee_3 << " double arr min element is: " << min_3 << " double element max is: " << max_3 << std::endl;
int a = 0;
std::cin >> a; 

delete[] arr_1;
delete[] arr_2;
delete[] arr_3;
return 0;
}