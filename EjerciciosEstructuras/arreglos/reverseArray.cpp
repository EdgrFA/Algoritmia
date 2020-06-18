#include <bits/stdc++.h>
using namespace std;

// Complete the reverseArray function below.
vector<int> reverseArray(vector<int> a) {
    vector<int> reverseVector;
    for(int i = a.size()-1; i >= 0; i--)
        reverseVector.push_back(a[i]);
    return reverseVector;
}