#include <iostream>
using namespace std;


template <typename T> class dyn_arr
{
    private:
    int filled = 0;
    int size = filled + 5;
    T* arr = new T[size];
    public:
    dyn_arr();
    ~dyn_arr();
    void push(T element);
    int get_filled();
    T& operator[] (int element);
    template <typename T> friend std::ostream& operator << (std::ostream& os, dyn_arr<T>& d_arr);
};


template <typename T> dyn_arr<T>::dyn_arr() 
{
    for(int a = 0; a < this->size;a++)
    {
        this->arr[a] = T();
    }
}


template <typename T> dyn_arr<T>::~dyn_arr()
{
    delete[] arr;
    size  = 0;
}


template <typename T> void dyn_arr<T>::push(T element)
{
    if(filled == size){
        T* arr_2 = new T[size + 5];
        for(int a = 0; a < size; a++)
        {
        arr_2[a] = arr[a];
        }
        arr_2[size] = element;
        for (int a = size+1; a < (size+5); a++ )
        {
        arr_2[a] = T();
        }
        delete[] arr;
        arr = arr_2;
        size = size +5;
        filled++;
                     }
    else{
    arr[filled] = element;
    filled++; 
        }
}


template <typename T> int dyn_arr<T>::get_filled()
{
    return filled;
}


template <typename T> T& dyn_arr<T>::operator[] (int element)
{
    return arr[element];
}


template <typename T> std::ostream& operator << (std::ostream& os, dyn_arr<T>& d_arr)
{
    for(int a = 0; a < d_arr.size; a++)
    {
        os << d_arr[a] << " ";
    }
    os << std::endl;
    return os;
}


int main(int argc, char* argv[])
{
    dyn_arr <float> d_arr;
    d_arr.push(2.012);
    d_arr.push(2.051);
    d_arr.push(0.12);
    d_arr.push(2.012);
    d_arr.push(2.051);
    d_arr.push(0.12);
    std::cout << d_arr;
    int a ;
    std::cin >> a;
    return 0;
}