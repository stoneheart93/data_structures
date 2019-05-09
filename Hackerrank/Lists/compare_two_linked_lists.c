/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
bool compare_lists(SinglyLinkedListNode* a, SinglyLinkedListNode* b) 
{
    if(a == NULL && b == NULL)
        return true;
    else if(a != NULL && b != NULL)
        return (a->data == b->data && compare_lists(a->next, b->next));
    else
        return 0;
}

