
SinglyLinkedListNode {
    int data;
    SinglyLinkedListNode* next;
};
 
SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* head, int data, int position) {
    SinglyLinkedListNode* auxNode = head;
    for(int i = 1; auxNode; auxNode = auxNode->next, i++){
        if(i == position){
            SinglyLinkedListNode* newNode = (SinglyLinkedListNode*)malloc(sizeof(SinglyLinkedListNode));
            newNode->data = data;
            newNode->next = auxNode->next;
            auxNode->next = newNode;
        }
    }
    return head;
}
