//https://www.hackerrank.com/challenges/dynamic-array/problem
#include <bits/stdc++.h>
using namespace std;

vector<int> dynamicArray(int n, vector<vector<int>> queries) {
    vector<int> lastAnswers;
    vector<vector<int>> sequences(n);

    int lastAnswer = 0;
    for(int i = 0; i < queries.size(); i++){
        int index = (queries[i][1] ^ lastAnswer) % n;
        if(queries[i][0] == 1)
            sequences[index].push_back(queries[i][2]);
        else{
            lastAnswer = sequences[index][queries[i][2] % sequences[index].size()];
            lastAnswers.push_back(lastAnswer);
        }
    }
    return lastAnswers;
}