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

vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        if(nums.size()<4)
        	return ans;
        sort(nums.begin(),nums.end());
        map<vector<int>,int> m;
        for(int i=0;i<nums.size()-3;i++)
        {
            for(int j=i+1;j<nums.size()-2;j++)
            {
            	/*for(int k=j+1;k<nums.size()-1;k++)
            	{
            		for(int l=k+1;l<nums.size();l++)
            		{
            			if(nums[i]+nums[j]+nums[k]+nums[l]==target)
            			{
            				vector<int> temp(4);
	                        temp[0]=nums[i];
	                        temp[1]=nums[j];
	                        temp[2]=nums[k];
	                        temp[3]=nums[l];
	                        ans.push_back(temp);
            			}
            		}
            	}*/
                int p=target-(nums[i]+nums[j]);
                int k=j+1,l=nums.size()-1;
                while(k<l)
                {
                    if(nums[k]+nums[l]<p)
                    {
                        k++;
                    }
                    else if(nums[k]+nums[l]>p)
                    {
                        l--;
                    }
                    else
                    {
                        vector<int> temp(4);
                        temp[0]=nums[i];
                        temp[1]=nums[j];
                        temp[2]=nums[k];
                        temp[3]=nums[l];
                        if(m[temp]==0)
                        {
                        	ans.push_back(temp);
                        	m[temp]=1;
                        }
                        k++;
                        l--;
                    }
                }
            }
        }
        return ans;
}

int main(void) {
	vector<int> v={1,0,-1,0,-2,2};
	int target=0;
	disp(fourSum(v,target));
	return 0;
}