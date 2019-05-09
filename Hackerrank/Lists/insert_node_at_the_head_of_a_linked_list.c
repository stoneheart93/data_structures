/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* insertNodeAtHead(SinglyLinkedListNode* head, int data) {
    struct SinglyLinkedListNode* temp = (struct SinglyLinkedListNode*)malloc(sizeof(struct SinglyLinkedListNode));
    temp->data = data;
    
    temp->next = head;
    return temp;

}
