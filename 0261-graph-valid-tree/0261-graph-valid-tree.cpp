class Solution {
public:
    bool validTree(int n, std::vector<std::vector<int>>& edges) {
    if (edges.size() != static_cast<size_t>(n - 1)) return false;

    // Make the adjacency list
    std::vector<std::vector<int>> adjacencyList(n);
    for (const auto& edge : edges) {
        adjacencyList[edge[0]].push_back(edge[1]);
        adjacencyList[edge[1]].push_back(edge[0]);
    }

    std::queue<int> queue;
    std::unordered_set<int> seen;
    queue.push(0);
    seen.insert(0);

    while (!queue.empty()) {
        int node = queue.front();
        queue.pop();
        for (int neighbour : adjacencyList[node]) {
            if (seen.find(neighbour) != seen.end()) continue;
            seen.insert(neighbour);
            queue.push(neighbour);
        }
    }

    return seen.size() == static_cast<size_t>(n);
}
};