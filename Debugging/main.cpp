#include <iostream>

using namespace std;

int main()
{
   int sum=0;
   int a[5]={1,2,3,4,5};
   for(int i=0;i<5;i++)
   {
       sum+=a[i];
   }
   cout<<sum;
    return 0;
}
