/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::hasPathSum(TreeNode* A, int B) {
    
    if(A==NULL)
    {
        return 0;
    }
    
    if(A->left==NULL && A->right==NULL)
    {
        if(B==A->val)
        {
            return 1;
        }
        
        return 0;
    }
    else if(A->left==NULL)
    {
        return hasPathSum(A->right, B-A->val);
    }
    else if(A->right==NULL)
    {
        return hasPathSum(A->left, B-A->val);
    }
    
    
    return hasPathSum(A->left, B-A->val) || hasPathSum(A->right, B-A->val);
    
}
