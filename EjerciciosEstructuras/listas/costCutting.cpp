//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2827
#include <bits/stdc++.h>
using namespace std;

int survivorSalary(vector<int> salaries){
    for(int i=0; i < 3; i++){
        int a = i, b = (i+1)%3, c = (i+2)%3;
        if((salaries[a]<salaries[b]) == (salaries[b]<salaries[c]))
            return salaries[b];
    }
    return 0;
}

int main(){
    int t, s;
    cin >> t;
    vector<vector<int>> testCases;
    for(int i = 0; i < t; i++){
        vector<int> salaries;
        for(int j = 0; j < 3; j++){
            cin >> s;
            salaries.push_back(s);
        }
        testCases.push_back(salaries);
    }
    for(int i = 0; i < t; i++)
        cout << "Case " << (i+1) << ": " << survivorSalary(testCases[i]) << "\n";
}