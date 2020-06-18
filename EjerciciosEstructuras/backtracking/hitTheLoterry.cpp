//https://codeforces.com/contest/996/problem/A
#include <bits/stdc++.h>
using namespace std;

const int denominations[6] = {100,20,10,5,1};

int hitTheLottery(int dollars){
    if(dollars == 0) return 0;
    for(auto denomination : denominations){
        if(dollars >= denomination){
            int bills = dollars/denomination;
            return bills + hitTheLottery(dollars-bills*denomination);
        }
    }
    return 0;
}

int main(){
    int dollars;
    cin >> dollars;
    cout << hitTheLottery(dollars);
}