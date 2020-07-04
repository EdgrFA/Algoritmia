//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1796
#include <bits/stdc++.h>
using namespace std;

const vector<pair<int,int>> movements{make_pair(0,1),make_pair(1,0),make_pair(0,-1),make_pair(-1,0)};

vector<char> squareToVector(vector<vector<char>> square){
    vector<char> vec;
    int n = square.size();
    int i = 0, j = 0, dir = 0, rec = 0, rep = 1;
    for(int x = 0; x < square.size()*square.size(); x++){
        vec.push_back(square[i][j]);
        if(++rec >= n){
            dir = (dir+1)%4;
            if(--rep == 0) n--, rep = 2;
            rec = 0;
        }
        pair<int,int> move = movements[dir];
        i += move.first;
        j += move.second;
    }
    return vec;
}

vector<int> rotatedSquare(int x, int y, int sizeSmSq, vector<vector<char>> &bigSq, vector<char> &smallSq){
    vector<int> frec(4,0);
    vector<pair<int,int>> initialIndex{make_pair(x,y),make_pair(x,y+sizeSmSq-1),make_pair(x+sizeSmSq-1,y+sizeSmSq-1),make_pair(x+sizeSmSq-1,y)};
    for(int r = 0; r < 4; r++){
        int lim = sizeSmSq;
        int i = initialIndex[r].first, j = initialIndex[r].second;
        int dir = r, rec = 0, rep = 1, z;
        for(z = 0; z < smallSq.size(); z++){
            if(bigSq[i][j] != smallSq[z]) break;
            if(++rec >= lim){
                dir = (dir+1)%4;
                if(--rep == 0) lim--, rep = 2;
                rec = 0;
            }
            pair<int,int> move = movements[dir];
            i += move.first;
            j += move.second;
        }
        if(z == smallSq.size()) frec[r]++; 
    }
    return frec;
}

vector<int> rotatedSquares(vector<vector<char>> &bigSquare, vector<vector<char>> &smallSquare){
    vector<int> frec(4,0);
    vector<char> smallSq = squareToVector(smallSquare);
    int limit =  bigSquare.size()-smallSquare.size();
    for(int i = 0; i <= limit; i++){
        for(int j = 0; j <= limit; j++){
            vector<int> resFrec = rotatedSquare(i,j,smallSquare.size(),bigSquare,smallSq);
            frec[0] += resFrec[0];
            frec[1] += resFrec[1];
            frec[2] += resFrec[2];
            frec[3] += resFrec[3];
        }
    }
    return frec;
}

int main(){
    int N, n;
    cin >> N >> n;
    vector<vector<int>> output;
    while(N != 0 && n != 0){
        vector<vector<char>> bigSquare;
        vector<vector<char>> smallSquare;
        char c;
        for(int i = 0; i < N; i++){
            vector<char> row;
            for(int j = 0; j < N; j++){
                cin >> c;
                row.push_back(c);
            }
            bigSquare.push_back(row);
        }
        for(int i = 0; i < n; i++){
            vector<char> row;
            for(int j = 0; j < n; j++){
                cin >> c;
                row.push_back(c);
            }
            smallSquare.push_back(row);
        }
        vector<int> frec(4,0);
        if(N != 0 && n != 0) frec = rotatedSquares(bigSquare,smallSquare);
        output.push_back(frec);
        cin >> N >> n;
    }
    for(auto otp: output)
        cout << otp[0] << " " << otp[1] << " " << otp[2] << " " << otp[3] << "\n";
}