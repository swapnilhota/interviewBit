/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::isSameTree(TreeNode* A, TreeNode* B) {
    
    if(A==NULL && B==NULL)
    {
        return true;
    }
    else if(A==NULL)
    {
        return false;
    }
    else if(B==NULL)
    {
        return false;
    }
    else if(A->val!=B->val)
    {
        return false;
    }
    else
    {
        return isSameTree(A->left, B->left) && isSameTree(A->right, B->right);
    }
    
}
