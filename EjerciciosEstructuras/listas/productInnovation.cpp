//https://codeforces.com/gym/100090
//TLE
#include <bits/stdc++.h>
using namespace std;

//print - 0
//moveLeft - 1
//moveRight - 2
//insertLeft - 3
//insertRight - 4
void executeCommands(list<int> elements, int pos, vector<pair<int,int>> commands){
    auto it = elements.begin();
    it = next(it,pos);
    for(auto command: commands){
        if(command.first == 0) cout << *it << "\n";
        else if(command.first == 1 && it != elements.begin()) it--;
        else if(command.first == 2 && it != --elements.end()) it++;
        else if(command.first == 3) elements.insert(it,command.second);
        else if(command.first == 4) elements.insert(next(it,1),command.second);
    }
}

int main(){
    int n, p, e;
    cin >> n >> p;
    list<int> elements;
    for(int i = 0; i < n; i++){
        cin >> e;
        elements.push_back(e);
    }
    int q, x = 0;
    vector<pair<int,int>> commands;
    string command;
    int cmmnd;
    cin >> q;
    for(int i = 0; i < q; i++, x = 0){
        cin >> command;
        if(command[0] == 'p') cmmnd = 0;
        else if(command[0] == 'm'){
            if(command[4] == 'L') cmmnd = 1;
            else cmmnd = 2;
        }else{
            if(command[6] == 'L') cmmnd = 3;
            else cmmnd = 4;
            cin >> x;
        }
        commands.push_back(make_pair(cmmnd,x));
    }
    executeCommands(elements, p-1, commands);
}

// if(command.find("insert") != string::npos)
//     cin >> x;