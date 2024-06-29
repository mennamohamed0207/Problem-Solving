/*
You are given a positive integer n representing the number of nodes of a Directed Acyclic Graph (DAG). The nodes are numbered from 0 to n - 1 (inclusive).

You are also given a 2D integer array edges, where edges[i] = [fromi, toi] denotes that there is a unidirectional edge from fromi to toi in the graph.

Return a list answer, where answer[i] is the list of ancestors of the ith node, sorted in ascending order.

A node u is an ancestor of another node v if u can reach v via a set of edges.

 

Example 1:


Input: n = 8, edgeList = [[0,3],[0,4],[1,3],[2,4],[2,7],[3,5],[3,6],[3,7],[4,6]]
Output: [[],[],[],[0,1],[0,2],[0,1,3],[0,1,2,3,4],[0,1,2,3]]
Explanation:
The above diagram represents the input graph.
- Nodes 0, 1, and 2 do not have any ancestors.
- Node 3 has two ancestors 0 and 1.
- Node 4 has two ancestors 0 and 2.
- Node 5 has three ancestors 0, 1, and 3.
- Node 6 has five ancestors 0, 1, 2, 3, and 4.
- Node 7 has four ancestors 0, 1, 2, and 3.

*/
//First Solution but there is wrong answer 21/80
class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> result(n);
        for (int i = 0; i < edges.size(); i++) {
            for (int j = 0; j < n; j++) {
                if (edges[i][1] == j) {
                    result[j].push_back(edges[i][0]);
                    int k = 0;
                    cout << result[edges[i][0]].size() << " ";
                    while (k < result[edges[i][0]].size()) {
                        cout << "/////";
                        cout << result[edges[i][0]][k] << " ";
                        result[j].push_back(result[edges[i][0]][k]);
                        k++;
                    }
                }
            }
        }
        for (int i = 0; i < result.size(); i++) {
            sort(result[i].begin(), result[i].end());
            auto it = unique(result[i].begin(), result[i].end());
            // Use erase method  to remove all the duplicates
            // from the vector
            result[i].erase(it, result[i].end());
        }
        return result;
    }
};
//Accepted one with the help of chatgpt
class Solution {
public:
     vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> result(n);
        vector<vector<int>> graph(n);
        vector<int> inDegree(n, 0);

        // Build the graph and compute in-degrees
        for (const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            inDegree[edge[1]]++;
        }

        // Queue for nodes with zero in-degrees
        vector<int> zeroInDegree;
        for (int i = 0; i < n; ++i) {
            if (inDegree[i] == 0) {
                zeroInDegree.push_back(i);
            }
        }

        // Process nodes with zero in-degrees
        while (!zeroInDegree.empty()) {
            int node = zeroInDegree.back();
            zeroInDegree.pop_back();
            for (int neighbor : graph[node]) {
                // Add current node and its ancestors to the neighbor's ancestor list
                result[neighbor].push_back(node);
                result[neighbor].insert(result[neighbor].end(), result[node].begin(), result[node].end());
                // Remove duplicates and sort the ancestor list
                sort(result[neighbor].begin(), result[neighbor].end());
                auto it = unique(result[neighbor].begin(), result[neighbor].end());
                result[neighbor].erase(it, result[neighbor].end());
                // Decrease in-degree and add to queue if zero
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) {
                    zeroInDegree.push_back(neighbor);
                }
            }
        }

        return result;
    }
};