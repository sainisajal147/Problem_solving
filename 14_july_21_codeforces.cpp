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


bool check(string s)
{
	ll zeros=0,ones=1;
	for(ll i=0;i<s.size();i++)
	{
		if(s[i]=='0')
			zeros++;
		else
			ones++;
	}
	return zeros<ones;
}
 
int main(void) {
	ll t;
	cin>>t;
	while(t--)
	{
		ll n,a,b;
		cin>>n>>a>>b;
		string s;
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
		getline(cin,s);
		char ch='1';
		if(check(s))
			ch='0';
		ll count=0;
		for(int i=1;i<s.size();i++)
		{
			if(s[i]!=s[i-1])
			{
				
			}
		}
		//cout<<count<<endl;
		cout<<max(a*n+b*n,a*n+b*(count+1))<<endl;
	}
	return 0;
}