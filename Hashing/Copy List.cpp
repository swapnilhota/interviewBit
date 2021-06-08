/**
 * Definition for singly-linked list.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
 
RandomListNode* deepCopy(RandomListNode* A, unordered_map<RandomListNode*, RandomListNode*> &mp)
{
    if(!A)
    {
        return nullptr;
    }
    if(mp.find(A)==mp.end())
    {
        RandomListNode* tmp = new RandomListNode(A->label);
        mp[A] = tmp;
        tmp->next = deepCopy(A->next, mp);
        tmp->random = deepCopy(A->random, mp);
    }
    return mp[A];
}

RandomListNode* Solution::copyRandomList(RandomListNode* A) {
    
    unordered_map<RandomListNode*, RandomListNode*> mp;
    
    return deepCopy(A, mp);
    
}
