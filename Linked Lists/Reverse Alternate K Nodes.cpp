/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::solve(ListNode* A, int B) {
    
    ListNode* temp=A;
    
    int cnt=0;
    bool flag=true;
    
    queue<int> q;
    stack<int> stk;
    
    while(temp)
    {
        while(cnt<B)
        {
            if(flag)
            {
                stk.push(temp->val);
            }
            else
            {
                q.push(temp->val);
            }
            cnt++;
            temp=temp->next;
        }
        
        if(!stk.empty())
        {
            while(!stk.empty())
            {
                q.push(stk.top());
                stk.pop();
            }
        }
        
        cnt=0;
        flag=(!flag);
        
    }
    
    temp=A;
    
    while(temp)
    {
        temp->val = q.front();
        q.pop();
        temp=temp->next;
    }
    
    return A;
    
}
