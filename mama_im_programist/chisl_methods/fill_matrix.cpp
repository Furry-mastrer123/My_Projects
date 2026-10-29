#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;


inline float func(int x, int y)
{
    return logf(x+y+1);
}

int main(int argc, char* argv[])
{
    int lim = 6;
    ofstream write_in_file_matrix("six_task_matrix.txt");
    if (!write_in_file_matrix.is_open()) return 1;


    for (int x = 0; x != lim; x++)
    {
        for(int y = 0; y !=lim; y++)
        {
            float res = func(x,y);
            write_in_file_matrix << res;
            char space = ' ';
            write_in_file_matrix << space;
        }
    }

    cout << "programm end";
    return 0;
}