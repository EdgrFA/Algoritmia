//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3139
#include <bits/stdc++.h>
using namespace std;

void printLine(list<char> line){
    for(auto l: line)
        cout << l;
}

int main(){
    char c;
    bool home = false;
    list<char> line, hline;
    while((c = getchar()) != EOF){
        if(c == '[' || c == ']' || c == '\n') {
            if(home && !hline.empty()){
                line.insert(line.begin(),hline.begin(),hline.end());
                hline.clear();
            }
            if(c == '[') home = true; 
            else if(c == ']') home = false;
            else {
                printLine(line);
                line.clear();
                cout << "\n";
            }
        } else if(home){
            hline.push_back(c);
        } else line.push_back(c);
    }
    if(!hline.empty()) line.insert(line.begin(),hline.begin(),hline.end());
    printLine(line);
}