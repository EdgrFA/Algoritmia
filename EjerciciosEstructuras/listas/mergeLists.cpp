//https://www.hackerrank.com/challenges/merge-two-sorted-linked-lists/problem
#include <bits/stdc++.h>
using namespace std;

struct SinglyLinkedListNode {
    int data;
    SinglyLinkedListNode* next;
};
 
SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    if(head1 == NULL) return head2;
    if(head2 == NULL) return head1;

    SinglyLinkedListNode* auxFL = head1;
    SinglyLinkedListNode* auxSL = head2;
    SinglyLinkedListNode* mergeListHead;

    if(head1->data <= head2->data) {
        mergeListHead = auxFL;
        auxFL = auxFL->next;
    }else{
        mergeListHead = auxSL;
        auxSL = auxSL->next;
    }

    SinglyLinkedListNode* auxML = mergeListHead;
    while(true){
        if(!auxFL){
            auxML->next = auxSL;
            break;
        }
        if(!auxSL){
            auxML->next = auxFL;
            break;
        }

        if(auxFL->data < auxSL->data){
            auxML->next = auxFL;
            auxFL = auxFL->next;
        }else {
            auxML->next = auxSL;
            auxSL = auxSL->next;
        }
        auxML = auxML->next;
    }
    return mergeListHead;
}
