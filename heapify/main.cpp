#include <iostream>
#include<cmath>
#include<bits/stdc++.h>
#include<vector>
#include<algorithm>
using namespace std;
void disp(vector<int> a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}
int left(int i)
{
    return 2 * (i + 1) - 1;
}
int right(int i)
{
    return 2 * (i + 1);
}
int parent(int i)
{
    return floor((i + 1) / 2) - 1;
}
void adjust( vector<int> &a, int i, int n)
{
    int l = left(i);
    int r = right(i);
    int larg = i;
    if (l < n && a[larg] < a[l])
        larg = l;
    if (r < n && a[larg] < a[r])
        larg = r;
    if (larg != i)
    {
        swap(a[larg], a[i]);
        adjust(a, larg, n);
    }
}
void heapify(vector<int> &a, int n)
{
    for (int i = n - 1; i >= 0; i--)
    {
        adjust(a, i, n);
    }
}
void del(vector<int> & a, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        swap(a[0], a[n - i - 1]);
        adjust(a, 0, n - i - 1);
    }
}
void heap_sort(vector<int> &a)
{
    int n = a.size();
    heapify(a, n);
    del(a, n);
}
int main()
{
    vector<int > a = {1, 5, 2, 3, 6, 2, 3, 1, 43, 32, 12, 35};
    heap_sort(a);
    disp(a, a.size());
    return 0;
}
