/*
Problem Description

Given a tree with N nodes labelled from 1 to N.

Each node is either good or bad denoted by binary array A of size N where if A[i] is 1 then ithnode is good else if A[i] is 
0 then ith node is bad.

Also the given tree is rooted at node 1 and you need to tell the number of root to leaf paths in the tree that contain not more than C good nodes.

NOTE:

Each edge in the tree is bi-directional.


Problem Constraints
2 <= N <= 105

A[i] = 0 or A[i] = 1

0 <= C <= N



Input Format
First argument is an binary integer array A of size N.

Second argument is a 2-D array B of size (N-1) x 2 denoting the edge of the tree.

Third argument is an integer C.



Output Format
Return an integer denoting the number of root to leaf paths in the tree that contain not more than C good nodes.
*/

void dfs(map<int, vector<int>> &adj, int curr, vector<int> &A, int C, vector<bool> visited, int &ans, int cnt)
{
    if(cnt>C)
    {
        return;
    }

    visited[curr] = true;
    
    int leaf = 0;
    if(A[curr-1]==1) cnt++;

    for(auto next: adj[curr])
    {
        if(!visited[next])
        {
            leaf++;
            dfs(adj, next, A, C, visited, ans, cnt);
        }
    }

    if(leaf==0 && cnt<=C)
    {
        ans++;
    }
}

int Solution::solve(vector<int> &A, vector<vector<int> > &B, int C) {
    map<int, vector<int>> adj;
    for(auto edge: B)
    {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }

    int ans = 0;
    vector<bool> visited(A.size()+1, false);
    visited[1] = true;
    dfs(adj, 1, A, C, visited, ans, 0);
    return ans;
}
