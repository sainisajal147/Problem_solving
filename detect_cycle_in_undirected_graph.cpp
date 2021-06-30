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

/*int bfs_cycle(vector<vector<int>> v,int A)
{
	queue<int> q;
	vector<int> visi(A+1,-1);
	vector<int> vi(A+1,false);
	q.push(1);
	vi[1]=true;
	while(!q.empty())
	{
		int temp=q.front();
		//cout<<temp<<" ";
		for(int j=0;j<v[temp].size();j++)
		{
			if(vi[v[temp][j]]==false)
			{
				q.push(v[temp][j]);
				visi[v[temp][j]]=temp;
				vi[v[temp][j]]=true;
			}
			else if(visi[temp]==visi[v[temp][j]])
			{
				//disp(visi);
				//disp(vi);
				return 1;
			}
		}
		q.pop();
	}
	//disp(visi);
	return 0;
}*/

int bfs_cycle(vector<vector<int>> v,int A)
{
	queue<int> q;
	vector<int> visi(A+1,-1);
	visi[1]=0;
	q.push(1);
	while(!q.empty())
	{
		int temp=q.front();
		q.pop();
		visi[temp]=1;
		for(int j=0;j<v[temp].size();j++)
		{
		    if(visi[v[temp][j]]==0)
			{
				cout<<"Has cycle";
				disp(visi);
				return 1;
			}
			if(visi[v[temp][j]]==-1)
			{
				q.push(v[temp][j]);
				visi[v[temp][j]]=0;
			}
		}
	}
	disp(visi);
	return 0;
}

int main(void) {
	int v=5;
	vector<vector<int>> A(v+1);
	A[1].push_back(2);
	A[1].push_back(3);
	A[2].push_back(1);
	A[2].push_back(4);
	A[2].push_back(5);
	A[3].push_back(1);
	A[4].push_back(2);
	A[4].push_back(5);
	A[5].push_back(2);
	A[5].push_back(4);
	disp(A);
	cout<<bfs_cycle(A,v);
	return 0;
}