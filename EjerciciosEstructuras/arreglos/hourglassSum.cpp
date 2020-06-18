//https://codeforces.com/problemset/problem/263/A
#include <bits/stdc++.h>
using namespace std;

// Complete the hourglassSum function below.
int hourglassSum(vector<vector<int>> arr) {
    int maxHourglass;
    for(int i = 0; i+2 < 6; i++){
        for (int j = 0; j+2 < 6; j++){
            int hgSum = arr[i][j] + arr[i][j+1] + arr[i][j+2] + arr[i+1][j+1] 
                    + arr[i+2][j] + arr[i+2][j+1] + arr[i+2][j+2];
            if(i == 0 && j == 0)
                maxHourglass = hgSum;
            else
                maxHourglass = max(maxHourglass, hgSum);
        }
    }
    return maxHourglass;
}

// a b c
//   d
// e f g