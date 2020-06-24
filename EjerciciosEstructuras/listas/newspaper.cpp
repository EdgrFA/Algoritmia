//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2315
#include <bits/stdc++.h>
using namespace std;

class Words{
    public:
        char c;
        int cost;
        vector<Words> nextC;

        Words(char c, int cost): 
            c(c), cost(cost){}

        Words* nextChar(char c){
            if(nextC.empty()) return NULL;
            Words *w = NULL;
            for(auto nC: nextC){
                if(nC.c == c){
                    *w = nC;
                    break; 
                }
            }
            return w;
        }

        Words* addChar(char c, int newCost){
            Words *newW = new Words(c,cost+newCost);
            nextC.push_back(*newW);
            return newW;
        }
};

bool isSign(char c){
    if(65 <= c && c <= 90) return false;
    if(97 <= c && c <= 122) return false;
    return true;
}

int getCost(char c, vector<pair<char,int>> &paidChrs){
    int cost = 0;
    for(auto paidC: paidChrs){
        if(paidC.first == c){
            cost = paidC.second;
            break;
        }
    }
    return cost;
}

long long stringCost(string line, vector<pair<char,int>> paidChrs, vector<Words> &Dictionary){
    long long totalCost = (long long)0;
    bool newWord = true;
    Words *auxWords = NULL;
    for(auto c: line){
        if(isSign(c)){
            totalCost += (long long)getCost(c,paidChrs);
            if(!newWord){
                totalCost += (long long)auxWords->cost;
                auxWords = NULL;
            }
            newWord = true;
            continue;
        }
        if(newWord){
            for(auto w: Dictionary){
                if(w.c == c){
                    auxWords = &w;
                    break;
                }
            }
            if(Dictionary.empty() || auxWords == NULL){
                auxWords = new Words(c, getCost(c,paidChrs));
                Dictionary.push_back(*auxWords);
            }
            newWord = false;
        }else{
            Words *auxW = auxWords->nextChar(c);
            if(auxW == NULL) auxWords = auxWords->addChar(c,getCost(c,paidChrs));
            else auxWords = auxW;
        }
    }
    if(!newWord) totalCost += (long long)auxWords->cost;
    return totalCost;
}

void imprimirFormato(string cost){
    if(cost.size() > 2) for(int i = 0; i+2 < cost.size(); i++) cout << cost[i];
    else cout << "0";

    string cents;
    if(cost.size() == 1) cents = ".0" + cost.substr(cost.size()-1,1);
    else cents =  "." + cost.substr(cost.size()-2,2);
    cout << cents << "$\n";
}

int main(){
    int n, k;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> k;
        vector<pair<char,int>> paidChrs;
        char c;
        int p;
        for(int j = 0; j < k; j++){
            cin >> c >> p;
            paidChrs.push_back(make_pair(c,p));
        }

        int m;
        cin >> m;        
        vector<Words> Dictionary;
        long long cost = (long long)0;
        string line, ws;
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        for(int j = 0; j < m; j++){
            getline(cin, line);
            cost += stringCost(line, paidChrs, Dictionary);
        }
        imprimirFormato(to_string(cost));
    }
}

// int main(){
//     ifstream inFile;
//     inFile.open("InputsOutputs/inputNewspaper3.txt");
//     if (!inFile) {
//         cout << "Unable to open file";
//         exit(1); // terminate with error
//     }

//     int n, k;
//     inFile >> n;
//     inFile.ignore(numeric_limits<streamsize>::max(), '\n');
//     for(int i = 0; i < n; i++){
//         inFile >> k;
//         inFile.ignore(numeric_limits<streamsize>::max(), '\n');
//         vector<pair<char,int>> paidChrs;
//         char c;
//         int p;
//         for(int j = 0; j < k; j++){
//             inFile >> c >> p;
//             inFile.ignore(numeric_limits<streamsize>::max(), '\n');
//             paidChrs.push_back(make_pair(c,p));
//         }
//         int m;
//         inFile >> m;        
//         vector<Words> Dictionary;
//         long long cost = (long long)0;
//         string line, ws;
//         inFile.ignore(numeric_limits<streamsize>::max(),'\n');
//         for(int j = 0; j < m; j++){
//             getline(inFile, line);
//             cost += stringCost(line, paidChrs, Dictionary);
//         }
//         imprimirFormato(to_string(cost));
//     }
//     inFile.close();
// }