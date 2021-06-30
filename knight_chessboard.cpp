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

struct cell{
  int i,j,dist;
  cell(){}
  cell(int i,int j,int dist): i(i),j(j),dist(dist){}
};

int knight(int A, int B, int C, int D, int E, int F) {
    queue<cell> q;
    cell src(C-1,D-1,0);
    q.push(src);
    vector<vector<int>> v(A,vector<int> (B,0));
    v[C-1][D-1]=0;
    while(!q.empty())
    {
        cell temp=q.front();
        int i=temp.i,j=temp.j,dist=temp.dist;
        if(i-2>=0 and j-1>=0 and v[i-2][j-1]==0)
        {
            v[i-2][j-1]=dist+1;
            cell new_temp(i-2,j-1,temp.dist+1);
            q.push(new_temp);
        }
        if(i-1>=0 and j-2>=0 and v[i-1][j-2]==0)
        {
            v[i-1][j-2]=dist+1;
            cell new_temp(i-1,j-2,temp.dist+1);
            q.push(new_temp);
        }
        if(i+1<A and j-2>=0 and v[i+1][j-2]==0)
        {
            v[i+1][j-2]=dist+1;
            cell new_temp(i+1,j-2,temp.dist+1);
            q.push(new_temp);
        }
        if(i+2<A and j-1>=0 and v[i+2][j-1]==0)
        {
            v[i+2][j-1]=dist+1;
            cell new_temp(i+2,j-1,temp.dist+1);
            q.push(new_temp);
        }
        if(i-1>=0 and j+2<B and v[i-1][j+2]==0)
        {
            v[i-1][j+2]=dist+1;
            cell new_temp(i-1,j+2,temp.dist+1);
            q.push(new_temp);
        }
        if(i-2>=0 and j+1<B and v[i-2][j+1]==0)
        {
            v[i-2][j+1]=dist+1;
            cell new_temp(i-2,j+1,temp.dist+1);
            q.push(new_temp);
        }
        if(i+1<A and j+2<B and v[i+1][j+2]==0)
        {
            v[i+1][j+2]=dist+1;
            cell new_temp(i+1,j+2,temp.dist+1);
            q.push(new_temp);
        }
        if(i+2<A and j+1<B and v[i+2][j+1]==0)
        {
            v[i+2][j+1]=dist+1;
            cell new_temp(i+2,j+1,temp.dist+1);
            q.push(new_temp);
        }
        q.pop();
    }
    return v[E-1][F-1];
}

int main(void) {
	cout<<knight(8,8,1,1,8,8);
	return 0;
}