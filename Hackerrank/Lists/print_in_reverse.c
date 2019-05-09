/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
void reversePrint(SinglyLinkedListNode* head) {
    if(head->next != NULL)
        reversePrint(head->next);

    printf("%d\n", head->data);

}

