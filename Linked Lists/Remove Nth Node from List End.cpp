/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::removeNthFromEnd(ListNode* A, int B) {
    
    int n=0;
    ListNode* temp=A;
    
    while(temp)
    {
        n++;
        temp=temp->next;
    }
    
    if(B>=n)
    {
        A=A->next;
        return A;
    }
    
    int idx = n-B;
    
    int i=0;
    
    temp=A;
    
    while(i<idx-1)
    {
        temp=temp->next;
        i++;
    }
    
    temp->next = temp->next->next;
    
    return A;
    
}
