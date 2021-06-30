
#include <iostream>

using namespace std;
int sumi(int a[3][3])
{
    int sum=a[1][1];
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(i==0 || i==2)
            sum+=a[i][j];
        }
    }
    return sum;
}
int large(int sum[16])
{
    int max=sum[0];
    for(int i=1;i<16;i++)
    {
        if(sum[i]>max)
        {
            max=sum[i];
        }
    }
    return max;
}
// Complete the hourglassSum function below.
int hourglassSum(vector<vector<int>> arr) {
int a[3][3],sum[16];
for(int i=0;i<6;i++)
{
    for(int j=0;j<6;j++)
    {
        for(int k=0;k<16;k++)
        {
            for(int n=i;n<i+3;n++)
            {
                for(int m=j;m<j+3;m++)
                {
                    a[n][m]=arr[i][j];
                }
            }
            sum[k]=sumi(a);
        }
    }
}
int max=large(sum);
return max;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> arr(6);
    for (int i = 0; i < 6; i++) {
        arr[i].resize(6);

        for (int j = 0; j < 6; j++) {
            cin >> arr[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = hourglassSum(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}
