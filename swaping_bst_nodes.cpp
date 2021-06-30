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

vector<int> swapping(vector<int> &v)
{
	vector<int> ans(2);
	bool st=false;
    bool nd=false;
    int a,b,c;
    for(int i=1;i<v.size();i++)
    {
        if(!st and v[i]<v[i-1])
        {
            a=v[i-1];
            b=v[i];
            cout<<v[i-1]<<" "<<v[i]<<endl;
            st=true;
            continue;
        }
        if(st and !nd and v[i]<v[i-1])
        {
            c=v[i];
            cout<<v[i-1]<<" "<<v[i]<<endl;
            nd=true;
        }
    }
    if(nd)
    {
        ans[0]=c;
        ans[1]=a;
        return ans;
    }
    for(int i=1;i<v.size();i++)
    {
        if(v[i]<v[i-1])
        {
            ans[0]=v[i];
            ans[1]=v[i-1];
            break;
        }
    }
    return ans;
}

int main(void) {
	vector<int> v={69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 92, 85, 86, 87, 88, 89, 90, 91, 84, 93, 94, 95, 96};
	disp(swapping(v));
	return 0;
}