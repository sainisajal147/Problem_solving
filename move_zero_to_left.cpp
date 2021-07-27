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

void moveElements(vector<int> &arr) {
    int n=arr.size();
    int i=0,j=1;
    while(j<n)
    {
        if(i==j)
        {
            j++;
        }
        else if(arr[i]==0 and arr[j]==0)
        {
            j++;
        }
        else if(arr[i]==0 and arr[j]!=0 and i<j)
        {
            swap(arr[i],arr[j]);
            i++;
            j++;
        }
        else if(arr[i]!=0 and arr[j]==0)
        {
            i++;
        }
        else
        	i++;
    }
}

int main(void) {
	vector<int> v={1, 9, 8, 4, 0, 0, 2, 7, 0, 6, 0, 9};
	moveElements(v);
	disp(v);
	return 0;
}