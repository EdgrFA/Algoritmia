//https://www.hackerrank.com/challenges/array-left-rotation/problem
#include <bits/stdc++.h>
using namespace std;

void lefRotation(int rotations, vector<int> a){
    queue<int> pastNumbers;
    int qLenght = 0;
    int size = a.size();
    int r = rotations%size;
    for(int i = size-1; i >= 0; i--){
        int index = i-r;
        if(index < 0)
            index = size + index;

        pastNumbers.push(a[index]);
        if(pastNumbers.size() <= r)
            a[index] = a[i];
        else{
            a[index] = pastNumbers.front();
            pastNumbers.pop();
        }
    }
    for(int i = 0; i < size; i++)
        cout << a[i] << " ";
    cout << endl;
}