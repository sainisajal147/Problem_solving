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

struct node{
    int cr;
    int cl;
    int dis;
    node(int cr,int cl, int dis):cr(cr),cl(cl),dis(dis){}
};
int CleanRoomBattery(vector<vector<bool>> floorPlan, int battery) {
    int n=floorPlan.size(),m=floorPlan[0].size();
    //vector<vector<bool>> visi(n,vector<int> (m,false));
    bool visi[n][m]={0};
    queue<node> q;
    node src(0,0,1);
    visi[src.cr][src.cl]=1;
    q.push(src);
    int ans=1;
    while(!q.empty())
    {
        node temp=q.front();
        cout<<temp.dis<<endl;
        if(temp.cr-1>=0 and visi[temp.cr-1][temp.cl]==false and floorPlan[temp.cr-1][temp.cl]==0)
        {
            visi[temp.cr-1][temp.cl]=true;
            node p(temp.cr-1,temp.cl,temp.dis+1);
            q.push(p);
            if(p.dis<=ceil((battery*1.0)/2))
                ans++;
        }
        if(temp.cl-1>=0 and visi[temp.cr][temp.cl-1]==false and floorPlan[temp.cr][temp.cl-1]==0)
        {
            visi[temp.cr][temp.cl-1]=true;
            node p(temp.cr,temp.cl-1,temp.dis+1);
            q.push(p);
            if(p.dis<=ceil((battery*1.0)/2))
                ans++;
        }
        if(temp.cr+1<n and visi[temp.cr+1][temp.cl]==false and floorPlan[temp.cr+1][temp.cl]==0)
        {
            visi[temp.cr+1][temp.cl]=true;
            node p(temp.cr+1,temp.cl,temp.dis+1);
            q.push(p);
            if(p.dis<=ceil((battery*1.0)/2))
                ans++;
        }
        if(temp.cl+1<m and visi[temp.cr-1][temp.cl]==false and floorPlan[temp.cr][temp.cl+1]==0)
        {
            visi[temp.cr][temp.cl+1]=true;
            node p(temp.cr,temp.cl+1,temp.dis+1);
            q.push(p);
            if(p.dis<=ceil((battery*1.0)/2))
                ans++;
        }
        q.pop();
    }
    return ans;
}

int main(void) {
	vector<vector<bool>> v={{0,0,0},{0,1,0},{0,0,0}};
	cout<<CleanRoomBattery(v,12);
	return 0;
}