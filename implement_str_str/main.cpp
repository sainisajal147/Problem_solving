#include <iostream>
#include<string>
using namespace std;

int strStr(string A,string B) {
    if(A==B)
        return 0;
    else if(A.size()>B.size())
    {
        for(int i=0;i<A.size()-B.size()+1;i++)
        {
            for(int j=i;j<i+B.size();j++)
            {
                if(A[j]==B[j-i])
                    {
                        if(j-i+1==B.size())
                            return i;
                    }
                else
                    break;
            }
        }
    }
    return -1;
}

int main()
{
    string a="bbaabbbbbaabbaabbbbbbabbbabaabbbabbabbbbababbbabbabaaababbbaabaaaba";
    string b="babaaa";
    cout<<strStr(a,b);
    return 0;
}
