#include <iostream>
#include "random.h"



void fill(int arr[])
{
    for (int a =0; a < sizeof(arr)/2; a++)
    {
        arr[a] = random(10);
    }
}



void show(int* arr)
{
    for (int a = 0; a < sizeof(arr)/4; a++)
    {std::cout <<  arr[a] << " ";}
    std::cout << std::endl;   
}



float find_srednee(int arr[])
{
    float srednee = 0;
    for (int a = 0; a < sizeof(arr)/2; a++)
    {
        srednee = srednee + arr[a];
    }
    srednee = srednee/sizeof(arr);
    return srednee;
}



void which_srednee_is_bigger(int arr_1[], int arr_2[])
{
    float srednee_1 = find_srednee(arr_1);
    float srednee_2 = find_srednee(arr_2);
    if(srednee_1>srednee_2) std::cout<< "srednee v pervom masive bolshe ";
    if(srednee_1<srednee_2) std::cout<< "srednee v pervom masive menshe ";
    if(srednee_1==srednee_2) std::cout<< "srednee v pervom masive ravno vtoromu srednemu ";
}



int main(int argc, char* argv[])
{
    srand(time(0));
    int N =10;


    int* arr_1 = new int [random_polosh(N)];            //initializiruen
    int *arr_2 = new int [random_polosh(N)]; 

    
    fill(arr_1);                    // zapolnyaem
    fill(arr_2);


    show(arr_1);                    //pokashi
    show(arr_2);
    which_srednee_is_bigger(arr_1, arr_2);              //tsk kskor bolshe?


    int a;
    std::cin >> a;


    delete[] arr_1;                                     //udalyi nahui
    delete[] arr_2;


    return 0;
}