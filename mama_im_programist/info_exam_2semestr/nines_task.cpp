#include <iostream>

class dyn_arr
{
    private:
    int filled = 0;
    int El=0;
    int size = El+5;
    int *arr = new int [size];           //pyat chtobi ne obnovlyat kachdiy raz
    public:
    dyn_arr();
    ~dyn_arr();
    void push(int element);
    int get_filled_num();
    int& operator [](int element);
    friend std::ostream& operator << (std::ostream& pnbb, const dyn_arr& d_arr); 
};


int dyn_arr::get_filled_num()
{
    return this->filled;
}


dyn_arr::dyn_arr()
{
    for (int a = 0; a < this->size; a++)
    {
        this->arr[a] = 0;
    }
}


dyn_arr::~dyn_arr()
{
    delete[] this->arr;
    filled = 0;
    El = 0;
}


void dyn_arr::push(int element)
{
    this->arr[filled] = element;
    filled++;
}


int& dyn_arr::operator[](int element)
{
    return this->arr[element];                  // it isnt ssilka dolbaeb(vrode kak)
}       


std::ostream& operator << (std::ostream& pnbb, const dyn_arr& d_arr)
{
    for(int a = 0; a < d_arr.filled; a++)
    {
        pnbb << d_arr.arr[a] << " ";
    }
    pnbb << std::endl;
    return pnbb;
}


int main(int argc, char* argv[])
{   
    dyn_arr Arr;
    Arr.push(100);
    Arr.push(12);
    std::cout << Arr[1];
    std::cout << Arr;
    int a= 0;
    std::cin>> a;
    return 0;
}
