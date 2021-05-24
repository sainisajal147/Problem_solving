/*
AUTHOR : SAJAL SAINI
*/
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
#include <math.h>
#include <set>

using namespace std;

#define MAX 1000001

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

int x(int z)
{
	string s=to_string(z);
	int ans=0;
	vector<int> v;
	int n=z;
	while(n)
	{
		v.insert(v.begin(),n%10);
		n=n/10;
	}
	
	for(int i=v.size()-1;i>=1;i--)
	{
		if(v[i]>v[i-1])
		{
			swap(v[i],v[i-1]);
			break;
		}
	}
	disp(v);
	return ans;
}

bool ans(vector<int> A)
{
	sort(A.begin(),A.end());
    vector<int> ans;
    for(int i=0,j=A.size()/2+1,k=0;k<A.size();)
    {
    	if(k%2==0 and i<=A.size()/2)
    	{
    		//cout<<A[i]<<" ";
    		ans.push_back(A[i]);
    		i++;
    	}
    	else 
    	{
    		if(j<A.size())
    		{
    			//cout<<A[j]<<" ";
    			ans.push_back(A[j]);
    			j++;
    		}
    	}
    	k++;
    }
    //disp(A);
    disp(ans);
    for(int i=0;i<ans.size()-2;i++)
    {
    	if(i%2==0)
    	{
    		if(ans[i]<ans[i+1] and ans[i+1]>ans[i+2])
    			continue;
    		else
    			return false;
    	}
    	else
    	{
    		if(ans[i]>ans[i+1] and ans[i+1]<ans[i+2])
    			continue;
    		else
    			return false;
    	}
    }
    return true;
}

void sieveOfEratosthenes(bool* primes) 
{ 
    // 1 is neither prime nor composite 
    primes[1] = false; 
  
    for (int i = 2; i * i < MAX; i++) { 
  
        // If prime[i] is not changed, 
        // then it is a prime 
        if (primes[i] == true) { 
  
            // Update all multiples of i 
            for (int j = i * 2; j < MAX; j += i) 
                primes[j] = false; 
        } 
    } 
} 
  
// Function returns 1 if the number N is 
// permutable prime otherwise not 
bool checkPermutablePrime(int N) 
{ 
    // Boolean Array for prime numbers 
    bool primes[MAX]; 
  
    // Initialize all entries as true. 
    // A value in prime[i] will finally 
    // be false if i is not a prime, 
    // else true. 
    memset(primes, true, sizeof(primes)); 
  
    sieveOfEratosthenes(primes); 
  
    // Creating Array to store digits 
    int num[7]; 
  
    // Convert the number into array of digits 
    int pos = 0; 
    while (N > 0) { 
        num[pos++] = N % 10; 
        N /= 10; 
    } 
  
    // Size of Array 
    int SZ = pos; 
    int flag = 0; 
  
    sort(num, num + SZ); 
  
    do { 
  
        // Construct the number again 
        // from array of digits 
        int temp = 0; 
        pos = 0; 
        while (pos < SZ) { 
            temp = temp * 10 + num[pos]; 
            pos++; 
        } 
  
        // check if it is prime of not 
        if (primes[temp] == false) { 
            flag = 1; 
            break; 
        } 
    } while (next_permutation(num, num + SZ)); 
  
    // If flag is 1, number 
    // is not permutable prime 
    if (flag) 
        return false; 
  
    return true; 
}

int main(void) {
	//cout<<x(41352);
	vector<int> v={0,4,22,4,14,4,2};
	cout<<ans(v);
	//cout<<checkPermutablePrime(98);
	return 0;
}