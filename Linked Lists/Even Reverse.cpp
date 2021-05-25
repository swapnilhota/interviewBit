/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::solve(ListNode* A) {
    
    stack<int> even;
    
    ListNode* temp=A;
    
    int i=1;
    
    while(temp)
    {
        if(i%2==0)
        {
            even.push(temp->val);
        }
        i++;
        temp=temp->next;
    }
    
    i=1;
    
    temp=A;
    
    while(temp)
    {
        if(i%2==0)
        {
            temp->val=even.top();
            even.pop();
        }
        i++;
        temp=temp->next;
    }
    
    return A;
    
}
