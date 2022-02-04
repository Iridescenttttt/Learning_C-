#include<iostream>
using namespace std;

int Add(int a, int b)
{
    return a + b;
}

float Add(float a, float b)
{
    return a + b;
}

int main()
{
    int a = 1, b = 2;
    float c = 3.0, d = 4.5;
    cout<<Add(a, b)<<endl;
    cout<<Add(c, d)<<endl;
    return 0;
}