/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::swapPairs(ListNode* A) {
    
    if(A==NULL)
    {
        return A;
    }
    
    ListNode* f = A;
    ListNode* s = f->next;
    ListNode* prev=f;
    
    if(s==NULL)
    {
        return A;
    }
    
    A=A->next;
    
    int cnt=1;
    
    while(f!=NULL && s!=NULL)
    {
        
        f->next = s->next;
        s->next = f;
        f = f->next;
        if(cnt>1)
        {
            prev->next=s;
            prev=s->next;
        }
        if(f==NULL)
        {
            break;
        }
        s = f->next;
        cnt++;
    }
    
    return A;
    
}
