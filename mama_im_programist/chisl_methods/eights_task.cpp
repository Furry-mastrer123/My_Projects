#include <cmath>
#include <fstream>
#include <functional>
#include <iostream>

using std::cout, std::cin, std::cerr;

inline double** method_jordan_gauss(double** matrix, int arr_num, int col_num) {
  if (col_num == 0) {
    cout << "error! there is no arrays and colomns in matrix!";
    return nullptr;
  }

  double** matrix_b = new double*[col_num];
  for (int i = 0; i != arr_num;
       i++)  // kopiruem matricu i dopolnyaem sprava edinichnoy
  {
    matrix_b[i] = new double[col_num + col_num]();
    for (int j = 0; j != col_num + col_num; j++) {
      if (j >= col_num)
        matrix_b[i][j] = (j - col_num == i) ? 1 : 0;
      else
        matrix_b[i][j] = matrix[i][j];
    }
  }

  for (int i = 0; i != arr_num - 1; i++)  // privedeniye k verhnetreug vidu
  {
    int max_diag_el = i;
    for (int t = i; t != arr_num; t++)  // poisk max diad elementa
    {
      if (fabs(matrix_b[t][i]) > fabs(matrix_b[max_diag_el][i])) {
        max_diag_el = t;
      }
    }

    if (max_diag_el != i)  // menyaem stroki mestami
    {
      double* pivot = matrix_b[i];
      matrix_b[i] = matrix_b[max_diag_el];
      matrix_b[max_diag_el] = pivot;
    }

    double pivot_1 = matrix_b[i][i];

    for (int j = 0; j != col_num * 2;
         j++)  // privodim perbuyu stroku k a_11 = 1, a_12 = a_12/pivot ...
    {
      matrix_b[i][j] = matrix_b[i][j] / pivot_1;
    }

    for (int j = i + 1; j != arr_num; j++) {
      double pivot_2 = matrix_b[j][i];
      for (int k = 0; k != col_num * 2; k++) {
        matrix_b[j][k] = matrix_b[j][k] - matrix_b[i][k] * pivot_2;
      }
    }
  }

  for (int i = 1; i != arr_num;
       i++)  // privedeniye ishodnoy k edinichnoy matrice
  {
    double pivot_1 = matrix_b[arr_num - i][arr_num - i];  // velichina a_nn
    for (int j = arr_num - i; j != col_num * 2;
         j++)  // privedeniye k vidu a_nn = 1
    {
      matrix_b[arr_num - i][j] = matrix_b[arr_num - i][j] / pivot_1;
    }

    for (int j = 0; j != arr_num - i;
         j++)  // udaleniye elementov nad privedennim
    {
      double pivot_2 = matrix_b[j][col_num - i];
      for (int k = 0; k != 2 * col_num; k++) {
        matrix_b[j][k] = matrix_b[j][k] - matrix_b[arr_num - i][k] * pivot_2;
      }
    }
  }

  double** backward_matrix = new double*[arr_num]();  // sozdaniye backward
  for (int i = 0; i != col_num; i++) {
    backward_matrix[i] = new double[col_num]();
  }

  for (int i = 0; i != arr_num; i++)  // zapolneniye backward
  {
    for (int j = 0; j != col_num; j++) {
      backward_matrix[i][j] = matrix_b[i][col_num + j];
    }
  }

  for (int i = 0; i != arr_num; i++) {
    delete[] matrix_b[i];
  }
  delete[] matrix_b;

  return backward_matrix;
}

inline double** multiplication(double** matrix_a, int mat_a_arr_num,
                               int mat_a_col_num, double** matrix_b,
                               int mat_b_arr_num, int mat_b_col_num) {
  if (mat_a_col_num != mat_b_arr_num) {
    cerr << "error! matrixes are cannot be multiplicated!";
    return nullptr;
  }

  double** result = new double*[mat_a_arr_num];
  for (int i = 0; i != mat_a_arr_num; i++) {
    result[i] = new double[mat_b_col_num]();
  }

  for (int i = 0; i != mat_a_arr_num; i++) {
    for (int j = 0; j != mat_b_col_num; j++) {
      double add_ij = 0;
      for (int k = 0; k != mat_a_col_num; k++) {
        add_ij += matrix_a[i][k] * matrix_b[k][j];
      }
      result[i][j] = add_ij;
    }
  }

  return result;
}

double* diff_vec(double** matrix, double* vec) {
  double* vector = new double[2]();
  vector[0] = vec[0] - matrix[0][0];
  vector[1] = vec[1] - matrix[1][0];
  return vector;
}

double F_func(double x, double y) { return y - 3 * sin(x * y); }

double G_func(double x, double y) {
  return pow(x + 0.5, 2) + pow((y - 0.25), 2) - 3;
}

double devirative_x(std::function<double(double, double)> func, double x,
                    double y) {
  double res = 0;
  double h = 1e-6;  // shag
  res = (func(x + h, y) - func(x - h, y)) / (2 * h);
  return res;
}

