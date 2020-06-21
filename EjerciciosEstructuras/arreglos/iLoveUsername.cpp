//https://codeforces.com/problemset/problem/155/A
#include <bits/stdc++.h>
using namespace std;

int amazingScores(vector<int> scores){
    int max = scores[0], min = scores[0], amazingC = 0;
    for(auto score: scores){
        if(score < min) amazingC++, min = score;
        else if(score > max) amazingC++, max = score;
    }
    return amazingC;
}

int main(){
    int n;
    vector<int> scores;
    cin >> n;
    for(int i = 0; i < n; i++){
        int sc;
        cin >> sc;
        scores.push_back(sc);
    }
    cout << amazingScores(scores);
}

// int main(){
//     int n;
//     vector<int> scores;
//     ifstream inFile;
//     inFile.open("InputsOutputs/inputLoveUserName.txt");
//     if (!inFile) {
//         cout << "Unable to open file";
//         exit(1); // terminate with error
//     }

//     inFile >> n;
//     inFile.ignore(numeric_limits<streamsize>::max(), '\n');
//     for(int i = 0; i < n; i++){
//         int sc;
//         inFile >> sc;
//         scores.push_back(sc);
//     }
//     inFile.ignore(numeric_limits<streamsize>::max(), '\n');
//     inFile.close();
//     cout << amazingScores(scores);
// }