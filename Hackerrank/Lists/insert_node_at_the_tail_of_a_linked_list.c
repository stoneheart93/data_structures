/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* insertNodeAtTail(SinglyLinkedListNode* head, int data) {
    struct SinglyLinkedListNode* temp = (struct SinglyLinkedListNode*)malloc(sizeof(struct SinglyLinkedListNode));
    temp->data = data;
    temp->next = NULL;
    
    if(head == NULL)
        return temp;
    else
    {
        struct SinglyLinkedListNode* rider = head;
        while(rider->next != NULL)
            rider = rider->next;
        rider->next = temp;
        return head;
    }
}

