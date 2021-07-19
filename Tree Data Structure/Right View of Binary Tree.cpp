/*
Problem Description

Given a binary tree A of integers. Return an array of integers representing the right view of the Binary tree.

Right view of a Binary Tree: is a set of nodes visible when the tree is visited from Right side.



Problem Constraints
1 <= Number of nodes in binary tree <= 105

0 <= node values <= 109 



Input Format
First and only argument is an pointer to the root of binary tree A.



Output Format
Return an integer array denoting the right view of the binary tree A.



Example Input
Input 1:

        1
      /   \
     2    3
    / \  / \
   4   5 6  7
  /
 8 
Input 2:

    1
   /  \
  2    3
   \
    4
     \
      5


Example Output
Output 1:

 [1, 3, 7, 8]
Output 2:

 [1, 3, 4, 5]
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

void helper(TreeNode* node, map<int, vector<int>> &mp, int &h, int level)
{
    if(node==NULL)
    {
        return;
    }
    h = max(h, level);
    mp[level].push_back(node->val);
    helper(node->left, mp, h, level+1);
    helper(node->right, mp, h, level+1);
}

vector<int> Solution::solve(TreeNode* A) {

    int h=0;
    map<int, vector<int>> mp;

    helper(A, mp, h, 0);

    vector<int> ans;
    for(int i=0; i<=h; i++)
    {
        int len = mp[i].size();
        ans.push_back(mp[i][len-1]);
    }

    return ans;
}
