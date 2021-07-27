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

int get_rev(int n)
{
	int x=0;
	while(n!=0)
	{
		int lb=n&1;
		x=x|lb;
		n=n>>1;
		x=x<<1;
	}
	x=x>>1;
	return x;
}

int solve(int A) {
    int count=1;
    int length=1;
    while(count<A)
    {
        length++;
        count=count+(1<<((length-1)/2));
    }
    count-=(1<<((length-1)/2));
    int off=A-count-1;
    int ans=1<<(length-1);
    //cout<<"l= "<<length<<"\ncount= "<<count<<"\n off= "<<off<<endl;
    ans=ans|(off<<(length/2));
    int last=ans>>(length/2);
    int rev=get_rev(last);
    ans=ans|rev;
    /*if(length%2)
    {
        
    }*/
    return ans;
}

int main(void) {
	cout<<solve(9);
	return 0;
}