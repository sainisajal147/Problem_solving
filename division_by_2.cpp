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

string division_by_2(string dividend)
{
	if(dividend=="0")
		return "0";
	if(dividend=="1")
		return "1";
	if(!(dividend.back()=='0' or dividend.back()=='2' or dividend.back()=='4' or dividend.back()=='6' or dividend.back()=='8'))
		return "-1";
    string quotient="",rem="";
    for(int i=0;i<dividend.size();i++)
    {
        rem+=dividend[i];
        if(stoi(rem)>=2)
        {
            if(stoi(rem)%2==0)
            {
                quotient+=to_string(stoi(rem)/2);
                rem.clear();
            }
            else
            {
                quotient+=to_string(stoi(rem)/2);
                rem="1";
            }
        }
        else
        {
        	quotient+="0";
        }
    }
    while(quotient[0]=='0')
    	quotient.erase(quotient.begin());
    return quotient;
}

int main(void) {
	cout<<division_by_2("4");
	return 0;
}