#include<iostream>
#include<queue>
using namespace std;

struct Test{
    int x;
    Test(int xx):x(xx){}
    bool operator< (const Test& t)
    {
        return x < t.x;
    }
};

struct cmp{
    bool operator() (Test a, Test b)
    {
        return a.x < b.x;
    }
};

int main()
{
    priority_queue<int> a;                              //默认为降序，即大顶堆
    // priority_queue<int, vector<int>, less<int>> a;
    priority_queue<int, vector<int>, greater<int>> b;
    for(int i = 0; i < 10; i++){
        a.push(i);
        b.push(i);
    }
    while(!a.empty()){
        cout<<a.top()<<" ";
        a.pop();
    }
    cout<<endl;
    while(!b.empty()){
        cout<<b.top()<<" ";
        b.pop();
    }
    cout<<endl;
    priority_queue<pair<int, int>> c;               //pair先比较第一个，第一个相同比较第二个
    c.push(pair<int, int>(1, 5));
    c.push(pair<int, int>(2, 3));
    c.push(pair<int, int>(1, 2));   
    while(!c.empty()){
        pair<int, int> p = c.top();
        cout<<p.first<<" "<<p.second<<endl;
        c.pop();
    }
    //自定义类型的比较
    Test t1(1);
    Test t2(2);
    Test t3(3);
    priority_queue<Test> t;                         //方法一：在结构体中重载<操作符
    t.push(t1);
    t.push(t2);
    t.push(t3);
    while(!t.empty()){
        auto n = t.top();
        cout<<n.x<<endl;
    }
    priority_queue<Test, vector<Test>, cmp> tt;     //方法二：重写仿函数
    return 0;
}