/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::detectCycle(ListNode* A) {
    unordered_set<ListNode*> s;
    
    ListNode* temp=A;
    
    while(temp)
    {
        if(s.find(temp)!=s.end())
        {
            return temp;
        }
        else
        {
            s.insert(temp);
        }
        temp=temp->next;
    }
    
    return NULL;
}
