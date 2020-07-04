#include <bits/stdc++.h>
using namespace std;

/**
entradas
n -> tamaño del vector
s -> semilla
x -> no de elementos
xi -> elementos
**/

class Lista{
    public:
        string str;
        int frec;
        Lista* next;

        Lista(string strC, int frecC){
            str = strC;
            frec = frecC;
            next = NULL;
        }
};

int algoritmoHash(string str, int sem, int nmax){
    unsigned int hash = 0;
    for(int i = 1; i <= str.size(); i++)
        hash += (unsigned int)(pow(sem,str.size()-i)*(str[i-1]-32));
    return hash%nmax;
}

void insertarElemento(string str, int sem, vector<Lista*> &tablaH){
    int pos = algoritmoHash(str,sem,tablaH.size());
    if(tablaH[pos] == NULL){
        Lista* newE = new Lista(str,1);
        tablaH[pos] = newE;
        return;
    }
    Lista* ptrAux;
    for(ptrAux = tablaH[pos]; ptrAux != NULL; ptrAux = ptrAux->next){
        if(ptrAux->str.compare(str) == 0){
            ptrAux->frec++;
            return;
        }
        if(ptrAux->next == NULL) break;
    }
    ptrAux->next = new Lista(str,1);
}

void imprimirTabla(vector<Lista*> &tablaH){
    for(int i = 0; i < tablaH.size(); i++){
        cout << "C" << i << ": ";
        if(tablaH[i] == NULL) cout << "None\n";
        else{
            for(Lista* it = tablaH[i]; it != NULL; it = it->next){
                cout << "('" << it->str << "'," << it->frec << ")";
                if(it->next != NULL) cout << " -> ";
            }
            cout << "\n";
        }
    }
}

int main(){
    int n,s,x;
    string str;
    cin >> n >> s >> x;
    vector<Lista*> tablaH;
    for(int i = 0; i < n; i++)
        tablaH.push_back(NULL);
    for(int i = 0; i < x; i++){
        cin >> str;
        insertarElemento(str,s,tablaH);
    }
    imprimirTabla(tablaH);
}