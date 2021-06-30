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

int main(void) {
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		vector<ll> v(n);
		map<ll,ll> m;
		for(ll i=0;i<n;i++)
		{
			cin>>v[i];
			m[v[i]]=i+1;
		}
		int ans=0;
		for(int j=2;j<=2*n-1;j++)
		{
			for(int i=1;i<=sqrt(j);i++)
			{
				if(j%i==0 and m[i] and m[j/i] and i*i!=j and (m[i]+m[j/i]==j))
					ans++;
			}
			//cout<<endl;
		}
		cout<<ans<<endl;
	}
	return 0;
}