/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
void solve(TreeNode* node, int k, priority_queue<int> &max_heap)
{
    if(node==NULL)
    {
        return;
    }
    max_heap.push(node->val);
    if(max_heap.size()>k)
    {
        max_heap.pop();
    }
    solve(node->left, k, max_heap);
    solve(node->right, k, max_heap);
}
 
int Solution::kthsmallest(TreeNode* A, int B) {
    
    priority_queue<int> max_heap;
    
    solve(A, B, max_heap);
    
    return max_heap.top();
    
}