double devirative_y(std::function<double(double, double)> func, double x,
                    double y) {
  double res = 0;
  double h = 1e-6;  // shag
  res = (func(x, y + h) - func(x, y - h)) / (2 * h);
  return res;
}

double** jacobian_matrix(std::function<double(double, double)> func,
                         std::function<double(double, double)> gunc,
                         double* vec) {
  double** matrix = new double*[2];
  for (int i = 0; i != 2; i++) {
    matrix[i] = new double[2];
  }
  matrix[0][0] = devirative_x(func, vec[0], vec[1]);
  matrix[0][1] = devirative_y(func, vec[0], vec[1]);
  matrix[1][0] = devirative_x(gunc, vec[0], vec[1]);
  matrix[1][1] = devirative_y(gunc, vec[0], vec[1]);
  return matrix;
}

inline double** make_func_matrix(std::function<double(double, double)> func,
                                 std::function<double(double, double)> gunc,
                                 double* vec) {  // dodelat
  double** matrix = new double*[2];
  matrix[0] = new double[1];
  matrix[1] = new double[1];
  matrix[0][0] = func(vec[0], vec[1]);
  matrix[1][0] = gunc(vec[0], vec[1]);
  return matrix;
}

double* copy_vec(double* vec, int arr_count) {
  double* vector = new double[arr_count]();
  for (int i = 0; i != arr_count; i++) {
    vector[i] = vec[i];
  }
  return vector;
}

bool accuracy_check(double* vec_prev, double* vec_next, double accuracy) {
  return fabs(vec_next[0] - vec_prev[0]) <= accuracy &&
         fabs(vec_next[1] - vec_prev[1]) <= accuracy;
}

double* nonlinear_sol(std::function<double(double, double)> func,
                      std::function<double(double, double)> gunc,
                      double* vec_pribl, double accuracy) {
  double* vec_next = new double[2]();
  double* vec_prev = copy_vec(vec_pribl, 2);
  int max_iter = 1000;
  int iter_act = 0;
  do {
    if (iter_act >= max_iter) {
      cerr << "iter_num is too big!";
      break;
    } else {
      iter_act++;
    }
    if (iter_act >= 1 && accuracy_check(vec_prev, vec_next, accuracy)) {
      break;
    }

    auto matrix_1 =
        method_jordan_gauss(jacobian_matrix(func, gunc, vec_prev), 2, 2);
    auto matrix_2 = make_func_matrix(func, gunc, vec_prev);
    auto matrix_3 = multiplication(matrix_1, 2, 2, matrix_2, 2, 1);
    vec_next = diff_vec(matrix_3, vec_prev);
    for (int i = 0; i != 2; i++) {
      delete[] matrix_1[i];
      delete[] matrix_2[i];
      delete[] matrix_3[i];
    }
    delete[] matrix_1;
    delete[] matrix_2;
    delete[] matrix_3;
    delete[] vec_prev;
    vec_prev = copy_vec(vec_next, 2);
  } while (true);
  return vec_next;
}

inline int write_in_file(std::ofstream& ofst, double* vec,
                         int i_size)  // doselat
{
  if (!ofst.is_open()) {
    cout << "error! couldnt write in file!";
    return (1);
  }

  for (int i = 0; i != i_size; i++) {
    ofst << vec[i];
    ofst << "\n";
  }

  cout << "matrix succesfully writen in file!";
  return 0;
}

int main(int argc, char* argv[]) {
  std::ofstream vec_1_file("8_task_vec_1.txt");
  std::ofstream vec_2_file("8_task_vec_2.txt");
  std::ofstream vec_3_file("8_task_vec_3.txt");
  std::ofstream vec_4_file("8_task_vec_4.txt");
  if (!vec_1_file.is_open() | !vec_2_file.is_open() | !vec_3_file.is_open() |
      !vec_4_file.is_open()) {
    cerr << "couldn`t open file!";
    return 1;
  }
  double* vec_1 = new double[2]();
  double* vec_2 = new double[2]();
  double* vec_3 = new double[2]();
  double* vec_4 = new double[2]();
  vec_1[0] = 0;
  vec_1[1] = 2;

  vec_2[0] = 1;
  vec_2[1] = 0;

  vec_3[0] = -2;
  vec_3[1] = 0;

  vec_4[0] = 0;
  vec_4[1] = -2;

  double accuracy = 1e-7;

  vec_1 = nonlinear_sol(F_func, G_func, vec_1, accuracy);
  vec_2 = nonlinear_sol(F_func, G_func, vec_2, accuracy);
  vec_3 = nonlinear_sol(F_func, G_func, vec_3, accuracy);
  vec_4 = nonlinear_sol(F_func, G_func, vec_4, accuracy);

  cout << write_in_file(vec_1_file, vec_1, 2) << std::endl;
  cout << write_in_file(vec_2_file, vec_2, 2) << std::endl;
  cout << write_in_file(vec_3_file, vec_3, 2) << std::endl;
  cout << write_in_file(vec_4_file, vec_4, 2) << std::endl;
  int i = 0;
  cin >> i;
  delete[] vec_1;
  delete[] vec_2;
  delete[] vec_3;
  delete[] vec_4;
  return 0;
}