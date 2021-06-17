/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
void solve(TreeNode* &A)
{
    if(A==NULL)
    {
        return;
    }
    swap(A->left, A->right);
    solve(A->left);
    solve(A->right);
}
 
TreeNode* Solution::invertTree(TreeNode* A) {
    
    if(A==NULL)
    {
        return A;
    }
    
    solve(A);
    
    return A;
    
}
