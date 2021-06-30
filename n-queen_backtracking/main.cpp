#include <iostream>
#include<string>
#include<vector>
using namespace std;
void comb(string s,int l, int h)
{
    if(l==h)
    {
        cout<<s<<endl;
    }
    else
    {
        for(int i=l;i<=h;i++)
        {
            swap(s[l],s[i]);
            comb(s,l+1,h);
            swap(s[l],s[i]);
        }
    }
}
int main()
{
    string s="ABC";
    comb(s,0,s.size()-1);
    return 0;
}
