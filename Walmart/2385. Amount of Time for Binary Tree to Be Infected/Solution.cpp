class Solution
{
public:
    void f(TreeNode *root, unordered_map<int, vector<int>> &adj, int parent)
    {
        if (!root)
        {
            return;
            // Aditya Seth.
        }
        int curr = root->val;
        if (!root->left)
            adj[curr].push_back(0);
        else
            adj[curr].push_back(root->left->val);
        if (!root->right)
            adj[curr].push_back(0);
        else
            adj[curr].push_back(root->right->val);
        adj[curr].push_back(parent);
        f(root->left, adj, curr);
        f(root->right, adj, curr);
    }
    int amountOfTime(TreeNode *root, int start)
    {
        if (!root)
            return 0;
        unordered_map<int, vector<int>> adj;
        f(root, adj, -1);
        int ans = 0;
        queue<pair<int, int>> q;
        q.push({start, 0});
        int maxi = 0;
        for (auto c : adj)
            maxi = max(maxi, c.first);
        vector<int> vis(maxi + 1, 0);
        vis[start] = 1;
        while (!q.empty())
        {
            auto top = q.front();
            q.pop();
            int currNode = top.first;
            vis[currNode] = 1;
            ans = max(ans, top.second);
            for (auto c : adj[currNode])
            {
                if (c != -1 && c != 0 && !vis[c])
                {
                    vis[c] = 1;
                    q.push({c, top.second + 1});
                }
            }
        }
        return ans;
    }
};