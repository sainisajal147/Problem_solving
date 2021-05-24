#include<bits/stdc++.h>
 
using namespace std;

int main(){
	int n;
	cin>>n;
	int arr[n];
	map<int,int> m;
	for(int i= 0;i<n;i++){
		cin>>arr[i];
		m[arr[i]]++;
	}
	for(int i = 0;i<n;i++){
		if(m[arr[i]]==1){
			cout<<arr[i];
			return 0;
		}
	}
	cout<<-1;
	return 0;
}