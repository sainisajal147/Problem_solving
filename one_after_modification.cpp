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

int solve(vector<int> &A, int B) {
	int n=A.size();
	int w=0,ws=0,we=0,z=0;
	while(we<n)
	{
		if(A[we]==0)
		{
			z++;
		}
		if(z>B)
		{
			if(A[ws]==0)
				z--;
			ws++;
		}
		w=max(w,we-ws+1);
		we++;
	}
	return w;
    /*int i=0,j=0,n=A.size(),ans=INT_MIN;
    /*while(i<n and A[i]==0)
        i++;
    if(i==n)
        return B;
    cout<<i<<endl;
    ans=min({B+1,i+1});
    while(i<n and j<n)
    {
    	while(i<n and A[i]==0)
    		i++;
        j=i+1;
        int oin=B;
        while(j<n and oin>0)
        {
            if(A[j]==0)
                oin--;
            j++;
        }
        if(A[j]==0)
        {
        	i=j;
        	continue;
        }
        while(j<n and A[j]==1)
            j++;
        j--;
        ans=max(ans,j-i+1);
        if(i==j)
        	break;
        //ans=max(ans,j-i+1);
        cout<<i<<" "<<j<<endl;
        i=j;
    }
    return ans;*/
}

int main(void) {
	vector<int> v={0,0,1,1,1,1};
	cout<<solve(v,4);
	return 0;
}