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

bool is_palindrome(string s,int l,int h)
{
    while(l<=h)
    {
        if(s[l]!=s[h])
            return false;
        l++;
        h--;
    }
    return true;
}
void partition_string(string s,int start,vector<vector<string>> &ans,vector<string> &temp)
{
    if(start==s.size())
    {
        ans.push_back(temp);
        return;
    }
    for(int i=start;i<s.size();i++)
    {
        if(is_palindrome(s,start,i))
        {
        	string sub(s.begin()+start,s.begin()+i+1);
        	//cout<<sub<<endl;
            temp.push_back(sub);
            partition_string(s,i+1,ans,temp);
            temp.pop_back();
        }
    }
}
vector<vector<string> > partition(string A) {
	vector<vector<string>> ans;
	vector<string> temp;
	partition_string(A,0,ans,temp);
	return ans;
}


int main(void) {
	disp(partition("aab"));
	//cout<<is_palindrome("aab",0,1);
	return 0;
}