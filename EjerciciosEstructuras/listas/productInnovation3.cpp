//https://codeforces.com/gym/100090
//TLE
#include <bits/stdc++.h>
using namespace std;

class ElementList{
    public:
        int data;
        ElementList* prev;
        ElementList* next;

        ElementList(int d){
            data = d;
            prev = NULL;
            next = NULL;
        }
};

ElementList* insertRight(int newD, ElementList* standingOnE){
    ElementList* el = new ElementList(newD);
    ElementList* aux = standingOnE->next;
    standingOnE->next = el;
    el->prev = standingOnE;
    el->next = aux;
    if(aux) aux->prev = el;
    return el;
}

ElementList* insertLeft(int newD, ElementList* standingOnE){
    ElementList* el = new ElementList(newD);
    ElementList* aux = standingOnE->prev;
    standingOnE->prev = el;
    el->next = standingOnE;
    el->prev = aux;
    if(aux) aux->next = el;
    return el;
}

ElementList* nextEL(ElementList* standingOnE){
    if(standingOnE->next == NULL) return standingOnE;
    return standingOnE->next;
}

ElementList* prevEL(ElementList* standingOnE){
    if(standingOnE->prev == NULL) return standingOnE;
    return standingOnE->prev;
}

int main(){
    int n, p, a;
    cin >> n >> p;
    p--;

    ElementList* el = NULL;
    ElementList* standingOnE = NULL;
    for(int i = 0; i < n; i++){
        cin >> a;
        if(el == NULL)
            el = new ElementList(a);
        else
            el = insertRight(a,el);
        if(p == i)
            standingOnE = el;
    }

    int q, x = 0;
    string command;
    cin >> q;
    for(int i = 0; i < q; i++, x = 0){
        cin >> command;
        if(command[0] == 'p') cout << standingOnE->data << "\n";
        else if(command[0] == 'm'){
            if(command[4] == 'L') standingOnE = prevEL(standingOnE);
            else if(command[4] == 'R') standingOnE = nextEL(standingOnE);
        }else{
            cin >> x;
            if(command[6] == 'L') insertLeft(x,standingOnE);
            else if(command[6] == 'R') insertRight(x,standingOnE);
        }
    }
}