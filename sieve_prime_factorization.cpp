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

void spf(int n)
{
	vector<ll> v(n+1,0);
	for(int i=2;i<=n;i++)
		v[i]=i;
	for(int i=2;i<=n;i++)
	{
		if(v[i]==i)
		{
			for(int j=i*i;j<=n;j+=i)
			{
				v[j]=i;
			}
		}
	}
	while(n!=1)
	{
		cout<<v[n]<<" ";
		n=n/v[n];
	}
	/*for(int i=2;i<=n;i++)
	{
		if(v[i]==0)
			cout<<i<<" ";
	}*/
	cout<<endl;
}

int main(void) {
	ll n;
	cin>>n;
	spf(n);
	return 0;
}