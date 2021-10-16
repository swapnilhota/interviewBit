/*
Problem Description

Given an directed graph having A nodes labelled from 1 to A containing M edges given by matrix B of size M x 2such that there is a edge directed from node

B[i][0] to node B[i][1].

Find whether a path exists from node 1 to node A.

Return 1 if path exists else return 0.

NOTE:

There are no self-loops in the graph.
There are no multiple edges between two nodes.
The graph may or may not be connected.
Nodes are numbered from 1 to A.
Your solution will run on multiple test cases. If you are using global variables make sure to clear them.


Problem Constraints
2 <= A <= 105

1 <= M <= min(200000,A(A-1))

1 <= B[i][0], B[i][1] <= A



Input Format
The first argument given is an integer A representing the number of nodes in the graph.

The second argument given a matrix B of size M x 2 which represents the M edges such that there is a edge directed from node B[i][0] to node B[i][1].



Output Format
Return 1 if path exists between node 1 to node A else return 0.
*/

int helper(vector<vector<int>> &adj, int curr, int dest, vector<bool> &visited)
{
    if(curr==dest)
    {
        return 1;
    }

    visited[curr] = true;

    for(auto next: adj[curr])
    {
        if(!visited[next])
        {
            if(helper(adj, next, dest, visited))
            {
                return 1;
            }
        }
    }

    return 0;
}

int Solution::solve(int A, vector<vector<int> > &B) {
    vector<vector<int>> adj(A+1);
    for(auto edge: B)
    {
        adj[edge[0]].push_back(edge[1]);
    }

    vector<bool> visited(A+1, false);

    return helper(adj, 1, A, visited);
}
