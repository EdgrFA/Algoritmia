//https://codeforces.com/problemset/problem/1113/A
#include <bits/stdc++.h>
using namespace std;

void printQueens(vector<int> queens){
    for(int i=0; i < queens.size(); i++){
        for(int j=0; j < queens.size(); j++){
            if(j!=0) cout << " ";
            if(queens[i] == j) cout << "1";
            else cout << "0";
        }
        cout << "\n";
    }
}

int nqueens(vector<int> queens, int index){
    int size = queens.size();
    for(int i = 0; i < size; i++){
        bool queenSafe = true;
        queens[index]++;
        //reglas
        for(int j = 0; j < size; j++){
            if (index == j || queens[j] == -1) continue;
            if(queens[j] == queens[index]) queenSafe = false; //Misma columna
            if(queens[j] == queens[index]-index+j) queenSafe = false; //Diagonal Derecha
            if(queens[j] == queens[index]+index-j) queenSafe = false; //Diagonal izquierda
            if(!queenSafe) break; 
        }
        if(!queenSafe) continue; 
        if(index+1 == size) {
            printQueens(queens); //imprimir resultado
            return 1;
        }
        if(nqueens(queens,index+1)) return 1;
    }
    return 0;
}

int main(){
    int n;
    cin >> n; //1 <= n <= 10
    vector<int> queens;
    for(int i=0; i < n; i++) queens.push_back(-1);
    if(!nqueens(queens, 0))
        cout << "Not possible";
}