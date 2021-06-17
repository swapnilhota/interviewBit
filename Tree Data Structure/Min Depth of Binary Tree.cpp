/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
int solve(TreeNode* A, int ans)
{
    if(A->left==NULL && A->right==NULL)
    {
        return ans;
    }
    else if(A->right==NULL)
    {
        return solve(A->left, ans+1);
    }
    else if(A->left==NULL)
    {
        return solve(A->right, ans+1);
    }
    else
    {
        return min(solve(A->left, ans+1), solve(A->right, ans+1));
    }
}
 
int Solution::minDepth(TreeNode* A) {
    
    if(A==NULL)
    {
        return 0;
    }
    
    return solve(A, 1);
    
}
