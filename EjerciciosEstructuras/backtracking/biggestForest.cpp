//https://www.hackerearth.com/practice/basic-programming/recursion/recursion-and-backtracking/practice-problems/algorithm/biggest-forest-700592dd/description/
#include <bits/stdc++.h>
using namespace std;

const vector<pair<int,int>> movements{make_pair(1,0),make_pair(0,1),make_pair(-1,0),make_pair(0,-1)};

int asideTrees(int i, int j, vector<vector<bool>> &visited){
    if(i < 0 or j < 0 or i >= visited.size() or j >= visited.size() or visited[i][j] == true) return 0;
    int ntrees = 1;
    visited[i][j] = true;
    for(auto m: movements) 
        ntrees += asideTrees(i+m.first,j+m.second,visited);
    return ntrees;
}


int biggestForest(vector<vector<char>> forests){
    int size = forests.size();
    vector<vector<bool>> visited;
    for(int i = 0; i < size; i++){
        vector<bool> vaux;
        for(int j = 0; j < size; j++){
            if(forests[i][j] == 'W') vaux.push_back(true);
            else vaux.push_back(false);
        }
        visited.push_back(vaux);
    }
    int maxForest = 0;
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            if(visited[i][j] == true) continue;
            maxForest = max(asideTrees(i,j,visited), maxForest);
        }
    }
    return maxForest;
}

int main(){
    int n;
    cin >> n; //1<=N<=1000
    vector<vector<char>> forests;
    char c;
    for(int i = 0; i < n; i++){
        vector<char> faux;
        for(int j = 0; j < n; j++){
           cin >> c;
           faux.push_back(c);
        }
        forests.push_back(faux);
    }
    cout << biggestForest(forests);
}

// int main(){
//     ifstream inFile;
//     inFile.open("pruebaBF.txt");
//     if (!inFile) {
//         cout << "Unable to open file";
//         exit(1); // terminate with error
//     }

//     int n;
//     inFile >> n;
//     inFile.ignore(numeric_limits<streamsize>::max(), '\n');

//     vector<vector<char>> forests;
//     char c;
//     for(int i = 0; i < n; i++){
//         vector<char> faux;
//         for(int j = 0; j < n; j++){
//            inFile >> c;
//            faux.push_back(c);
//         }
//         inFile.ignore(numeric_limits<streamsize>::max(), '\n');
//         forests.push_back(faux);
//     }
//     inFile.close();
//     cout << biggestForest(forests);
//     return 0;
// }