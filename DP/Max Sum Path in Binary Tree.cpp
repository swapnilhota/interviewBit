/*
Given a binary tree T, find the maximum path sum.

The path may start and end at any node in the tree.

Input Format:

The first and the only argument contains a pointer to the root of T, A.
Output Format:

Return an integer representing the maximum sum path.
Constraints:

1 <= Number of Nodes <= 7e4
-1000 <= Value of Node in T <= 1000
*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int solve(TreeNode* root, int &res)
{
    if(root==NULL)
    {
        return 0;
    }

    int l = solve(root->left, res);
    int r = solve(root->right, res);

    int temp = root->val + max(l, r);
    temp = max(temp, root->val);
    int ans = max(temp, root->val + l + r);

    res=max(res, ans);

    return temp;
}

int Solution::maxPathSum(TreeNode* A) {
    int res = INT_MIN;
    solve(A, res);
    return res;
}
