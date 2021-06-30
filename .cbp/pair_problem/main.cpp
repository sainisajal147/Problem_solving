#include <iostream>
#include<math.h>
#include<cmath>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool issq(int n)
{
	int x=pow(n,1/2);
	int y=pow(n,1/3);
	cout<<x<<y;
	return n==x*x || n==y*y*y;
}
int main() {
	int t;
	cin >> t;										// Reading input from STDIN
	while(t--)
	{
		int ans=0,n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		for(int i=0;i<n-1;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				if(issq(a[i]+a[j]))
					ans++;
			}
		}
		cout<<ans<<endl;
	}

}
// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail


// Write your code here
