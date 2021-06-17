/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void helper(TreeNode* A, map<int, int> &mp, int level)
{
    if(A==NULL)
    {
        return;
    }
    mp[level] += A->val;
    helper(A->left, mp, level+1);
    helper(A->right, mp, level+1);
}

int Solution::solve(TreeNode* A) {
    
    map<int, int> mp;
    helper(A, mp, 0);
    int ans = INT_MIN;
    for(auto i:mp)
    {
        ans = max(ans, i.second);
    }
    
    return ans;
    
}
