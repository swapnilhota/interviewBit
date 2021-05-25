/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::solve(ListNode* A) {
    
    int cnt_zeroes=0;
    int cnt_ones=0;
    
    ListNode* temp=A;
    
    while(temp)
    {
        if(temp->val==1)
        {
            cnt_ones++;
        }
        else
        {
            cnt_zeroes++;
        }
        temp=temp->next;
    }
    
    if(cnt_ones==0 || cnt_zeroes==0)
    {
        return A;
    }
    
    temp=A;
    
    while(cnt_zeroes>0)
    {
        temp->val=0;
        temp=temp->next;
        cnt_zeroes--;
    }
    
    while(cnt_ones>0)
    {
        temp->val=1;
        temp=temp->next;
        cnt_ones--;
    }
    
    return A;
    
}
