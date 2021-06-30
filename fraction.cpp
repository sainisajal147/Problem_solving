#include <stdio.h>
#include <cmath>
#include <map>
#include <math.h>
#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

typedef long long int ll;
string fractionToDecimal(int A, int B) {
    if(A==0)
        return "0";
    int sign=0;
    if((A<0 and B<0) or (A>0 and B>0))
        sign =1;
    else
        sign =-1;
    ll c=abs(A),d=abs(B);
    ll a=abs(c/d);
    ll rem=c%d;
    string ans=to_string(a);
    if(!ans.empty() and (ans[0]=='+' or ans[0]=='-'))
        ans.erase(ans.begin());
    if(rem==0)
    {
        if(sign==1)
            return ans;
        else
            return '-'+ans;
    }
    ans+='.';
    int z;
    map<ll,int> m;
    while(rem!=0)
    {
        if(m[rem]!=0)
        {
            ans.insert(ans.begin()+m[rem],'(');
            ans+=')';
            break;
        }
        m[rem]=ans.size();
        cout<<rem<<endl;
        rem*=10;
        z=abs(rem/d);
        string x=to_string(rem/d);
        if(!x.empty() and (x[0]=='+' or x[0]=='-'))
            x.erase(x.begin());
        ans+=x;
        rem=rem%d;
        cout<<rem<<endl;
    }
    /*for (; rem; rem %= d)
    {
        if (m.find(rem) != m.end())
        {
            ans.insert(m[rem], 1, '(');
            ans.push_back(')');
            break;
        }
        
        m[rem] = ans.size();
        rem *= 10;
        ans.push_back('0' + rem/d);
    }*/
    //return res;
    if(sign==1)
        return ans;
    else
        return '-'+ans;
}


int main() {
	cout<<fractionToDecimal(87,22);
	return 0;
}