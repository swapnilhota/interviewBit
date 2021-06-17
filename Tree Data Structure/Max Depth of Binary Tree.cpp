/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int solve(TreeNode* node, int ans)
{
    if(node->left==NULL && node->right==NULL)
    {
        return ans;
    }
    else if(node->left==NULL)
    {
        return solve(node->right, ans+1);
    }
    else if(node->right==NULL)
    {
        return solve(node->left, ans+1);
    }
    
    ans++;
    
    return max(solve(node->left, ans), solve(node->right, ans));
}
 
int Solution::maxDepth(TreeNode* A) {
    
    if(A==NULL)
    {
        return 0;
    }
    
    return solve(A, 1);
    
}
