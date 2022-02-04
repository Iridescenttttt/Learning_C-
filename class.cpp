#include<iostream>
using namespace std;

class Date{
    int y, m, d;
public:
    Date(int yy = 0, int mm = 0, int dd = 0):y(yy), m(mm), d(dd){}
    Date(const Date& in):y(in.y), m(in.m), d(in.d){}
    ~Date(){} 
};