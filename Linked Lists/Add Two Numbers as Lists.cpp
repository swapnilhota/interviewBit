/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B) {
    
    ListNode* t1=A;
    ListNode* t2=B;
    
    int n1=0;
    int n2=0;
    
    while(t1)
    {
        n1++;
        t1=t1->next;
    }
    
    while(t2)
    {
        n2++;
        t2=t2->next;
    }
    
    if(n1<n2)
    {
        return addTwoNumbers(B, A);
    }
    
    t1=A;
    t2=B;
    
    int carry=0;
    
    while(t1->next && t2->next)
    {
        int x = t1->val + t2->val + carry;
        carry = x/10;
        x = x%10;
        
        t1->val = x;
        
        t1=t1->next;
        t2=t2->next;
    }
    
    if(t1->next==NULL && t2->next==NULL)
    {
        int x = t1->val + t2->val + carry;
        carry = x/10;
        x = x%10;
        
        t1->val = x;
        
        if(carry>0)
        {
            t1->next=new ListNode(carry);
        }
        
        return A;
    }
    
    //t2->next==NULL
    
    int temp = t1->val + t2->val + carry;
    carry = temp/10;
    temp=temp%10;
    
    t1->val = temp;
    t1=t1->next;
    
    while(t1->next)
    {
        int x = t1->val+carry;
        carry=x/10;
        x=x%10;
        
        t1->val=x;
        t1=t1->next;
    }
    
    temp = t1->val+carry;
    carry=temp/10;
    temp=temp%10;
    
    t1->val = temp;
    
    if(carry>0)
    {
        t1->next=new ListNode(carry);
    }
    
    return A;
    
}
