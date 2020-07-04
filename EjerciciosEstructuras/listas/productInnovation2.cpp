//https://codeforces.com/gym/100090
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, p, e;
    cin >> n >> p;
    list<int> elements;
    for(int i = 0; i < n; i++){
        cin >> e;
        elements.push_back(e);
    }
    int q, x = 0;

    string command;
    cin >> q;
    auto it = elements.begin();
    it = next(it,--p);
    for(int i = 0; i < q; i++, x = 0){
        cin >> command;
        if(command[0] == 'p') cout << *it << "\n";
        else if(command[0] == 'm'){
            if(command[4] == 'L' && it != elements.begin()) it--;
            else if(command[4] == 'R' && it != --elements.end()) it++;
        }else{
            cin >> x;
            if(command[6] == 'L') elements.insert(it,x);
            else if(command[6] == 'R') elements.insert(next(it,1),x);
        }
    }
}