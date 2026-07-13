#include <iostream>
#include "random.h"


using std::cout;
using std::cin;

template <typename T>inline void func(T** arr, int collomns, int strings)             //terpim terpim...
{
    for(int a = 0; a < collomns; a++)
    {
        int i_signed =0, i_unsigned = 0;
        for (int b = 0; b < strings; b++)
        {
            if(arr[a][b] < T()) i_signed++;
            else if(arr[a][b] > T()) i_unsigned++;
        }
        cout << "there is " << i_signed << "signed elements and " << i_unsigned << "unsigned elements in " << a+1 << "collomn" << std::endl;
    }
    int objee = 0;
    int numbers = collomns*strings;
    for (int a = 0; a < collomns; a++ )  
    {
        for (int b =0; b < strings; b++)
        {
            objee = objee + (int)arr[a][b];
        } 
    }
    cout << ((float)objee/numbers) << " its strednee  of the array";
    return;
}


template <typename T>inline void print (T** arr, int collomns, int strings)             //ebat togo
{
    for (int a = 0; a != collomns; a++ )
    {
        for (int b =0; b!= strings; b++)
        {
            cout << arr[a][b] << " ";
        } 
        cout << std::endl;
    }
}

int main(int argc, char* argv[])                    //terpim...terpim...
{
    srand(time(0));
    int strings = 0, collomns = 0;


    do{
        strings = random(10);
        collomns = random(10);
    } while(strings<=0 || collomns<=0);
    int** arr = new int* [collomns];
    

    for (int a = 0; a != collomns; a++)
    {
        arr[a] = new int[strings];
        for (int b = 0; b != strings; b++)
        arr[a][b] = random(100);
    }
    
    print(arr, collomns, strings);
    func(arr, collomns, strings);

    for (int a = 0; a != collomns; a++ )
    {
     delete[] arr[a];
    }
    delete[] arr;


    int m;      //proverka logiki na vipolneniye
    cin >> m;
}