/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* A) {
    
    map<int, int> m;
    
    ListNode* temp=A;
    
    while(temp)
    {
        m[temp->val]++;
        temp=temp->next;
    }
    
    temp=A;
    ListNode* prev;
    
    for(auto it:m)
    {
        if(it.second==1)
        {
            temp->val=it.first;
            prev=temp;
            temp=temp->next;
        }
    }
    
    if(temp==A)
    {
        return NULL;
    }
    
    prev->next=NULL;
    
    return A;
    
    
}
