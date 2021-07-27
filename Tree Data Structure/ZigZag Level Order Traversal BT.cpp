/*
Given a binary tree, return the zigzag level order traversal of its nodes’ values. (ie, from left to right, then right to left for the next level and alternate between).

Example : 

Given binary tree

    3
   / \
  9  20
    /  \
   15   7
return

[
         [3],
         [20, 9],
         [15, 7]
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
void helper(TreeNode* node, unordered_map<int, vector<int>> &mp, int lvl, int &level)
{
    if(node==NULL)
    {
        return;
    }
    level = max(level, lvl);
    mp[lvl].push_back(node->val);
    helper(node->left, mp, lvl+1, level);
    helper(node->right, mp, lvl+1, level);
}

vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A) {

    vector<vector<int>> ans;
    if(A==NULL)
    {
        return ans;
    }

    unordered_map<int, vector<int>> mp;
    int level=0;

    helper(A, mp, 0, level);

    for(int i=0; i<=level; i++)
    {
        if(i%2==0)
        {
            //left to right
            vector<int> tmp = mp[i];
            ans.push_back(tmp);
        }
        else
        {
            //right to left
            vector<int> tmp = mp[i];
            reverse(tmp.begin(), tmp.end());
            ans.push_back(tmp);
        }
    }

    return ans;

}
