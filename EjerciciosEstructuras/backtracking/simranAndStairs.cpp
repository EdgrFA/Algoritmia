//https://www.hackerearth.com/practice/basic-programming/recursion/recursion-and-backtracking/practice-problems/algorithm/simran-and-stairs/description/
#include <bits/stdc++.h>
using namespace std;

int simranStairs(int n, int indx, unordered_map<int, int> &caminos){
    if(indx+1 > n) return 1;
    if(caminos.find(indx) == caminos.end()){
        int cmns = 0;
        cmns += simranStairs(n,indx+1,caminos);
        if(indx+2 < n+1) cmns += simranStairs(n,indx+2,caminos);
        if(indx+3 < n+1) cmns += simranStairs(n,indx+3,caminos);
        caminos[indx] = cmns;
        return cmns;
    }
    return caminos[indx];
}

int main(){
    unordered_map<int, int> caminos;
    int n;
    cin >> n;
    cout << simranStairs(n,0,caminos);
}