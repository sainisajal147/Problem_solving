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

bool isvalid(string s)
{
	string n="";
	for(int i=0;i<s.size();i++)
	{
		if(s[i]!='.')
			n+=s[i];
		else
		{
			int x=stoi(n);
			if(x<0 or x>255 or n[0]=='0')
				return false;
			n.clear();
		}
	}
	int x=stoi(n);
	if(x<0 or x>255 or n[0]=='0')
		return false;
	return true;
}

void diff_ip_add(string &s,int start,vector<string> &ans)
{
	static int dots=0;
	if(dots==3)
	{
		if(isvalid(s))
			ans.push_back(s);
		return;
	}
	for(int i=start;i<s.size();i++)
	{
		if(i==0)
			continue;
		if(i>0 and s[i-1]=='.')
			continue;
		dots++;
		s.insert(s.begin()+i,'.');
		diff_ip_add(s,i+1,ans);
		s.erase(s.begin()+i);
		dots--;
	}
}

vector<string> restoreIpAddresses(string A) {
	vector<string> ans;
	diff_ip_add(A,0,ans);
	return ans;
}

int main(void) {
	string A="25025511135";
	disp(restoreIpAddresses(A));
	//A.insert(A.begin()+3,'.');
	//cout<<A<<endl;
	return 0;
}