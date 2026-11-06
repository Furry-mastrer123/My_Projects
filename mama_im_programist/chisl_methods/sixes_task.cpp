#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>

using namespace std;

inline double determinant(double **matrix, int arr_num, int col_num)
{
    double res = 0;

    if (arr_num != col_num)
    {
        cout << "error, number of collomns and arrays are not equal!";
        return 0;
    }
    if (col_num == 1)
        return matrix[0][0];

    double **matrix_b = new double *[col_num];
    for (int i = 0; i != arr_num; i++)
    {
        matrix_b[i] = new double[col_num]();
        for (int j = 0; j != col_num; j++)
        {
            matrix_b[i][j] = matrix[i][j];
        }
    }

    int max_diag_el = 0;
    for (int i = 0; i != col_num; i++)
    {
        if (fabs(matrix_b[i][0]) > fabs(matrix_b[max_diag_el][0]))
            max_diag_el = i;
    }

    if (max_diag_el != 0)
    {
        double *pivot = matrix_b[0];
        matrix_b[0] = matrix_b[max_diag_el];
        matrix_b[max_diag_el] = pivot;
    }

    double pivot_el = matrix_b[0][0];
    for (int i = 0; i != col_num; i++)
    {
        matrix_b[0][i] = matrix_b[0][i] / pivot_el;
    }

    for (int i = 1; i != arr_num; i++)
    {
        double pivot_3 = matrix_b[i][0];
        for (int j = 0; j != col_num; j++)
        {
            matrix_b[i][j] = matrix_b[i][j] - matrix_b[0][j] * pivot_3;
        }
    }

    double **matrix_c = new double *[arr_num - 1];
    for (int i = 0; i != arr_num - 1; i++)
    {
        matrix_c[i] = new double[col_num - 1]();
    }

    for (int i = 1; i != arr_num; i++)
    {
        for (int j = 1; j != col_num; j++)
        {
            matrix_c[i - 1][j - 1] = matrix_b[i][j];
        }
    }

    if (max_diag_el != 0)
    {
        res = -pivot_el;
    }
    else
    {
        res = pivot_el;
    }

    res *= determinant(matrix_c, arr_num - 1, col_num - 1);

    for (int i = 0; i != arr_num; i++)
    {
        delete[] matrix_b[i];
    }
    delete[] matrix_b;

    for (int i = 0; i != arr_num - 1; i++)
    {
        delete[] matrix_c[i];
    }
    delete[] matrix_c;

    return res;
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

inline double **method_jordan_gauss(double **matrix, int arr_num, int col_num)
{
    if (col_num == 0)
    {
        cout << "error! there is no arrays and colomns in matrix!";
        return nullptr;
    }

    double **matrix_b = new double *[col_num];
    for (int i = 0; i != arr_num; i++) // kopiruem matricu i dopolnyaem sprava edinichnoy
    {
        matrix_b[i] = new double[col_num + col_num]();
        for (int j = 0; j != col_num + col_num; j++)
        {
            if (j >= col_num)
                matrix_b[i][j] = (j - col_num == i) ? 1 : 0;
            else
                matrix_b[i][j] = matrix[i][j];
        }
    }

    for (int i = 0; i != arr_num - 1; i++) // privedeniye k verhnetreug vidu
    {
        int max_diag_el = i;
        for (int t = i; t != arr_num; t++) // poisk max diad elementa
        {
            if (fabs(matrix_b[t][i]) > fabs(matrix_b[max_diag_el][i]))
            {
                max_diag_el = t;
            }
        }

        if (max_diag_el != i) // menyaem stroki mestami
        {
            double *pivot = matrix_b[i];
            matrix_b[i] = matrix_b[max_diag_el];
            matrix_b[max_diag_el] = pivot;
        }

        double pivot_1 = matrix_b[i][i];

        for (int j = 0; j != col_num * 2; j++) // privodim perbuyu stroku k a_11 = 1, a_12 = a_12/pivot ...
        {
            matrix_b[i][j] = matrix_b[i][j] / pivot_1;
        }

        for (int j = i + 1; j != arr_num; j++)
        {
            double pivot_2 = matrix_b[j][i];
            for (int k = 0; k != col_num * 2; k++)
            {
                matrix_b[j][k] = matrix_b[j][k] - matrix_b[i][k] * pivot_2;
            }
        }
    }

    for (int i = 1; i != arr_num; i++) // privedeniye ishodnoy k edinichnoy matrice
    {
        double pivot_1 = matrix_b[arr_num - i][arr_num - i]; // velichina a_nn
        for (int j = arr_num - i; j != col_num * 2; j++)     // privedeniye k vidu a_nn = 1
        {
            matrix_b[arr_num - i][j] = matrix_b[arr_num - i][j] / pivot_1;
        }

        for (int j = 0; j != arr_num - i; j++) // udaleniye elementov nad privedennim
        {
            double pivot_2 = matrix_b[j][col_num - i];
            for (int k = 0; k != 2 * col_num; k++)
            {

                matrix_b[j][k] = matrix_b[j][k] - matrix_b[arr_num - i][k] * pivot_2;
            }
        }
    }

    double **backward_matrix = new double *[arr_num](); // sozdaniye backward
    for (int i = 0; i != col_num; i++)
    {
        backward_matrix[i] = new double[col_num]();
    }

    for (int i = 0; i != arr_num; i++) // zapolneniye backward
    {
        for (int j = 0; j != col_num; j++)
        {
            backward_matrix[i][j] = matrix_b[i][col_num + j];
        }
    }

    for (int i = 0; i != arr_num; i++)
    {
        delete[] matrix_b[i];
    }
    delete[] matrix_b;

    return backward_matrix;
}

inline double **multiplication(double **matrix_a, int mat_a_arr_num,
                               int mat_a_col_num, double **matrix_b, int mat_b_arr_num, int mat_b_col_num) // dodelat
{
    if (mat_a_col_num != mat_b_arr_num)
    {
        cerr << "error! matrixes are cannot be multiplicated!";
        return nullptr;
    }

    double **result = new double *[mat_a_arr_num];
    for (int i = 0; i != mat_a_arr_num; i++)
    {
        result[i] = new double[mat_b_col_num]();
    }

    for (int i = 0; i != mat_a_arr_num; i++)
    {
        for (int j = 0; j != mat_b_col_num; j++)
        {
            double add_ij = 0;
            for (int k = 0; k != mat_a_col_num; k++)
            {
                add_ij += matrix_a[i][k] * matrix_b[k][j];
            }
            result[i][j] = add_ij;
        }
    }

    return result;
}

double **matrix(ifstream &fstr, int i_max = 6, int j_max = 6) // 6 po zadaniyu
{
    double **matrix = new double *[i_max]();
    for (int i = 0; i != i_max; i++)
    {
        matrix[i] = new double[j_max]();
    }

    for (int i = 0; i != i_max; i++)
    {
        for (int j = 0; j != j_max; j++)
        {
            fstr >> matrix[i][j];
        }
    }
    return matrix;
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

double cond_number(double *matrix[], int arr_num_1, int colomn_num_1,
                   double *backward_matrix[], int arr_num_2, int colomn_num_2) // chislo obuslov, dodelat
{
    double norma_1 = norma_calc(matrix, arr_num_1, colomn_num_1);
    double norma_2 = norma_calc(backward_matrix, arr_num_2, colomn_num_2);
    return norma_1 * norma_2;
}

int main(int argc, char *argv[])
{
    int n = 6; // razmer
    ifstream read_file("six_task_matrix.txt");
    if (!read_file.is_open())
    {
        cout << "error! Couldnt read from file!";
        return 0;
    }
    double **Matrix_A = matrix(read_file, n, n);

    double det = determinant(Matrix_A, n, n);
    cout << det << endl;
    if (det == 0)
    {
        cout << "opredelitel = o!";
        return 0;
    }

    double **backward_matrix = method_jordan_gauss(Matrix_A, n, n);

    double con_num = cond_number(Matrix_A, n, n, backward_matrix, n, n);
    cout << con_num;

    ofstream write_backward_matrix("six_task_backward_mat.txt");
    if (!write_backward_matrix.is_open())
    {
        cout << "error! filw is not open!";
        return 0;
    }

    ofstream write_multip_matrix("mat_multiplic.txt");
    if (!write_multip_matrix.is_open())
    {
        cout << "error! couldnt open file!";
        return 0;
    }

    double **mult_res = multiplication(Matrix_A, n, n, backward_matrix, n, n);

    write_in_file(write_backward_matrix, backward_matrix, n, n);
    write_in_file(write_multip_matrix, mult_res, n, n);
    int o;
    cin >> o;

    for (int i = 0; i != n; i++)
    {
        delete[] backward_matrix[i];
        delete[] Matrix_A[i];
        delete[] mult_res[i];
    }
    delete backward_matrix;
    delete Matrix_A;
    delete mult_res;

    return 0;
}
