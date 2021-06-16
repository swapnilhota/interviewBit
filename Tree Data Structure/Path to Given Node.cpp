/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
void helper(TreeNode* node, int B, vector<int> tmp, vector<int> &ans)
{
    if(node==NULL)
    {
        return;
    }
    
    if(node->val==B)
    {
        tmp.push_back(B);
        ans=tmp;
        return;
    }
    
    tmp.push_back(node->val);
    helper(node->left, B, tmp, ans);
    helper(node->right, B, tmp, ans);
}
 
vector<int> Solution::solve(TreeNode* A, int B) {
    
    vector<int>  ans;
    
    vector<int> tmp;
    
    helper(A, B, tmp, ans);
    
    return ans;
}
