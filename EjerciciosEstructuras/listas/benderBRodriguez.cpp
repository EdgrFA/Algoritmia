//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2502
#include <bits/stdc++.h>
using namespace std;

 map<bool,char> signC = {{0,'+'},{1,'-'}};
 map<int,char> axisC = {{0,'x'},{1,'y'},{2,'z'}};

string directionPointed(vector<pair<bool,int>> bendings){
    pair<bool,int> axis(0,0);
    for(auto bndg: bendings){
        if(axis.second == 0){
            axis.second = bndg.second;
            if(axis.first == 0) axis.first = bndg.first;
            else axis.first = !bndg.first;
        }else{
            if(axis.second == bndg.second) axis.first = !(axis.first^bndg.first);
            if(axis.second == 1) axis.second = bndg.second-1;
            else axis.second = (bndg.second+1)%3;
        }
    }
    string answ;
    answ.push_back(signC.find(axis.first)->second);
    answ.push_back(axisC.find(axis.second)->second);
    return answ;
}

int main(){
    int L;
    cin >> L;
    vector<string> outputs;
    while(L) { 
        vector<pair<bool,int>> bendings;
        string str;
        bool sign;
        int axis;
        for(int i = 1; i < L; i++){
            cin >> str;
            if(str[0] == 'N') continue;
            if(str[0] == '+') sign = 0;
            else sign = 1;
            if(str[1] == 'x') axis = 0;
            else if(str[1] == 'y') axis = 1;
            else axis = 2;
            bendings.push_back(make_pair(sign,axis));
        }
        outputs.push_back(directionPointed(bendings));
        cin >> L;
    }
    for(auto otpt: outputs)
        cout << otpt << "\n";
}