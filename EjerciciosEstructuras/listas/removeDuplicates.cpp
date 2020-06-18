//https://www.hackerrank.com/challenges/delete-duplicate-value-nodes-from-a-sorted-linked-list/problem
#include <bits/stdc++.h>
using namespace std;

struct SinglyLinkedListNode {
	int data;
	SinglyLinkedListNode* next;
};

SinglyLinkedListNode* removeDuplicates(SinglyLinkedListNode* head) {
    SinglyLinkedListNode* auxNode = head;
    while(auxNode){
        SinglyLinkedListNode* lastNode = auxNode;
        while(auxNode && auxNode->data == lastNode->data)
            auxNode = auxNode->next;
        lastNode->next = auxNode;
    }
    return head;
}