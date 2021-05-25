/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) {
    
    ListNode* t1=A;
    ListNode* t2=B;
    
    ListNode* ans=NULL;
    
    if(t1->val<t2->val)
    {
        ans=new ListNode(t1->val);
        t1=t1->next;
    }
    else
    {
        ans=new ListNode(t2->val);
        t2=t2->next;
    }
   
    ListNode* t3 = ans;
    
    while(t1 && t2)
    {
        if(t1->val<t2->val)
        {
            if(t3==NULL)
            {
                ans=new ListNode(t1->val);
                t3=ans;
            }
            else
            {
                t3->next=new ListNode(t1->val);
                t3=t3->next;
            }
            t1=t1->next;
        }
        else
        {
            if(t3==NULL)
            {
                ans=new ListNode(t2->val);
            }
            else
            {
                t3->next=new ListNode(t2->val);
                t3=t3->next;
            }
            t2=t2->next;
        }
    }
    
    while(t1)
    {
        if(t3==NULL)
        {
            ans=new ListNode(t1->val);
            t3=ans;
        }
        else
        {
            t3->next=new ListNode(t1->val);
            t3=t3->next;
        }
        t1=t1->next;
    }
    
    while(t2)
    {
        if(t3==NULL)
        {
            ans=new ListNode(t2->val);
            t3=ans;
        }
        else
        {
            t3->next=new ListNode(t2->val);
            t3=t3->next;
        }
        t2=t2->next;
    }
    
    return ans;
    
}
