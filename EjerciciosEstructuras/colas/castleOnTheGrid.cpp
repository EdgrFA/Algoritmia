//https://www.hackerrank.com/challenges/castle-on-the-grid/problem#include <bits/stdc++.h>
#include <bits/stdc++.h>
using namespace std;

class Casilla{
    public:
        int pasos;
        int lastDirection = -1;
        pair<int,int> pos;
        pair<int,int> goal;
        vector<pair<int,int>> padres;

        Casilla(int pasos, int i, int j, int goalX, int goalY, vector<pair<int,int>> padres): 
            pasos(pasos), pos(i,j), goal(goalX, goalY), padres(padres){}

        Casilla(int pasos, int lastDirection, int i, int j, int goalX, int goalY, vector<pair<int,int>> padres):
            pasos(pasos), lastDirection(lastDirection), pos(i,j), goal(goalX, goalY), padres(padres){}

        pair<int,int> getDirecciones(int n){
            pair<int,int> posN;
            switch(n){
                case 0:
                    posN.first = pos.first-1; 
                    posN.second = pos.second;
                    return posN;
                case 1:
                    posN.first = pos.first; 
                    posN.second = pos.second+1;
                    return posN;
                case 2:
                    posN.first = pos.first+1; 
                    posN.second = pos.second;
                    return posN;
                case 3:
                    posN.first = pos.first; 
                    posN.second = pos.second-1;
                    return posN;                
            }
            return posN;
        }

        void imprimirCasilla(){
            int casillas = abs(pos.first-goal.first) + abs(pos.second-goal.second);
            cout << "Pasos: " << pasos << ", ";
            cout << "i,j: " << pos.first << "," << pos.second;
            cout << "| casillas: " << casillas << "\n";
        }

        void imprimirPadres(){
            cout << "PADRES:\n\n"; 
            for (int i = 0; i < padres.size(); i++){
                cout << "i,j: " << padres[i].first << "," << padres[i].second << "\n";
            }
        }
};

struct CompararCasillas{
    bool operator()(Casilla const& c1, Casilla const& c2) { 
        if(c1.pasos != c2.pasos)
            return c1.pasos > c2.pasos;
        else{
            pair<int,int> goal = c1.goal;
            int casillasC1 = abs(c1.pos.first-goal.first) + abs(c1.pos.second-goal.second);
            int casillasC2 = abs(c2.pos.first-goal.first) + abs(c2.pos.second-goal.second);
            return casillasC1 > casillasC2;
        }
    } 
};

// Complete the minimumMoves function below.
int minimumMoves(int size, char **grid, int startX, int startY, int goalX, int goalY) {
    priority_queue<Casilla, vector<Casilla>, CompararCasillas> pQ;

    int visitados[size][size];
    for (int i=0; i<size; i++){
        for (int j=0; j<size; j++){
            if(grid[i][j] == 'X')
                visitados[i][j] = -1;
            else
                visitados[i][j] = 0;
        }
    }
    vector<pair<int,int>> auxPad;
    pair<int,int> padre1(startX,startY);
    auxPad.push_back(padre1);
    Casilla cI(0,startX,startY,goalX,goalY,auxPad);
    // cI.imprimirCasilla();
    pQ.push(cI);
    while(!pQ.empty()){
        Casilla c = pQ.top();
        cout << "Top: ";
        c.imprimirCasilla();
        pQ.pop();
        if(c.pos.first == goalX && c.pos.second == goalY){
            c.imprimirPadres();
            return c.pasos;
        }
        if(visitados[c.pos.first][c.pos.second] < c.pasos && visitados[c.pos.first][c.pos.second] != 0)
            continue;
        visitados[c.pos.first][c.pos.second] = c.pasos;
        for(int opt = 0; opt < 4; opt++){
            pair<int,int> dir = c.getDirecciones(opt);
            int i = dir.first, j = dir.second;

            if(i >= 0 && i < size && j >= 0 && j < size && visitados[i][j] != -1){
                Casilla *cNew;
                vector<pair<int,int>> auxPad2 = c.padres;
                pair<int,int> padre2(i,j);
                auxPad2.push_back(padre2);
                if(c.lastDirection != opt){
                    cNew = new Casilla(c.pasos+1,opt,i,j,goalX,goalY,auxPad2);
                    pQ.push(*cNew);
                }else{
                    cNew = new Casilla(c.pasos,opt,i,j,goalX,goalY,auxPad2);
                    pQ.push(*cNew);
                }
            }
        }
    }
    return -1;
}


int main(){
    ifstream inFile;
    inFile.open("inputsCastleOnTheGrid/input00.txt");
    if (!inFile) {
        cout << "Unable to open file";
        exit(1); // terminate with error
    }

    int n, startX, startY, goalX, goalY;
    inFile >> n;
    inFile.ignore(numeric_limits<streamsize>::max(), '\n');

    char **grid = (char**)malloc(sizeof(char*)*n);
    for(int i = 0; i < n; i++)
        grid[i] = (char*)malloc(sizeof(char)*n);

    for (int i = 0; i < n; i++){
        inFile >> grid[i];
        inFile.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    inFile >> startX >> startY >> goalX >> goalY;
    inFile.ignore(numeric_limits<streamsize>::max(), '\n');
    inFile.close();

    int res = minimumMoves(n, grid, startX, startY, goalX, goalY);
    cout << res << "\n";
    
    return 0;
}

//input09 -> 79
//input08 -> 79
//input04 -> 7
//input00 -> 3