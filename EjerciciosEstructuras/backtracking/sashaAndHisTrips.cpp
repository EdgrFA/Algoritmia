//https://codeforces.com/problemset/problem/1113/A
#include <bits/stdc++.h>
using namespace std;

int calcularCosto(int n, int v){
    int costo = v, gas = v-1;
    if(n<=v){
        costo = n-1;
        gas = n-2;
    }
    for(int precio = 2; precio < n; precio++, gas--){
        if(gas < n-precio){
            costo += precio;
            gas++;
        }
    }
    return costo;
}

int calcularCostoRecursivo(int gas, int precio, int n, int v){
    if(n-precio == 0) return 0;
    if(gas < n-precio){
        int recarga = n-precio-gas;
        if(v-gas < recarga) recarga = v-gas;
        gas += recarga;
        return (recarga*precio) + calcularCostoRecursivo(gas-1,precio+1,n,v);
    }
    return calcularCostoRecursivo(gas-1,precio+1,n,v);
}

int main(){
    int n, v; //(2 ≤ n ≤ 100, 1 ≤ v ≤ 100)
    cin >> n >> v;
    cout << calcularCostoRecursivo(0,1,n,v) << "\n";
}