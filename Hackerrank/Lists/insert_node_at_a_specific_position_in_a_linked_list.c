// Complete the insertNodeAtPosition function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* head, int data, int position) {
    struct SinglyLinkedListNode* temp = (struct SinglyLinkedListNode*)malloc(sizeof(struct SinglyLinkedListNode));
    temp->data = data;
    
    if(position == 0)
    {
        temp->next = NULL;
        return temp;
    }
    else
    {
        struct SinglyLinkedListNode* rider = head;
        int i;
        for(i = 0; i < position - 1 && rider != NULL; i++)
            rider = rider->next;
        temp->next = rider->next;
        rider->next = temp;
        return head;
    }
}
