//https://www.hackerrank.com/challenges/crush/problem
#include <bits/stdc++.h>
using namespace std;

// Alta Complejidad
long long arrayManipulationFuerzaBruta(int n, vector<vector<int>> queries) {
    vector<long long> array(n,(long long)0);
    for(auto querie: queries){
        for(int i = querie[0]; i <= querie[1]; i++){
            array[i-1] += (long long)querie[2];
        }
    }
    long long maxValue = (long long)0;
    for(auto a: array) maxValue = max(maxValue, a);
    return maxValue;
}

long long arrayManipulation(int n, vector<vector<int>> queries) {
    vector<long long> array(n,(long long)0);
    for(auto querie: queries){
        array[querie[0]-1] += (long long)querie[2];
        if(querie[1] < n) array[querie[1]] -= (long long)querie[2];
    }
    long long maxValue = (long long)0;
    long long suma = (long long)0;
    for(int i = 0; i < n; i++) {
        if(array[i] == 0) continue;
        suma += array[i];
        maxValue = max(maxValue, suma);
    } 
    return maxValue;
}

// int main(){
//     int n,m;
//     cin >> n >> m;
//     vector<vector<int>> queries;
//     for(int i = 0; i < m; i++){
//         int a,b,k;
//         cin >> a >> b >> k;
//         vector<int> querie{a,b,k};
//         queries.push_back(querie);
//     }
//     cout << arrayManipulation(n,queries) << "\n";
// }

int main(){
    ifstream inFile;
    inFile.open("InputsOutputs/inputArrayManipulation2.txt");
    if (!inFile) {
        cout << "Unable to open file";
        exit(1); // terminate with error
    }
    int n,m;
    inFile >> n >> m;
    inFile.ignore(numeric_limits<streamsize>::max(), '\n');
    vector<vector<int>> queries;
    for(int i = 0; i < m; i++){
        int a,b,k;
        inFile >> a >> b >> k;
        inFile.ignore(numeric_limits<streamsize>::max(), '\n');
        vector<int> querie{a,b,k};
        queries.push_back(querie);
    }
    inFile.close();
    cout << arrayManipulation(n,queries) << "\n";
}

//inputArrayManipulation