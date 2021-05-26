/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::partition(ListNode* A, int B) {
    
    queue<int> q;
    
    queue<int> idx;
    
    ListNode* temp=A;
    
    int i=0;
    
    while(temp)
    {
        if(temp->val<B)
        {
            q.push(temp->val);
            idx.push(i);
        }
        i++;
        temp=temp->next;
    }
    
    i=0;
    temp=A;
    
    while(temp)
    {
        if(idx.empty())
        {
            q.push(temp->val);
        }
        else
        {
            if(i==idx.front())
            {
                idx.pop();
            }
            else
            {
                q.push(temp->val);
            }
        }
        i++;
        temp=temp->next;
    }
    
    temp=A;
    
    while(temp)
    {
        temp->val=q.front();
        q.pop();
        temp=temp->next;
    }
    
    return A;
    
}
