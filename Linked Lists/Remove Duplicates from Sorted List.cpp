/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* A) {
    
    ListNode* curr = A;
    ListNode* nxt = A; 
    
    while(nxt)
    {
        if(curr->val==nxt->val)
        {
            nxt=nxt->next;
        }
        else
        {
            curr->next=nxt;
            curr=curr->next;
        }
    }
    
    curr->next=NULL;
    
    return A;
    
}
