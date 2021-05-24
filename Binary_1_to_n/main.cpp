#include <iostream>
#include<queue>
#include<string>
using namespace std;

int main()
{
    int n=100;
    queue<string> q;
    q.push("1");
    while(n--)
    {
        string a=q.front();
        q.pop();
        cout<<a<<endl;
        string b=a;
        a.push_back('0');
        b.push_back('1');
        q.push(a);
        q.push(b);
    }
    return 0;
}
