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

vector<string> fullJustify(vector<string> &A, int B) {
	vector<string> ans;
    string temp;
    for (int i = 0; i < A.size(); i++)
    {
        if (temp.size() + A[i].size() <= B)
        {
            if (temp.size() + A[i].size() == B or i==A.size()-1)
                temp += A[i];
            else
                temp += A[i] + ' ';
        }
        else
        {
            ans.push_back(temp);
            temp.clear();
            temp += A[i] + ' ';
            //cout<<temp<<endl;
        }
    }
    if(!temp.empty())
    {
        for(int i=temp.size();i<B;i++)
        {
            temp+=' ';
        }
        ans.push_back(temp);
    }
	if(ans.size()>0)
	{
		for(int i=0;i<ans.size()-1;i++)
		{
			while(ans[i].back()==' ')
			{
				ans[i].pop_back();
			}
			int sp=B-ans[i].size(),k=0;
			while(sp>0)
			{
				k=k%(ans[i].size());
				if(ans[i][k]==' ')
				{
					ans[i].insert(ans[i].begin()+k,' ');
					sp--;
				}
				k+=2;
			}
		}
	}
	return ans;
}
void disp(vector<string> ans)
{
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << endl;
	}
}
int main() {
	//cout<<"Hello World!";
	vector<string> v ={ "am", "fasgoprn", "lvqsrjylg", "rzuslwan", "xlaui", "tnzegzuzn", "kuiwdc", "fofjkkkm", "ssqjig", "tcmejefj", "uixgzm", "lyuxeaxsg", "iqiyip", "msv", "uurcazjc", "earsrvrq", "qlq", "lxrtzkjpg", "jkxymjus", "mvornwza", "zty", "q", "nsecqphjy" };//{ "glu", "muskzjyen", "ahxkp", "t", "djmgzzyh", "jzudvh", "raji", "vmipiz", "sg", "rv", "mekoexzfmq", "fsrihvdnt", "yvnppem", "gidia", "fxjlzekp", "uvdaj", "ua", "pzagn", "bjffryz", "nkdd", "osrownxj", "fvluvpdj", "kkrpr", "khp", "eef", "aogrl", "gqfwfnaen", "qhujt", "vabjsmj", "ji", "f", "opihimudj", "awi", "jyjlyfavbg", "tqxupaaknt", "dvqxay", "ny", "ezxsvmqk", "ncsckq", "nzlce", "cxzdirg", "dnmaxql", "bhrgyuyc", "qtqt", "yka", "wkjriv", "xyfoxfcqzb", "fttsfs", "m" };
	disp(fullJustify(v, 14));
	return 0;
}