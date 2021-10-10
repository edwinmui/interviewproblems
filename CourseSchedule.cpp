class Solution {
public:
    /*
    Topological sort solution
    */
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // Tracks dependencies of courses on other courses
        unordered_map<int, vector<int>> dependencies;
        // Keeps track of indegrees of each course
        vector<int> indegrees(numCourses, 0);
        for (auto &p : prerequisites) {
            dependencies[p[0]].push_back(p[1]);
            ++indegrees[p[1]];
        }
        deque<int> q;
        // Adds all nodes with indegrees 0 to queue
        for (int i = 0; i < numCourses; ++i) {
            if (indegrees[i] == 0) q.push_back(i);
        }
        // Removes edges of nodes connected to queue; if edge deletion creates another node
        // with indegrees 0, adds new node into queue
        while (!q.empty()) {
            for (auto & next_node : dependencies[q.front()]) {
                --indegrees[next_node];
                if (indegrees[next_node] == 0) q.push_back(next_node);
            }
            q.pop_front();
        }
        // If there exists a node with indegrees > 0 still, topological sort fails
        // a.k.a. there exists a cycle in the graph
        for (auto &i : indegrees) {
            if (i > 0) return false;
        }
        return true;
    }
};
