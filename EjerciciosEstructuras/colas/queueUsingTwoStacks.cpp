//https://www.hackerrank.com/challenges/queue-using-two-stacks/problem
#include <bits/stdc++.h>
using namespace std;

int main() {
    int q, type;

    ifstream inFile;
    inFile.open("input15.txt");
    if (!inFile) {
        cout << "Unable to open file";
        exit(1); // terminate with error
    }

    inFile >> q;
    inFile.ignore(numeric_limits<streamsize>::max(), '\n');
    stack<int> queueStack, frontStack;
    for(int i = 0; i < q; i++){
        inFile >> type;
        if(type == 1){
            int x;
            inFile >> x;
            queueStack.push(x);
        }
        else{
            if(frontStack.empty()){
                if(queueStack.empty()) continue;
                while(!queueStack.empty()){
                    frontStack.push(queueStack.top());
                    queueStack.pop();
                }
            }

            if(type == 2) frontStack.pop();
            else cout << frontStack.top() << "\n";
        }
        inFile.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    inFile.close();
    return 0;
}