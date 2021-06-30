#include <stdio.h>
#include <cmath>
#include <map>
#include <math.h>
#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

bool sumofsub(vector<int> v,int sum,int k,int N,int tarsum,vector<bool> &visi)
{
	static int x=0;
	if(N==1)
	{
		return true;
	}
	if(tarsum==sum)
	{
		return sumofsub(v,0,0,N-1,tarsum,visi);
	}
	for(int i=k;i<v.size();i++)
	{
		if(!visi[i])
		{
			visi[i]=true;
			if(sumofsub(v,sum+v[i],i+1,N,tarsum,visi))
				return true;
			visi[i]=false;
		}
	}
	return false;
}
int main() {
	vector<int> v={1,1,1,1};int k=4;
	vector<bool> visi(v.size(),false);
	int s=accumulate(v.begin(),v.end(),0);
	if(s%k)
		cout<<false<<endl;
	else
		cout<<sumofsub(v,0,0,k,s/k,visi);
	return 0;
}