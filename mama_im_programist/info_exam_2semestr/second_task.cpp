#include <iostream>
using std::cin;
using std::cout;
struct Point
{
  float  position_x;
  float position_y;
  Point (float x): position_x(x) {}
};

void get_position (Point x)
{
    if(x.position_x < -2) {x.position_y = 0;
    cout << "x is:" << x.position_x << "y is: " << x.position_y;
    }
    else if (x.position_x>=-2 && x.position_x <=-1)
    {
        x.position_y = -x.position_x - 2;
        cout << "x is:" << x.position_x << "y is: " << x.position_y;
    }
    else if (x.position_x>-1 && x.position_x <=1)
    {
        x.position_y = x.position_x;
        cout << "x is:" << x.position_x << "y is: " << x.position_y;
    }
    else if (x.position_x>1 && x.position_x <= 2)
    {
        x.position_y = -x.position_x + 2;
        cout << "x is:" << x.position_x << "y is: " << x.position_y;
    }
    else if (x.position_x>2)
    {
        x.position_y = 0;
        cout << "x is:" << x.position_x << "y is: " << x.position_y;
    }
}

int main(int argc, char* argv [])
{
    float x, wait;
    cin>> x;
    Point one(x);
    get_position(one);
    cin >> wait;
    return 0;
}