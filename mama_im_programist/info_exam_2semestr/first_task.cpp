#include <iostream>
        //Задано два момента времени в часах, минутах и секундах (в пределах одних суток)...
struct Time 
{
    int hours;
    int minutes;
    int seconds;
    Time(int h, int m, int s): hours(h), minutes(m), seconds(s) {std::cout<< "usual constructor called";}
    Time(): hours(0), minutes(0), seconds(0) {std::cout<< "hole constructor called";}
    Time(const Time  & t): hours(t.hours), minutes(t.minutes), seconds(t.seconds) {std::cout<< "copy constructor called";}
    ~Time() {std::cout<<"object has been deleted";}
    Time operator - (const Time  &  T);
};

Time Time::operator- (const Time &  T)
{
    int t1 = this->hours*3600 + this->minutes*60+this->seconds;
    int t2 = T.hours*3600 + T.minutes*60 +T.seconds;
    int t_result = t2-t1;
    int h = t_result/3600;
    int m = t_result%60;
    int s = t_result % 3600 %60;
    return Time(h,m,s);
}

void view(const Time&  T) {std::cout<<"there's " << T.hours << std::endl<< "hours, " << T.minutes << std::endl << "minutes, and  " << T.seconds << "seconds" << std::endl << "between your time poitns" << std::endl;}

int main(int argc, char* argv[])
{
    Time first_point(10, 12, 10);
    Time second_point(12, 12, 14);
    Time third_point =  second_point - first_point;
    view (third_point);
    int a;
    std::cin >>a;
    return 0;
}