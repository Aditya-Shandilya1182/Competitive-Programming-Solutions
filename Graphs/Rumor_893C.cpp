#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <climits>

void dfs(int node, std::vector<std::vector<int>>& adj, std::vector<bool>& visited, std::vector<int>& component, std::vector<int>& costs){
    visited[node] = true;
    component.push_back(node);
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited, component, costs);
        }
    }
}

int main(){
    int n, m;
    std::cin >> n >> m;

    std::vector<int> cost(n + 1);
    for(int i = 1; i <= n; i++){
        std::cin >> cost[i];
    }

    std::vector<std::vector<int>> adj(n + 1);
    for(int i = 0; i < m; i++){
        int x, y;
        std::cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    std::vector<bool> vis(n + 1, false);
    long long total_min_cost = 0;

    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            std::vector<int> nodes;
            dfs(i, adj, vis, nodes, cost);
            int min_cost = INT_MAX;
            for(int node : nodes){
                min_cost = std::min(min_cost, cost[node]);
            }
            total_min_cost += min_cost;
        }
    }

    std::cout << total_min_cost << std::endl;

    return 0;
}
