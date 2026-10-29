#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

// inline float determinant (float* arr[], int arr_num, int colomn_num, int start_arr_index = 0, int start_col_index = 0)      //dodelat ... huynya
// {
//     if (arr_num == 1 || arr_num == 0) return arr[start_arr_index][start_col_index];
//     float addition = 0;
//     if (colomn_num == 2 && arr_num ==2) return (arr[start_arr_index][start_col_index]*arr[start_arr_index+1][start_col_index+1]-arr[start_arr_index][start_col_index+1]*arr[start_arr_index+1][start_col_index]);
//     for(int i = start_col_index; i != colomn_num; i++)
//     {
//         if(i%2 == 0) addition = addition +  arr[start_arr_index][i]*determinant(arr, arr_num-1, colomn_num-1, start_arr_index + 1, start_arr_index+i+1);
//         else addition = addition - arr[start_arr_index][i]*determinant(arr, arr_num-1, colomn_num-1, start_arr_index + 1, start_arr_index+i+1);
//     }
//     return addition;
// }


inline float norma_calc(float* matrix[], int arr_num, int col_num)
{
    float* arr = new float[col_num]();      //skobki -> znach po umolchaniyu


    for(int j = 0; j!= col_num; j++)
        {for(int i =0; i != arr_num; i++)
            {
                arr[j] += fabs(matrix[i][j]);
            }
        }


    float res = 0;
    for (int i = 0; i!= col_num; i++)
    {
        if(res < arr[i]) res = arr[i];
    }
    delete[] arr;
    return res;
}


// inline int* multiplication (int arr_1[], int arr_1_arr_num, int arr_1_col_num, int arr_2[[]], int arr_2_arr_num, int arr_2_col_num)  //dodelat
// {
//     int *arr = new int[];
//     return arr;
// }


float** matrix(fstream& fstr, int i_max = 6, int j_max = 6)           //6 po zadaniyu
{
    float** matrix = new float*[i_max](); 
    for (int i = 0; i != i_max; i++)
    {
        matrix[i] = new float[j_max]();
    }

    for(int i =0; i!= i_max; i++)
    {
        for(int j = 0; j != j_max; j++)
        {
            fstr >> matrix[i][j];
        }
    }
    return matrix;
}


inline int write_in_file(ofstream& ofst, float* matri[], int i_size, int j_size)      //doselat
{
    return 0;
}


float cond_number(float* matrix[], int arr_num_1, int colomn_num_1, float* backward_matrix[], int arr_num_2, int colomn_num_2)       //chislo obuslov, dodelat
{
    int cond_num = 0;
    float norma_1 = norma_calc(matrix, arr_num_1, colomn_num_1);
    float norma_2 = norma_calc(backward_matrix, arr_num_2, colomn_num_2);
    return norma_1*norma_2;
}


int main(int argc, char* argv)
{
    ofstream read_file("six_task.txt");
    ifstream write_backward_matrix("six_task_backward_mat.txt");
    ifstream write_multip_matrix("mat_multiplic.txt");
    return 0;
}

