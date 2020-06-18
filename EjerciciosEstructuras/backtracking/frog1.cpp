//https://atcoder.jp/contests/dp/tasks/dp_a
#include <bits/stdc++.h>
using namespace std;

int frog1(vector<int> stones){
    queue<pair<int,int>> saltos; //pair(costo acumulado, indice)
    saltos.push(make_pair(0,0));
    while(saltos.front().second+1 < stones.size()){
        int indx = saltos.front().second;
        int costoAnterior = saltos.front().first;
        saltos.pop();
        int costo = abs(stones[indx]-stones[indx+1]) + costoAnterior;
        if(saltos.empty()) saltos.push(make_pair(costo,indx+1));
        else if(saltos.front().first > costo) saltos.front().first = costo;
        if(indx+2 < stones.size()){
            costo = abs(stones[indx]-stones[indx+2]) + costoAnterior;
            saltos.push(make_pair(costo,indx+2));
        }
    }
    return saltos.front().first;
}

/**
2 ≤ N ≤ 10^5
1 ≤ hi ≤ 10^4
**/
int main(){
    int n, s;
    cin >> n;
    vector<int> stones;
    for(int i=0; i<n; i++){
        cin >> s;
        stones.push_back(s);
    }
    cout << frog1(stones);
}

