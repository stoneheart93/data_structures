/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* deleteNode(SinglyLinkedListNode* head, int position) {
    
    if(position == 0)
    {
        SinglyLinkedListNode* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    else
    {
        SinglyLinkedListNode* rider = head;
    
        int i;
        for(i = 0; i < position - 1 && rider != NULL; i++)
            rider = rider->next;

        SinglyLinkedListNode* temp = rider-> next;
        rider->next = temp->next;
        free(temp);
        return head;
    }
}

