//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2493
#include <bits/stdc++.h>
using namespace std;

void getDivision(int n, int m, int x, int y){
    if(n == x || m == y){
        cout << "divisa\n";
        return;
    }
    if(x < n){ //oeste
        if(y < m) cout << "SO\n";
        else cout << "NO\n";
    }
    else{ //este
        if(y < m) cout << "SE\n";
        else cout << "NE\n";
    }   
}

int main(){
    int k;
    cin >> k;
    while(k){
        int n,m,x,y;
        cin >> n >> m;
        for(int i = 0; i < k; i++){
            cin >> x >> y;
            getDivision(n,m,x,y);
        }
        cin >> k;
    }
    return 0;
}