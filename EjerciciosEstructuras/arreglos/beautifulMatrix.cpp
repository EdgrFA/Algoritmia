//https://codeforces.com/problemset/problem/263/A
#include <bits/stdc++.h>
using namespace std;

int beautifulMatrix(vector<vector<int>> matrix){
	//find '1'
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
        	if(matrix[i][j] == 1)
        		return abs(i - 2) + abs(j - 2);
    return -1;
}

int main(){
	vector<vector<int>> matrix(5);

    for (int i = 0; i < 5; i++) {
        matrix[i].resize(5);
        for (int j = 0; j < 5; j++)
            cin >> matrix[i][j];
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

	int movements = beautifulMatrix(matrix);
	cout << movements << endl;
}

/****
Input
0 0 0 0 0
0 0 0 0 1
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0

Output
3
****/