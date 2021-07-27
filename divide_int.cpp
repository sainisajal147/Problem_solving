/*
AUTHOR : SAJAL SAINI
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

template <class t>
void disp(vector<vector<t>> v)
{
	for(int i=0;i<v.size();i++)
	{
		for(int j=0;j<v[i].size();j++)
		{
			cout<<v[i][j]<<" ";
		}
		cout<<endl;
	}
}

template <class t>
void disp(vector<t> v)
{
	for(int i=0;i<v.size();i++)
	{
		cout<<v[i]<<" ";
	}
	cout<<endl;
}

int divide(int A, int B) {
    long long int c=A,d=B,ans=0;
    if(c>INT_MAX or c<INT_MIN)
            return INT_MAX;
    if(d==1)
    {
     	return A;
    }
    if(d==-1 and A<0)
    {
        return abs(c);
    }
    c=abs(A),d=abs(B);
    if(c-d<0)
        return 0;
    while(c-d>0)
    {
        ans++;
        c=c-d;
    }
    if(ans>INT_MAX)
        return INT_MAX;
    if(A<0 and B<0)
        return ans;
    if(A<0 or B<0)
        return -1*ans;
    return ans;
}


int main(void) {
	//int A=-2147483648;
	//ll c=A;
	//cout<<(1^10^3^5)<<endl;
	//cout<<(1^10^5^3^3^10^10^3^1^1);
	vector<int> A={1, 2, 4, 3, 3, 2, 2, 3, 1, 1};
	int ans=0;
	for(int i=31;i>=0;i--)
	{
		int temp=0,x=1;
		for(int j=0;j<A.size();j++)
		{
			if(A[j]&(x<<i))
				temp++;
		}
		ans+=pow(2,i)*(temp%3);
	}
	cout<<ans<<endl;
	//cout<<divide(-2147483648,-1);
	return 0;
}