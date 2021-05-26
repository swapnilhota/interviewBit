/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseList(ListNode* A, int B) {
    
    ListNode* f=A;
    ListNode* s=A;
    
    stack<int> stk;
    
    int cnt=0;
    
    while(f)
    {
        while(cnt<B)
        {
            stk.push(s->val);
            s=s->next;
            cnt++;
        }
        while(f!=s)
        {
            f->val=stk.top();
            stk.pop();
            f=f->next;
        }
        cnt=0;
    }
    
    return A;
    
}
