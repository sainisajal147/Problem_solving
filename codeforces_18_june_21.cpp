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

ll solve(vector<ll> ans)
{
	ll a=0;
	for(ll i=1;i<ans.size();i++)
	{
		if(ans[i]>=ans[i-1])
			a++;
	}
	return a;
}

int main(void) {
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		vector<ll> v(n);
		for(int i=0;i<n;i++)
			cin>>v[i];
		sort(v.begin(), v.end());
		ll a1=0,a2=1,an=abs(v[0]-v[1]);
		for(int i=2;i<n;i++)
		{
			if(abs(v[i]-v[i-1])<an)
			{
				a1=i-1,a2=i;
				an=abs(v[i]-v[i-1]);
			}
		}
		vector<ll> ans1,ans2,ans;
		for(int i=0;i<n;i++)
		{
			if(i==a1 or i==a2)
				continue;
			if(v[i]>=v[a1])
				ans1.push_back(v[i]);
			else
				ans2.push_back(v[i]);
		}
		ans2.push_back(v[a2]);
		ans1.insert(ans1.begin(),v[a1]);
		for(int i=0;i<ans1.size();i++)
			ans.push_back(ans1[i]);
		for(int i=0;i<ans2.size();i++)
			ans.push_back(ans2[i]);
		disp(ans);
	}
	return 0;
}