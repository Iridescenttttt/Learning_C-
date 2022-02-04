#include<iostream>
#include<stack>
using namespace std;

int main()
{
    stack<int> s;                                              //标明栈的类型
    for(int i = 0; i < 5; i++){
        int n;
        cin>>n;
        s.push(n);                                             //进栈
    }
    cout<<s.size()<<endl;                                      //栈的长度                     
    for(int i = 0; i < 5; i++){
        cout<<s.top()<<" ";                                    //获取栈顶元素
        s.pop();                                               //出栈
    }
    cout<<boolalpha<<s.empty()<<endl;                          //栈空返回真
    return 0;
}