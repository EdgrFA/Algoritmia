//https://codeforces.com/problemset/problem/266/A
#include <bits/stdc++.h>
using namespace std;

int neighboringStones(int n, string row){
	int ns = 0;
	for (int i = 0; i+1 < n; i++)
		if(row[i] == row[i+1])
			ns++;
	return ns;
}

int main(){
	int n;
	string stonesRow;
	cin >> n >> stonesRow;
	cout << neighboringStones(n, stonesRow);
}