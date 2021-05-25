/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int Solution::solve(ListNode* A, int B) {
    
    int n=0;
    ListNode* temp=A;
    
    while(temp)
    {
        n++;
        temp=temp->next;
    }
    
    int mid = (n/2)+1;
    
    int idx = mid-B;
    
    if(idx<=0)
    {
        return -1;
    }
    
    temp=A;
    
    int ans;
    
    while(idx>0)
    {
        idx--;
        ans=temp->val;
        temp=temp->next;
    }
    
    return ans;
    
}
