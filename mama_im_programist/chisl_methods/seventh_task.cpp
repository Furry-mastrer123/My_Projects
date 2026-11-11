#include <cmath>
#include <fstream>
#include <iostream>
using namespace std;

double max_diff(double* vec_1, double* vec_2, int arr_num) {
  double max_diff = 0;
  for (int i = 0; i != arr_num; i++) {
    if (fabs(vec_1[i] - vec_2[i]) > max_diff)
      max_diff = fabs(vec_1[i] - vec_2[i]);
  }
  return max_diff;
}

double* method_prostix_iter(double** matrix, double* colomn, int arr_num,
                            int col_num, double accuracy) {
  double* vec_prev = new double[col_num];  // previous solition vector
  for (int i = 0; i != col_num; i++) {
    vec_prev[i] = 0;
  }

  double* vec_act = new double[arr_num];  // actual solution vector
  for (int i = 0; i != col_num; i++) {
    vec_act[i] = 0;
  }

  double** matrix_koeff = new double*[arr_num];  // kopirovaniye matrici
  {
    for (int i = 0; i != arr_num; i++) {
      matrix_koeff[i] = new double[col_num]();
    }
    for (int i = 0; i != arr_num; i++) {
      for (int j = 0; j != col_num; j++) {
        matrix_koeff[i][j] = matrix[i][j];
      }
    }
  }

  double* free_vec = new double[arr_num]();  // copy colomn
  for (int i = 0; i != arr_num; i++) {
    free_vec[i] = colomn[i];
  }

  for (int i = 0; i != arr_num; i++)  // privedeniye r nuzhnomu vidu
  {
    double pivot = matrix_koeff[i][i];
    for (int j = 0; j != col_num; j++) {
      if (i == j) {
        matrix_koeff[i][j] = 0;
      } else {
        matrix_koeff[i][j] = -1 * matrix_koeff[i][j] / pivot;
      }
    }
    free_vec[i] = free_vec[i] / pivot;
  }
  int iter = 0;
  do  // method itself
  {
    if (iter >= 1000) break;
    for (int i = 0; i != arr_num; i++) {
      vec_act[i] = 0;
      for (int j = 0; j != col_num; j++) {
        vec_act[i] += vec_prev[j] * matrix_koeff[i][j];
      }
      vec_act[i] += free_vec[i];
    }

    double cur_diff = max_diff(vec_act, vec_prev, arr_num);
    if (fabs(cur_diff) < accuracy) break;

    for (int i = 0; i != arr_num; i++) {
      vec_prev[i] = vec_act[i];
    }
    iter++;
  } while (true);

  for (int i = 0; i != arr_num; i++) {
    delete[] matrix_koeff[i];
  }
  delete[] matrix_koeff;
  delete[] vec_act;
  delete[] free_vec;

  return vec_prev;
}

// 100 symbols is about 5 symbols less than next string
double* method_zeydel(double** matrix, double* colomn, int arr_num, int col_num,
                      double accuracy)  // dodelat
{
  int iter = 0;
  double* vec_prev = new double[col_num];  // previous solition vector
  for (int i = 0; i != col_num; i++) {
    vec_prev[i] = 0;
  }

  double* vec_act = new double[arr_num];  // actual solution vector
  for (int i = 0; i != col_num; i++) {
    vec_act[i] = 0;
  }

  double** matrix_koeff = new double*[arr_num];  // kopirovaniye matrici
  {
    for (int i = 0; i != arr_num; i++) {
      matrix_koeff[i] = new double[col_num]();
    }
    for (int i = 0; i != arr_num; i++) {
      for (int j = 0; j != col_num; j++) {
        matrix_koeff[i][j] = matrix[i][j];
      }
    }
  }

  double* free_vec = new double[arr_num]();  // copy colomn
  for (int i = 0; i != arr_num; i++) {
    free_vec[i] = colomn[i];
  }

  for (int i = 0; i != arr_num; i++)  // privedeniye r nuzhnomu vidu
  {
    double pivot = matrix_koeff[i][i];
    for (int j = 0; j != col_num; j++) {
      if (i == j) {
        matrix_koeff[i][j] = 0;
      } else {
        matrix_koeff[i][j] = -1 * matrix_koeff[i][j] / pivot;
      }
    }
    free_vec[i] = free_vec[i] / pivot;
  }

  for (int i = 0; i != arr_num; i++) {
    vec_prev[i] = free_vec[i];
  }

  do  // method itself
  {
    if (iter >= 1000) break;
    for (int i = 0; i != arr_num; i++) {
      vec_act[i] = free_vec[i];
      for (int j = 0; j != col_num; j++) {
        if (i == 0) {
          vec_act[i] += vec_prev[j] * matrix_koeff[i][j];
        }
        if (i > 0) {
          if (j < i) {
            vec_act[i] += vec_act[j] * matrix_koeff[i][j];
          } else if (j > i) {
            vec_act[i] += vec_prev[j] * matrix_koeff[i][j];
          }
        }
      }
    }
    double cur_diff = max_diff(vec_act, vec_prev, arr_num);
    if (fabs(cur_diff) < accuracy) break;
    for (int i = 0; i != arr_num; i++) {
      vec_prev[i] = vec_act[i];
    }
    iter++;
  } while (true);

  for (int i = 0; i != arr_num; i++) {
    delete[] matrix_koeff[i];
  }
  delete[] matrix_koeff;
  delete[] vec_act;
  delete[] free_vec;

  return vec_prev;
}

double** make_koef_matrix(int arr_num, int col_num) {
  double** matrix = new double*[arr_num];
  for (int i = 0; i != arr_num; i++) {
    matrix[i] = new double[col_num];
  }

  for (int i = 0; i != arr_num; i++) {
    for (int j = 0; j != col_num; j++) {
      if (i == j) {
        matrix[i][j] = 5 + log((i + 1) + (j + 1));
      } else {
        matrix[i][j] = log((i + 1) + (j + 1));
      }
    }
  }
  return matrix;
}

double* make_col(int arr_num) {
  double* col = new double[arr_num];
  for (int i = 0; i != arr_num; i++) {
    col[i] = i + 1;
  }
  return col;
}

inline double norma_calc(double* matrix[], int arr_num, int col_num) {
  double* arr = new double[col_num]();  // skobki -> znach po umolchaniyu

  for (int j = 0; j != col_num; j++) {
    for (int i = 0; i != arr_num; i++) {
      arr[j] += fabs(matrix[i][j]);
    }
  }

  double res = 0;
  for (int i = 0; i != col_num; i++) {
    if (res < arr[i]) res = arr[i];
  }
  delete[] arr;
  return res;
}

inline int write_in_file(ofstream& ofst, double* vec, int i_size)  // doselat
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
  int n = 4;
  ofstream write_prost("sev_task_prost.txt");
  ofstream write_zeydel("sev_task_zeyd.txt");

  double accuracy = 1e-5;

  double* col = make_col(n);
  double** matrix_of_koef = make_koef_matrix(n, n);
  double* solution_1 = method_prostix_iter(matrix_of_koef, col, n, n, accuracy);
  double* solution_2 = method_zeydel(matrix_of_koef, col, n, n, accuracy);

  write_in_file(write_prost, solution_1, n);
  write_in_file(write_zeydel, solution_2, n);

  delete[] col;
  for (int i = 0; i != n; i++) {
    delete[] matrix_of_koef[i];
  }
  delete[] matrix_of_koef;
  delete[] solution_1;
  delete[] solution_2;
  return 0;
}