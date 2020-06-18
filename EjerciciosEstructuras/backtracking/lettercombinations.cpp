//https://leetcode.com/problems/letter-combinations-of-a-phone-number/
#include <bits/stdc++.h>
using namespace std;

const string letters[8] = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

void getAllCombinations(string digits, int index, string combination, vector<string> *combinations){
    if(index >= digits.size()){
        combinations->push_back(combination);
        return;
    }
    int i = digits[index] - '2';
    for(auto letter: letters[i])
        getAllCombinations(digits, index+1, combination + letter, combinations);
}
vector<string> letterCombinations(string digits) {
    vector<string> *combinations = new vector<string>;
    if(!digits.empty()) getAllCombinations(digits,0,"",combinations);
    return *combinations;
}

int main(){
    //digitos solo del 2 al 9
    string digits;
    cin >> digits;
    vector<string> answ = letterCombinations(digits);
    for(auto combination : answ) cout << combination << "\n";
}