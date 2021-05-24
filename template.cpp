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

int main(void) {
	double 1st=6.94;
	double 3rd=6.87;
	double 4th=6.75;
	double 7th=7.8;
	double 2nd = ((2*4+2*4+2*6+4*9+4*8+2*7+2*9+2*5+2*6)*(1.0))/22;
	double 5th = ((2*7+1*9+6*8+4*7+6*9+3*6+6*5)*(1.0))/28;
	double 6th = ((6*6+3*7+6*6+6*6+6*9)*(1.0))/27;
	double 8th = ((2*9+6*8+2*6+2*4+6*6+6*9+3*6+6*4+2*10)*(1.0))/35;
	cout<<"2nd sem "<<2nd<<endl;
	cout<<"5th sem "<<5th<<endl;
	cout<<"6th sem "<<6th<<endl;
	cout<<"8th sem "<<8th<<endl;
	cout<<"Final avg"<<((1st+2nd+3rd+4th+5th+6th+7th+8th)*(1.0))/8;
	return 0;
}