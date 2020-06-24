//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2899
#include <bits/stdc++.h>
using namespace std;

int clownMinimumSpeed(vector<int> creatures){
    int minSpeed = 0;
    for(auto crtr : creatures)
        minSpeed = max(minSpeed, crtr);
    return minSpeed;
}

int main(){
    int t, n, c;
    cin >> t;
    vector<vector<int>> testCases;
    for(int i = 1; i <= t; i++){
        vector<int> creatures;
        cin >> n;
        for(int j = 0; j < n; j++){
            cin >> c;
            creatures.push_back(c);
        }
        testCases.push_back(creatures);
    }
    for(int i = 0; i < t; i++)
        cout << "Case " << (i+1) << ": " << clownMinimumSpeed(testCases[i]) << "\n";
}

// int main(){
//     int t, n, c;
//     ifstream inFile;
//     inFile.open("InputsOutputs/inputHorrorDash.txt");
//     if (!inFile) {
//         cout << "Unable to open file";
//         exit(1); // terminate with error
//     }
//     inFile >> t;
//     inFile.ignore(numeric_limits<streamsize>::max(), '\n');
//     vector<vector<int>> testCases;
//     for(int i = 1; i <= t; i++){
//         vector<int> creatures;
//         inFile >> n;
//         for(int j = 0; j < n; j++){
//             inFile >> c;
//             creatures.push_back(c);
//         }
//         inFile.ignore(numeric_limits<streamsize>::max(), '\n');
//         testCases.push_back(creatures);
//     }
//     inFile.close();
//     for(int i = 0; i < t; i++)
//         cout << "Case " << (i+1) << ": " << clownMinimumSpeed(testCases[i]) << "\n";
// }
