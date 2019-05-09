/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* a, SinglyLinkedListNode* b) 
{
    if(a == NULL)
        return b;
    if(b == NULL)
        return a;

    if(a->data <= b->data)
    {
        a->next = mergeLists(a->next, b);
        return a;
    }
    else   
    {
        b->next = mergeLists(a, b->next);
        return b;
    }
}

