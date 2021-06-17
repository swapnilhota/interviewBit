/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void solve(TreeNode* A, int sum, int &ans)
{
    if(A==NULL)
    {
        return;
    }
    
    if(A->left==NULL && A->right==NULL)
    {
        sum = (sum*10)%1003;
        sum = (sum + A->val)%1003;
        ans = (ans+sum)%1003;
        return;
    }
    else if(A->left==NULL)
    {
        sum = (sum*10)%1003;
        sum = (sum + A->val)%1003;
        return solve(A->right, sum, ans);
    }
    else if(A->right==NULL)
    {
        sum = (sum*10)%1003;
        sum = (sum + A->val)%1003;
        return solve(A->left, sum, ans);
    }
    else
    {
        sum = (sum*10)%1003;
        sum = (sum + A->val)%1003;
        solve(A->left, sum, ans);
        solve(A->right, sum, ans);
        return;
    }
}

int Solution::sumNumbers(TreeNode* A) {
    
    if(A==NULL)
    {
        return 0;
    }
    
    int sum = 0;
    int ans = 0;
    
    solve(A, sum, ans);
    
    return ans;
    
}
