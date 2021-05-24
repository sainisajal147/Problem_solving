#include <iostream>
#include<vector>
#include<string>
#include<bits/stdc++.h>
using namespace std;

string countAndSay(int A) {
    string s[A];
    s[0]="1";
    for(int i=1;i<A;i++)
    {
        if(i==1)
        {
            s[i]="11";
        }
        else
        {
            int j=1,c=1;
            for(;j<s[i-1].size();j++)
            {
                if(s[i-1][j]==s[i-1][j-1])
                {
                    c++;
                }
                if(j==s[i-1].size()-1 or s[i-1][j]!=s[i-1][j-1])
                {
                    s[i]+=to_string(c)+s[i-1][j-1];
                    c=1;
                }
            }
            if(s[i-1][j-2]!=s[i-1][j-1])
            s[i]+=to_string(c)+s[i-1][j-1];
        }
    }
    return s[A-1];
}

int main()
{
    int n;
    cin>>n;
    cout<<countAndSay(n);
    return 0;
}
