/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
int getNode(SinglyLinkedListNode* head, int positionFromTail) {
    SinglyLinkedListNode* slowptr = head;
    SinglyLinkedListNode* fastptr = head;
    
    int i;
    for(i = 0; i < positionFromTail; i++)
        fastptr = fastptr->next;
    
    while(fastptr->next != NULL)
    {
        fastptr = fastptr->next;
        slowptr = slowptr->next;
    }
    return slowptr->data;
}

