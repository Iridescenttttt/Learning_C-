[TOC]

## 引用
1. 声明一个引用时，一定要初始化

2. 不能对引用进行第二次修改


## 函数重载

1. 名字相同，参数类型或个数不同
```c++
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

/*
3
7.5
*/
```


## 类
1. 成员函数在类之外定义的常规方式：<返回值类型> <类名>::<函数名>(参数列表){}
1. 内联成员函数：no loop, no switch
1. 构造函数
1. 拷贝构造函数：形参必须是引用，如果不是引用，参数传递时也会调用拷贝构造函数，形成死循环
1. 拷贝构造函数与赋值函数的区别：赋值函数通过运算符重载实现
1. 析构函数
1. 静态变量和静态成员函数

```c++
#include<iostream>
using namespace std;

class Date{
    int y, m, d;
public:
    Date(int yy = 0, int mm = 0, int dd = 0):y(yy), m(mm), d(dd){}
    Date(const Date& in):y(in.y), m(in.m), d(in.d){}
    ~Date(){} 
};
```

## Stack
```c++
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
```

## Queue
```c++
#include <iostream>
#include<queue>
using namespace std;

int main()
{
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    cout<<q.size()<<endl;                           //队列中元素个数    
    q.pop();                                        //第一个元素出队
    cout<<boolalpha<<q.empty()<<endl;               //若为空，返回true
    cout<<q.front()<<endl;                          //返回第一个元素
    cout<<q.back()<<endl;                           //返回最后一个元素
    return 0;
}
```

## priority_queue
1. 优先队列具有队列的所有性质，但出队顺序并不是入队顺序，而是内部的优先级，本质通过堆实现
2. 定义：priority_queue<Type, Container, Functional>
3. 只要掌握自定义结构的比较方法，其他与队列相同
```c++
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
```

## stringstream
头文件：sstream

## set
set作为一个容器也是用来存储同一数据类型的数据类型，系统能根据元素的值自动进行排序，所以用set存储的数据类型一定要定义小于运算
1. set中的元素都是排好序的
2. set集合中没有重复元素
```c++
#include<iostream>
#include<set>
using namespace std;

int main()
{
    set<int> s;
    s.insert(1);                                    //insert：插入元素
    s.insert(2);
    cout<<s.size()<<endl;                           //size：当前集合大小
    s.insert(3);
    s.insert(2);
    cout<<s.count(2)<<endl;                         //有序，无重复，所以count返回值只能为0或1
    cout<<s.max_size()<<endl;                       //max_size：可存储的最大元素个数
    // cout<<s.begin()<<endl;
    cout<<*(s.begin())<<endl;                       //begin：返回集合第一个元素的指针
    cout<<*(s.end())<<endl;                         //end：最后一个元素的指针
    cout<<boolalpha<<s.empty()<<endl;               //empty：判断是否为空
    auto it = s.find(2);                            //找元素返回指针
    cout<<*it<<endl;
    for(set<int>::iterator it = s.begin(); it != s.end(); it++){
        // *it = 100;                               //set值不可以修改！！！
        cout<<*it<<" ";
    }
    cout<<endl;
    // s.erase(s.begin());                          //删除定位器指向的值
    // s.erase(s.begin(), s.end());                 //删除first到second的值
    // s.erase(2);                                  //删除key
    cout<<s.size()<<endl;
    s.clear();                                      //清空
    cout<<s.empty()<<endl;
    return 0;
}
```

## map
map是STL的一个关联容器，它提供一对一的hash。
第一个可以称为关键字(key)，每个关键字只能在map中出现一次；
第二个可能称为该关键字的值(value)；
```c++
#include<iostream>
#include<map>
using namespace std;

int main()
{
    map<int, string> mapstudent;
    mapstudent.insert(pair<int, string>(0, "student zero"));     //通过insert函数插入键值对
    mapstudent[1] = "student one";                               //通过[]（类似于数组下标的方式）
    /*
    注意两种方式的区别，insert会检查键是否重复，不重复则插入
    而[]则会覆盖原来的值（若存在）
    */
    mapstudent.insert(pair<int, string>(1, "student"));
    mapstudent[1] = "student";
    auto it = mapstudent.find(1);                               //寻找元素，返回迭代器
    cout<<it->first<<" "<<it->second<<endl;                     //用first和second分别表示键和值
    mapstudent.erase(it);                                       //erase删除
    mapstudent.erase(1);                                        //也可以直接通过键删除
    cout<<mapstudent.size()<<endl;                             
    return 0;
}
```