//https://www.hackerrank.com/challenges/reverse-a-linked-list/problem
#include <bits/stdc++.h>
using namespace std;

struct SinglyLinkedListNode {
    int data;
    SinglyLinkedListNode* next;
};

SinglyLinkedListNode* reverse(SinglyLinkedListNode* head) {
    if(head == NULL)
        return head;
        
    SinglyLinkedListNode* auxNode = NULL;
    SinglyLinkedListNode* auxHead = head->next;
    head->next = NULL;
    while(auxHead){
        auxNode = auxHead;
        auxHead = auxHead->next;
        auxNode->next = head;
        head = auxNode;
    }
    return head;
}