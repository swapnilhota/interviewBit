/*
Given a binary tree and a sum, find all root-to-leaf paths where each path’s sum equals the given sum.

For example:

Given the below binary tree and sum = 22,

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return

[
   [5,4,11,2],
   [5,8,4,5]
]
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
void helper(TreeNode* node, int sum, int target, vector<int> path, vector<vector<int>> &ans)
{
    if(node==NULL)
    {
        return;
    }
    if(node->left==NULL && node->right==NULL)
    {
        sum += node->val;
        if(sum==target)
        {
            path.push_back(node->val);
            ans.push_back(path);
        }
        return;
    }

    sum += node->val;
    path.push_back(node->val);

    helper(node->left, sum, target, path, ans);
    helper(node->right, sum, target, path, ans);
}

vector<vector<int> > Solution::pathSum(TreeNode* A, int B) {

    vector<vector<int>> ans;
    vector<int> path;

    helper(A, 0, B, path, ans);

    return ans;

}
