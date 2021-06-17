/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int helper(TreeNode* A, TreeNode* B)
{
    if(A==NULL && B==NULL)
    {
        return 1;
    }
    else if(A==NULL)
    {
        return 0;
    }
    else if(B==NULL)
    {
        return 0;
    }
    else if(A->val!=B->val)
    {
        return 0;
    }
    else
    {
        return helper(A->left, B->right) && helper(A->right, B->left);
    }
}

int Solution::isSymmetric(TreeNode* A) {
    
    if(A==NULL)
    {
        return true;
    }
    
    return helper(A->left, A->right);
    
}
