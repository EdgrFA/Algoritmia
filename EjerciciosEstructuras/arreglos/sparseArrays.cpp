//https://www.hackerrank.com/challenges/sparse-arrays/problem
#include <bits/stdc++.h>
using namespace std;

// Complete the matchingStrings function below.
vector<int> matchingStrings(vector<string> strings, vector<string> queries) {
    int qSize = queries.size();
    vector<int> matchedStrings(qSize,0);
    for(auto string: strings){
        for(int i = 0; i < qSize; i++){
            if(string.size() != queries[i].size()) continue;
            bool sameString = true;
            for(int j = 0; j < string.size(); j++){
                if(string[j] != queries[i][j]){ 
                    sameString = false; 
                    break;
                }
            }
            if(sameString) matchedStrings[i]++;
        }
    }
    return matchedStrings;
}

int main(){
    vector<string> strings, queries; // 0 <= strings[i],queries[i] <= 20
    int s,q; // 0 <= s,q <= 1000
    cin >> s;
    for(int i = 0; i < s; i++){
        string str;
        cin >> str;
        strings.push_back(str);
    }
    cin >> q;
    for(int i = 0; i < q; i++){
        string str;
        cin >> str;
        queries.push_back(str);
    }
    for(auto mString: matchingStrings(strings,queries))
        cout << mString << "\n";
}

// int main(){
//     ifstream inFile;
//     inFile.open("InputsOutputs/InputSparseArrays.txt");
//     if (!inFile) {
//         cout << "Unable to open file";
//         exit(1); // terminate with error
//     }

//     vector<string> strings, queries;
//     int s,q;
//     inFile >> s;
//     inFile.ignore(numeric_limits<streamsize>::max(), '\n');
//     for(int i = 0; i < s; i++){
//         string str;
//         inFile >> str;
//         inFile.ignore(numeric_limits<streamsize>::max(), '\n');
//         strings.push_back(str);
//     }

//     inFile >> q;
//     inFile.ignore(numeric_limits<streamsize>::max(), '\n');
//     for(int i = 0; i < q; i++){
//         string str;
//         inFile >> str;
//         inFile.ignore(numeric_limits<streamsize>::max(), '\n');
//         queries.push_back(str);
//     }
//     for(auto mString: matchingStrings(strings,queries))
//         cout << mString << "\n";
//     return 0;
// }