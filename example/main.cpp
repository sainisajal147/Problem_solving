#include <iostream>
#include<math.h>
using namespace std;

int len(int c)
{
    if(c==0)
    return 1;
    int i=0;
    while((c/((int)pow(10,i)))!=0)
    {
        i++;
    }
    return i;
}
int main()
{
    cout <<len(24566463)<< endl;
    return 0;
}
