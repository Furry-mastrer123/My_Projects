#include <iostream>
#include <fstream>
using namespace std;

double calc_max_el(double *vec, int arr_num)
{
    int max_num_el = 0;
    for (int i = 0; i != arr_num; i++)
    {
        if (vec[max_num_el] < vec[i])
            max_num_el = i;
    }
    return vec[max_num_el];
}

double *method_prostix_iter(double **matrix, double *colomn, int arr_num, int col_num, double accuracy)
{
    double *vec_prev = new double[col_num]; // previous solition vector
    for (int i = 0; i != col_num; i++)
    {
        vec_prev[i] = 0;
    }

    double *vec_act = new double[arr_num]; // actual solution vector
    for (int i = 0; i != col_num; i++)
    {
        vec_prev[i] = 0;
    }

    double **matrix_koeff = new double *[arr_num]; // kopirovaniye matrici
    {
        for (int i = 0; i != arr_num; i++)
        {
            matrix_koeff[i] = new double[col_num]();
        }
        for (int i = 0; i != arr_num; i++)
        {
            for (int j = 0; j != col_num; j++)
            {
                matrix_koeff[i][j] = matrix[i][j];
            }
        }
    }

    double *free_vec = new double[arr_num](); // copy colomn
    for (int i = 0; i != arr_num; i++)
    {
        free_vec[i] = colomn[i];
    }

    for (int i = 0; i != arr_num; i++) // privedeniye r nuzhnomu vidu
    {
        double pivot = matrix_koeff[i][i];
        for (int j = 0; j != col_num; j++)
        {
            if (i == j)
            {
                matrix_koeff[i][j] = 0;
            }
            else
            {
                matrix_koeff[i][j] = -1 * matrix_koeff[i][j] / pivot;
            }
        }
        free_vec[i] = free_vec[i] / pivot;
    }

    do // method itself
    {

    } while (calc_max_el(vec_act, arr_num) - calc_max_el(vec_prev, arr_num) > accuracy);

    return vec_prev;
}

// 100 symbols is about 5 symbols less than next string
double *method_zeydel(double **matrix, double *colomn, int arr_num, int col_num) // dodelat
{
    double *vec = new double[col_num];
    for (int i = 0; i != col_num; i++)
    {
        vec[i] = 0;
    }
    return vec;
}

double **make_koef_matrix(int arr_num, int col_num)
{
    double **matrix = new double *[arr_num];
    for (int i = 0; i != arr_num; i++)
    {
        matrix[i] = new double[col_num];
    }

    for (int i = 0; i != arr_num; i++)
    {
        for (int j = 0; j != col_num; j++)
        {
            if (i == j)
            {
                matrix[i][j] = 7 + i + j;
            }
            else
            {
                matrix[i][j] = 2 + i + j;
            }
        }
    }
    return matrix;
}

double *make_col(int arr_num)
{
    double *col = new double[arr_num];
    for (int i = 0; i != arr_num; i++)
    {
        col[i] = i + 1;
    }
    return col;
}

inline double norma_calc(double *matrix[], int arr_num, int col_num)
{
    double *arr = new double[col_num](); // skobki -> znach po umolchaniyu

    for (int j = 0; j != col_num; j++)
    {
        for (int i = 0; i != arr_num; i++)
        {
            arr[j] += fabs(matrix[i][j]);
        }
    }

    double res = 0;
    for (int i = 0; i != col_num; i++)
    {
        if (res < arr[i])
            res = arr[i];
    }
    delete[] arr;
    return res;
}

inline int write_in_file(ofstream &ofst, double *matrix[], int i_size, int j_size) // doselat
{
    if (!ofst.is_open())
    {
        cout << "error! couldnt write in file!";
        return (1);
    }

    for (int i = 0; i != i_size; i++)
    {
        for (int j = 0; j != j_size; j++)
        {
            ofst << matrix[i][j] << " ";
        }
        ofst << "\n";
    }

    cout << "matrix succesfully writen in file!";
    return 0;
}

int main(int argc, char *argv[])
{
    int n = 4;
    ofstream write_prost("sev_task_prost.txt");
    ofstream write_zeydel("sev_task_zeyd.txt");

    double accuracy = 1e-5;

    double *col = make_col(n);
    double **matrix_of_koef = make_koef_matrix(n, n);
    double *solution_1 = method_prostix_iter(matrix_of_koef, col, n, n, accuracy);
    double *solution_2 = method_zeydel(matrix_of_koef, col, n, n);
    return 0;
}