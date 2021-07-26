/*
Problem Description

Consider lines of slope -1 passing between nodes.

Given a Binary Tree A containing N nodes, return all diagonal elements in a binary tree belonging to same line.

NOTE:

See Sample Explanation for better understanding.
Order does matter in the output.
To get the same order as in the output traverse the tree same as we do in pre-order traversal.


Problem Constraints
 0 <= N <= 105 



Input Format
First and only Argument represents the root of binary tree A.



Output Format
Return a 1D array denoting the diagonal traversal of the tree.



Example Input
Input 1:

            1
          /   \
         4      2
        / \      \
       8   5      3
          / \    /
         9   7  6
Input 2:

             11
          /     \
         20      12
        / \       \
       1   15      13
          /  \     /
         2    17  16
          \   /
          22 34


Example Output
Output 1:

 [1, 2, 3, 4, 5, 7, 6, 8, 9]
Output 2:

 [11, 12, 13, 20, 15, 17, 16, 1, 2, 22, 34]
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

void helper(TreeNode* node, int idx, int &cnt, unordered_map<int, vector<int>> &mp)
{
    if(node==NULL)
    {
        return;
    }
    cnt=max(cnt, idx);
    mp[idx].push_back(node->val);
    helper(node->left, idx+1, cnt, mp);
    helper(node->right, idx, cnt, mp);
}

vector<int> Solution::solve(TreeNode* A) {

    unordered_map<int, vector<int>> mp;
    int cnt=0;
    helper(A, 1, cnt, mp);

    vector<int> ans;

    for(int i=1; i<=cnt; i++)
    {
        auto tmp = mp[i];
        for(auto x: tmp)
        {
            ans.push_back(x);
        }
    }

    return ans;

}
