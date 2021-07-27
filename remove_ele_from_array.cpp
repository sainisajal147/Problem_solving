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

int removeElement(vector<int> &A, int B) {
    int i=0,j=0,n=A.size();
    while(i<n and j<n)
    {
        while(i<n and A[i]!=B)
            i++;
        j=i+1;
        while(j<n and A[j]==B)
            j++;
        //cout<<A[i]<<" "<<A[j]<<endl;
        if(i<n and j<n)
        	swap(A[i],A[j]);
    }
    //A=A(A.begin(),A.begin()+i);
    /*while(A.back()==B)
    	A.pop_back();*/
    A.resize(i);
    disp(A);
    return n-i;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}

int main(void) {
	vector<int> v={2, 0, 1, 2, 0, 3, 2, 2, 2, 1, 0, 0, 0, 1, 0, 0, 2, 2, 2, 3, 2, 3, 1, 2, 1, 2, 2, 3, 2, 3, 0, 3, 0, 2, 1, 2, 0, 0, 3, 2, 3, 0, 3, 0, 2, 3, 2, 2, 3, 1, 3, 3, 0, 3, 3, 0, 3, 3, 2, 0, 0, 0, 0, 1, 3, 0, 3, 1, 3, 1, 0, 2, 3, 3, 3, 2, 3, 3, 2, 2, 3, 3, 3, 1, 3, 2, 1, 0, 0, 0, 1, 0, 3, 2, 1, 0, 2, 3, 0, 2, 1, 1, 3, 2, 0, 1, 1, 3, 3, 0, 1, 2, 1, 2, 2, 3, 1, 1, 3, 0, 2, 2, 2, 2, 1, 0, 2, 2, 2, 1, 3, 1, 3, 1, 1, 0, 2, 2, 0, 2, 3, 0, 1, 2, 1, 1, 3, 0, 2, 3, 2, 3, 2, 0, 2, 2, 3, 2, 2, 0, 2, 1, 3, 0, 2, 0, 2, 1, 3, 1, 1, 0, 0, 3, 0, 1, 2, 2, 1, 2, 0, 1, 0, 0, 0, 1, 1, 0, 3, 2, 3, 0, 1, 3, 0, 0, 1, 0, 1, 0, 0, 0, 0, 3, 2, 2, 0, 0, 1, 2, 0, 3, 0, 3, 3, 3, 0, 3, 3, 1, 0, 1, 2, 1, 0, 0, 2, 3, 1, 1, 3, 2};//{4,4,32,1,1,1,1,543,231,1,1,2,1,3};
	cout<<removeElement(v,2);
	return 0;
	//0 1 0 3 1 0 0 0 1 0 0 3 3 1 1 3 3 0 3 0 1 0 0 3 3 0 3 0 3 3 1 3 3 0 3 3 0 3 3 0 0 0 0 1 3 0 3 1 3 1 0 3 3 3 3 3 3 3 3 1 3 1 0 0 0 1 0 3 1 0 3 0 1 1 3 0 1 1 3 3 0 1 1 3 1 1 3 0 1 0 1 3 1 3 1 1 0 0 3 0 1 1 1 3 0 3 3 0 3 0 1 3 0 0 1 3 1 1 0 0 3 0 1 1 0 1 0 0 0 1 1 0 3 3 0 1 3 0 0 1 0 1 0 0 0 0 3 0 0 1 0 3 0 3 3 3 0 3 3 1 0 1 1 0 0 3 1 1 3
	//0 1 0 3 1 0 0 0 1 0 0 3 3 1 1 3 3 0 3 0 1 0 0 3 3 0 3 0 3 3 1 3 3 0 3 3 0 3 3 0 0 0 0 1 3 0 3 1 3 1 0 3 3 3 3 3 3 3 3 1 3 1 0 0 0 1 0 3 1 0 3 0 1 1 3 0 1 1 3 3 0 1 1 3 1 1 3 0 1 0 1 3 1 3 1 1 0 0 3 0 1 1 1 3 0 3 3 0 3 0 1 3 0 0 1 3 1 1 0 0 3 0 1 1 0 1 0 0 0 1 1 0 3 3 0 1 3 0 0 1 0 1 0 0 0 0 3 0 0 1 0 3 0 3 3 3 0 3 3 1 0 1 1 0 0 3 1 1 3
	//0 1 0 3 1 0 0 0 1 0 0 3 3 1 1 3 3 0 3 0 1 0 0 3 3 0 3 0 3 3 1 3 3 0 3 3 0 3 3 0 0 0 0 1 3 0 3 1 3 1 0 3 3 3 3 3 3 3 3 1 3 1 0 0 0 1 0 3 1 0 3 0 1 1 3 0 1 1 3 3 0 1 1 3 1 1 3 0 1 0 1 3 1 3 1 1 0 0 3 0 1 1 1 3 0 3 3 0 3 0 1 3 0 0 1 3 1 1 0 0 3 0 1 1 0 1 0 0 0 1 1 0 3 3 0 1 3 0 0 1 0 1 0 0 0 0 3 0 0 1 0 3 0 3 3 3 0 3 3 1 0 1 1 0 0 3 1 1 3
	//0 1 0 3 1 0 0 0 1 0 0 3 3 1 1 3 3 0 3 0 1 0 0 3 3 0 3 0 3 3 1 3 3 0 3 3 0 3 3 0 0 0 0 1 3 0 3 1 3 1 0 3 3 3 3 3 3 3 3 1 3 1 0 0 0 1 0 3 1 0 3 0 1 1 3 0 1 1 3 3 0 1 1 3 1 1 3 0 1 0 1 3 1 3 1 1 0 0 3 0 1 1 1 3 0 3 3 0 3 0 1 3 0 0 1 3 1 1 0 0 3 0 1 1 0 1 0 0 0 1 1 0 3 3 0 1 3 0 0 1 0 1 0 0 0 0 3 0 0 1 0 3 0 3 3 3 0 3 3 1 0 1 1 0 0 3 1 1 3
}