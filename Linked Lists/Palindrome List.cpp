/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int Solution::lPalin(ListNode* A) {
    
    stack<int> s;
    
    ListNode* temp=A;
    
    while(temp)
    {
        s.push(temp->val);
        temp=temp->next;
    }
    
    temp=A;
    
    while(temp)
    {
        if(temp->val!=s.top())
        {
            return 0;
        }
        s.pop();
        temp=temp->next;
    }
    
    return 1;
    
}
