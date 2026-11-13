#include <iostream>
#include <random>
#include <vector>
using std::cout, std::cin, std::endl;
using std::vector;
/// making random x_points
inline vector<double> make_x_vec(int n) {
  std::random_device rd;
  std::uniform_real_distribution<double> distr(0, 1);
  std::mt19937 gen(rd());
  vector<double> x_vec;
  for (int i = 0; i != n; i++) {
    x_vec.push_back(2.0 * distr(gen));
  }
  return x_vec;
}

/// making random y_points
inline vector<double> make_y_vec(int n) {
  std::random_device rd;
  std::uniform_real_distribution<double> distr(0, 1);
  std::mt19937 gen(rd());
  vector<double> y_vec;
  for (int i = 0; i != n; i++) {
    y_vec.push_back(1 + distr(gen));
  }
  return y_vec;
}

/// in my version in problem book (задачник) this thing is useless because my
/// region is already rectangle and all points will be in region, without
/// exseptions
inline bool check_if_point_is_inside(std::pair<double, double> point) {
  bool res = false;
  if (point.first < 2 && point.first > 0 && point.second > 1 &&
      point.second < 2) {
    res = true;
  }
  return res;
}

/// counting z value
inline double count_z(double x, double y) { return x * x + y * y; }

/// counting integral value
inline double count_integral(int N, vector<double> x_vec,
                             vector<double> y_vec) {
  vector<double> z_vec;
  vector<int> n_vec;
  for (int i = 0; i != N; i++) {
    if (check_if_point_is_inside(std::make_pair(x_vec[i], y_vec[i]))) {
      n_vec.push_back(1);
      z_vec.push_back(count_z(x_vec[i], y_vec[i]));
    } else {
      n_vec.push_back(0);
    }
  }
  double z_average = 0;
  for (int i = 0; i != z_vec.size(); i++) {
    z_average += z_vec[i];
  }
  z_average = z_average / z_vec.size();
  int n = 0;
  for (int i = 0; i != N; i++) {
    n += n_vec[i];
  }
  double res = 2 * z_average * (n / N);  // 2 is square of region
  return res;
}

int main(int argc, char* argv[]) {
  int N;
  cout << "please insert n (count of points)" << endl;
  cin >> N;
  vector<double> x_vec = make_x_vec(N);
  vector<double> y_vec = make_y_vec(N);
  double res = count_integral(N, x_vec, y_vec);
  double analys = 7.3333333333;
  cout << "result by numerical method is " << res << endl;
  cout << "result by anylisys ciunting is " << analys << endl;
  cout << "difference between them is " << analys - res << endl;
  int x = 0;
  cin >> x;
  return 0;
}