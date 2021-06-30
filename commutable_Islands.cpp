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

int solve(int A, vector<vector<int> > &B) {
    vector<vector<int>> v(A+1,vector<int> (A+1,INT_MAX));
    vector<vector<int>> bridge(2,vector<int> (A-1,0));
    vector<int> near(A+1,INT_MAX);
    int start_bridge=INT_MAX,bridge_index=1;
    for(int i=0;i<B.size();i++)
    {
    	if(start_bridge>B[i][2])
    	{
    		bridge[0][0]=B[i][0];
    		bridge[1][0]=B[i][1];
    		start_bridge=B[i][2];
    	}
        v[B[i][0]][B[i][1]]=B[i][2];
        v[B[i][1]][B[i][0]]=B[i][2];
    }
    near[bridge[0][0]]=near[bridge[1][0]]=0;
    for(int i=1;i<=A;i++)
    {
    	if(bridge[0][0]!=i and bridge[1][0]!=i)
    	{
	    	if(v[bridge[0][0]][i]<v[bridge[1][0]][i])
	    		near[i]=bridge[0][0];
	    	else
	    		near[i]=bridge[1][0];
	    }
    }
    cout<<"start Bridge"<<start_bridge<<endl<<endl;
    for(int i=1;i<A-1;i++)
    {
    	start_bridge=INT_MAX;
    	for(int j=1;j<=A;j++)
    	{
    		if(near[j]!=0 and start_bridge>v[j][near[j]])
    		{
    			bridge[0][i]=j;
    			start_bridge=v[j][near[j]];
    		}
    	}
    	bridge[1][i]=near[bridge[0][i]];
    	near[bridge[0][i]]=0;
    	for(int j=1;j<=A;j++)
	    {
	    	if(near[j]!=0 and v[j][bridge[0][i]]<v[j][near[j]])
	    		near[j]=bridge[0][i];
	    }
    }
    int ans=0;
    for(int i=0;i<A-1;i++)
    	ans+=v[bridge[0][i]][bridge[1][i]];
    cout<<"The Bridge Array\n";
    disp(bridge);
    cout<<endl;
    cout<<"The graph\n";
    disp(v);
    cout<<endl;
    cout<<"near array\n";
    disp(near);
    return ans;
}

int main(void) {
	int A=3;
	vector<vector<int>> B={{1,2,10},{2,3,5},{1,3,9}};
	cout<<solve(A,B);
	return 0;
}