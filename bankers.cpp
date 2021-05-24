#include <iostream> 
using namespace std; 
  
int main() 
{ 
    // P0, P1, P2, P3, P4 are the Process names here 
  
    int n, m, i, j, k; 
    n = 3; // Number of processes
    m = 3; // Number of resources 
    int alloc[3][3] = { { 3,5,4 }, // P0 // Allocation Matrix 
                        { 1,3,5 }, // P1 
                        { 2,3,5 }}; // P4 
  
    /*int max[3][3] = { { 5,9,4 }, // P0 // MAX Matrix 
                    { 1,3,5 }, // P1 
                    { 2,4,8 }}; // P4 
    */
    int avail[3] = { 2,2,3 }; // Available Resources 
    int need[3][3]={{2,4,0},
                    {0,0,1},
                    {0,1,3}};
    int f[n], ans[n], ind = 0; 
    for (k = 0; k < n; k++) { 
        f[k] = 0; 
    } 
    /*int need[n][m]; 
    for (i = 0; i < n; i++) { 
        for (j = 0; j < m; j++) 
            need[i][j] = max[i][j] - alloc[i][j]; 
    }*/
     
    int y = 0; 
    for (k = 0; k < 5; k++) { 
        for (i = 0; i < n; i++) { 
            if (f[i] == 0) { 
  
                int flag = 0; 
                for (j = 0; j < m; j++) { 
                    if (need[i][j] > avail[j]){ 
                        flag = 1; 
                        break; 
                    } 
                } 
  
                if (flag == 0) { 
                    ans[ind++] = i; 
                    for (y = 0; y < m; y++) 
                        avail[y] += alloc[i][y]; 
                    f[i] = 1; 
                } 
            } 
        } 
    } 
  
    cout << "Following is the SAFE Sequence" << endl; 
    for (i = 0; i < n - 1; i++) 
        cout << " P" << ans[i] << " ->"; 
    cout << " P" << ans[n - 1] <<endl; 
  
    return (0); 
} 