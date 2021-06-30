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

bool vaild_para(string s)
{
	stack<char> st;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='(')
			st.push(s[i]);
		else if(!st.empty())
		{
			if(st.top()=='(')
				st.pop();
		}
	}
	if(st.empty())
		return true;
	else
		return false;
}

void combination(string s,int i, vector<string> &ans)
{
	static map<string,int> m;
	static string temp_s="";
	static vector<int> h(1000,0);
	if(i==s.size())
	{
		if(vaild_para(temp_s) and m[temp_s]==0)
		{
			ans.push_back(temp_s);
			m[temp_s]=1;
		}
		return;
	}
	for(int j=0;j<s.size();j++)
	{
		if(h[j]==0)
		{
			h[j]=1;
			temp_s+=s[j];
			combination(s,i+1,ans);
			temp_s.pop_back();
			h[j]=0;
		}
	}
}

vector<string> generateParenthesis(int n) {
string s="";
for(int i=0;i<n;i++)
{
	s+="()";
}
vector<string> ans;
combination(s,0,ans);
return ans;        
}

int main(void) {
	//cout<<vaild_para("(()))(");
	//combination("abc",0);
	disp(generateParenthesis(6));
	return 0;
}