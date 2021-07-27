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

void disp(stack<char> s)
{
	while(!s.empty())
	{
		cout<<s.top()<<" ";
		s.pop();
	}
	cout<<"stack ended"<<endl;
}

int braces(string A) {
    stack<char> s;
    for(int i=0;i<A.size();i++)
    {
    	if(A[i]==')' and s.top()!='(')
        {
        	while(!s.empty() and A[i]==')' and s.top()!='(')
            	s.pop();
        	if(!s.empty() and A[i]==')' and s.top()=='(')
            	s.pop();
        }
        else
        {
        	s.push(A[i]);
        	cout<<A[i]<<" pushed\n";
        }
    }
    disp(s);
    if(!s.empty())
    {
        while(!s.empty())
        {
            if(s.top()=='(' or s.top()==')')
                return 1;
            s.pop();
        }
        return 0;
    }
    return 0;
}

int main(void) {
	cout<<braces("()a+(a+b)");
	return 0;
}