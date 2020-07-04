#include <bits/stdc++.h>
using namespace std;

int main(){
    list<int> lst;
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);
    lst.push_back(4);
    lst.push_back(5);
    auto it = lst.begin();
    advance(it,6);
    cout << *it << "\n";
}