#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>

using namespace std;

inline float determinant(float** matrix, int arr_num, int col_num)
{
    float res =0;   

    if(arr_num != col_num) 
        {
            cout<< "error, number of collomns and arrays are not equal!";
            return 0;
        }
    if(col_num == 1)return matrix[0][0];
    
    float** matrix_b = new float*[col_num];
    for(int i =0; i !=arr_num; i++)
    {
        matrix_b[i] = new float[col_num]();
        for(int j =0; j!= col_num; j++)
        {
            matrix_b[i][j] = matrix[i][j];
        }
    }

    int max_diag_el = 0;
    for (int i = 0; i!= col_num; i++) {
        if(fabs(matrix[i][0]) > fabs(matrix[i][max_diag_el])) max_diag_el = i;
    }

    if(max_diag_el != 0) 
    {
        float* pivot = matrix[0];
        matrix[0] = matrix[max_diag_el];
        matrix[max_diag_el] = pivot; 
    }

    float pivot_el = matrix[0][0];
    for(int i =0; i!= col_num; i++)
    {
        matrix[0][i] = matrix[0][i]/pivot_el;
    }

    for(int i = 1; i != arr_num; i++)
    {
        float pivot_3 = matrix[i][0];
        for(int j =0; j!= col_num; j++)
        {
            matrix[i][j] = matrix[i][j] - matrix[0][j]*pivot_3;
        }
    }

    float **matrix_c = new float*[arr_num-1];
    for(int i =0; i!=arr_num-1; i++)
    {
        matrix_c[i] = new float[col_num-1]();
    }

    for(int i =1; i!= arr_num; i++)
    {
        for(int j =1; j!= col_num; j++)
        {
            matrix_c[i-1][j-1] = matrix_b[i][j];
        }
    }


    if(max_diag_el != 0)
    {
        res = -matrix_b[0][0];
    }
    else
    {
        res = pivot_el;
    }

    res *= determinant(matrix_c, arr_num-1, col_num-1);
    
    for(int i =0; i!=arr_num; i++)
    {
        delete[] matrix_b[i];
    }
    delete[] matrix_b;


    for(int i =0; i!=arr_num-1; i++)
    {
        delete[] matrix_c[i];
    }
    delete[] matrix_c;


    return res;
}   

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


// inline float** multiplication (int arr_1[], int arr_1_arr_num, int arr_1_col_num, int arr_2[[]], int arr_2_arr_num, int arr_2_col_num)  //dodelat
// {
//     int *arr = new int[];
//     return arr;
// }


float** matrix(ifstream& fstr, int i_max = 6, int j_max = 6)           //6 po zadaniyu
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


float cond_number(float* matrix[], int arr_num_1, int colomn_num_1,
     float* backward_matrix[], int arr_num_2, int colomn_num_2)       //chislo obuslov, dodelat
{
    int cond_num = 0;
    float norma_1 = norma_calc(matrix, arr_num_1, colomn_num_1);
    float norma_2 = norma_calc(backward_matrix, arr_num_2, colomn_num_2);
    return norma_1*norma_2;
}


int main(int argc, char* argv)
{
    int n = 6;      //razmer
    ifstream read_file("six_task.txt");
    float** Matrix_A = new float*[n];
    Matrix_A = matrix(read_file, n, n);
    
    float det = determinant(Matrix_A, n, n);
    cout << det;
    if(det == 0)
    {
        cout << "opredelitel = o!";
        return 0;
    }



    float** backward_matrix = new float*[n];
    backward_matrix = method_jardan_gausse(Matrix_A);    

    
    float con_num = cond_number(Matrix_A, n, n, backward_matrix, n, n);
    cout << con_num;

    ofstream write_backward_matrix("six_task_backward_mat.txt");
    ofstream write_multip_matrix("mat_multiplic.txt");
    return 0;
}

