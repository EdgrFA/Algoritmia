//https://www.hackerrank.com/challenges/crush/problem
#include <bits/stdc++.h>
using namespace std;

struct SinglyLinkedListNode {
    int data;
    SinglyLinkedListNode* next;
};

//Guardando apuntadores pasados en una lista
bool has_cycle(SinglyLinkedListNode* head) {
    if(head == NULL) return 0;
    vector<SinglyLinkedListNode*> headers;
    headers.push_back(head);
    while(head = head->next){
        for(auto h: headers)
            if(h == head) return 1;
        headers.push_back(head);
    }
    return 0;
}

//Usando el metodo de la liebre y la tortuga
bool has_cycle2(SinglyLinkedListNode* head) {
    if(head == NULL) return 0;
    SinglyLinkedListNode* slow = head;
    SinglyLinkedListNode* fast = head;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
            return 1; 
    }
    return 0;
}