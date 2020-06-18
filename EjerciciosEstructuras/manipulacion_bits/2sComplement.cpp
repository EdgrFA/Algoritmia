//https://www.hackerrank.com/challenges/2s-complement/problem
#include <bits/stdc++.h>
using namespace std;

/***
numero de bits encendidos totales de las combinaciones posibles en n bits.
long long bitsEncendidosNbits(int n){
    long long bitsE = 0; 
    for(int i=0; i<n; i++)
        bitsE += (1 << i) + btisE*2;
    return bitsE; 
}


long long bitsEncendidos(long n){
    long long c = 0;
    if(n < 0) {
        //Negativos
        n = ~n;
        while(n){
            if((n & 1) == 1) c++;
            n >>= 1;
        }
        c = (long)(32-c);
    }else{
        //Positivos
        while(n){
            if((n & 1) == 1) c++;
            n >>= 1;
        }
    }
    return c;
}
***/

long long bitsEncendidosPositivos(long a, long b){
    if( a == 0 && b == 0) return (long long) 0;
    if(++a < ++b) a -= a != 0 ? 1 : 0;
    else b -= b != 0 ? 1 : 0;
    long long bitsA = 0, bitsB = 0;
    for(int i = 1; i <= 32; i++){
        bitsA += (a / ((long long)1 << i)) * ((long long)1 << (i-1)) + max((long long)0, a % (1 << i) - ((long long)1 << (i - 1)));
        bitsB += (b / ((long long)1 << i)) * ((long long)1 << (i-1)) + max((long long)0, b % (1 << i) - ((long long)1 << (i - 1)));
    }
    return abs(bitsA - bitsB);
}

long long bitsEncendidosNegativos(long a, long b){
    a *= -1 , b *= -1;
    if(a < b) a -= a != 0 ? 1 : 0;
    else b -= b != 0 ? 1 : 0;
    long long bitsA = 0, bitsB = 0;
    for(int i = 1; i <= 32; i++){
        bitsA +=  a - ((a / ((long long)1 << i)) * ((long long)1 << (i-1)) + max((long long)0, a % ((long long)1 << i) - ((long long)1 << (i - 1))));
        bitsB +=  b - ((b / ((long long)1 << i)) * ((long long)1 << (i-1)) + max((long long)0, b % ((long long)1 << i) - ((long long)1 << (i - 1))));
    }
    return abs(bitsA - bitsB);
}

long long twosCompliment(long a, long b) {
    long long ones = 0;
    if(a >= 0 && b >= 0) ones = bitsEncendidosPositivos(a,b);
    else if(a < 0 && b < 0) ones = bitsEncendidosNegativos(a,b);
    else if(a < 0 && b >= 0) ones = bitsEncendidosNegativos(-1,a) + bitsEncendidosPositivos(0,b);
    else ones = bitsEncendidosNegativos(-1,b) + bitsEncendidosPositivos(0,a);
    return ones;

}

int main(){
    int t;
    vector<pair<long,long>> ranges;
    cin >> t;
    for(int i =0; i < t; i++){
        int a,b;
        cin >> a >> b;
        ranges.push_back(make_pair(a,b));
    }
    for(auto r: ranges)
        cout << twosCompliment(r.first,r.second) << "\n";
}