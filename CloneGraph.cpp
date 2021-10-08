/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> =_neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
private:
    // Hashmap to save visited node as key to prevent cycles
    unordered_map<Node*, Node*> visited;
public:
    Node* cloneGraph(Node* node) {
        // base case
        if (!node) {
            return node;
        }
        // BFS
        deque<Node*> q;
        q.push_back(node);
        // Clones initial node and puts into visited hashmap
        Node* new_node = new Node(node->val, vector<Node*> {});
        visited[node] = new_node;
        // Starts actual BFS traversal
        while (!q.empty()) {
            Node *next_node = q.front();
            q.pop_front();
            // Iterate through neighbors of next node
            for (auto &neighbor : next_node->neighbors) {
                // If node hasn't been visited yet
                if (visited.find(neighbor) == visited.end()) {
                    // Clones neighbor and puts it into visited map with empty neighs list
                    visited[neighbor] = new Node(neighbor->val, vector<Node*> {});
                    q.push_back(neighbor);
                }
                // Adds clone of neighbor to neighbors of new_node's clone
                visited[next_node]->neighbors.push_back(visited[neighbor]);
            }
        }
        // Returns the clone of new_node
        return visited[node];
    }
};
