//https://www.hackerrank.com/challenges/counter-game/problem
#include <bits/stdc++.h>
using namespace std;

int contarBits(long long n){
    int c = 0;
    while (n) c++, n >>= 1;
    return c;
}

long long bitMasSignificativo(long long n){
    return (long long)1 << (contarBits(n)-1);
}

// Complete the counterGame function below.
string counterGame(long long n) {
    bool louiseWins = false;
    while(n > 1){
        cout << n << "\n";
        if((n & (n-1)) == 0) n >>= 1;
        else n = bitMasSignificativo(n) ^ n;
        louiseWins = !louiseWins;
    }
    if(louiseWins) return "Louise";
    return "Richard";
}


int main(){
    long long n;
    cin >> n;
    cout << counterGame(n);
}

// int main(){
//     ifstream inFile;
//     inFile.open("inOut/inputCF.txt");
//     if (!inFile) {
//         cout << "Unable to open file";
//         exit(1); // terminate with error
//     }

//     int t;
//     inFile >> t;
//     inFile.ignore(numeric_limits<streamsize>::max(), '\n');
//     vector<long long> numbers;
//     for (int i = 0; i < t; i++){
//         int n;
//         inFile >> n;
//         cout << (long long)n << "\n";
//         inFile.ignore(numeric_limits<streamsize>::max(), '\n');
//         numbers.push_back(n);
//     }
//     inFile.close();
//     for (int i = 0; i < t; i++)
//         cout << counterGame(numbers[i]) << "\n";
//     return 0;
// }