#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <utility>

using namespace std;

/*
Questions:
1. Is parent always first index, child second index?
- Correct


Suppose we have some input data describing a graph of relationships between parents and children over multiple families and generations. The data is formatted as a list of (parent, child) pairs, where each individual is assigned a unique positive integer identifier.

For example, in this diagram, 3 is a child of 1 and 2, and 5 is a child of 4:

1   2    4           30
 \ /   /  \           \ 
  3   5    9  15      16
   \ / \    \ / 
    6   7   12  


Sample input/output (pseudodata):

parentChildPairs = [
    (5, 6), (1, 3), (2, 3), (3, 6), (15, 12),
    (5, 7), (4, 5), (4, 9), (9, 12), (30, 16)
]


Write a function that takes this data as input and returns two collections: one containing all individuals with zero known parents, and one containing all individuals with exactly one known parent.

Output may be in any order:

findNodesWithZeroAndOneParents(parentChildPairs) => [
  [1, 2, 4, 15, 30],   // Individuals with zero parents
  [5, 7, 9, 16]        // Individuals with exactly one parent
]

*/

vector<vector<int>> findNodesWithZeroAndOneParents(vector<pair<int, int>> parentChildPairs) {
  // hash map
  // key: child_int, value: vector<parents_ints>
  unordered_map<int, vector<int>> child_parent_pairs;
  set<int> individuals;
  vector<int> zero_parents;
  vector<int> one_parent;
  // build map by iterating through parentchildpairs
  // O(N) 
  // insert(log(N)) 2N = #individuals
  // Nlog(N)
  for (int i = 0; i < parentChildPairs.size(); ++i) {
    int parent = parentChildPairs[i].first;
    int child = parentChildPairs[i].second;
    // Insert individual into set
    individuals.insert(child);
    individuals.insert(parent);
    // give child a parent
    child_parent_pairs[child].push_back(parent);
  }
  
  // iterate through map and identify individuals with 0 and 1 parent(s)
  for (auto it = individuals.begin(); it != individuals.end(); ++it) {
    int individual = *it;
    // If child has no parents
    if (child_parent_pairs.find(individual) == child_parent_pairs.end()) {
      zero_parents.push_back(individual);
      continue;
    }
    // If child has one parent
    if (child_parent_pairs[individual].size() == 1) {
      one_parent.push_back(individual);
    }
  }
  
  vector<vector<int>> solution;
  solution.push_back(zero_parents);
  solution.push_back(one_parent);
  return solution;
}


int main() {
  
  vector<pair<int, int>> parent_child_pairs = {
    make_pair(5, 6),
    make_pair(1, 3),
    make_pair(2, 3),
    make_pair(3, 6),
    make_pair(15, 12),
    make_pair(5, 7),
    make_pair(4, 5),
    make_pair(4, 9),
    make_pair(9, 12),
    make_pair(30, 16)
  };

  vector<vector<int>> solution = findNodesWithZeroAndOneParents(parent_child_pairs);
  
  /*
    zero_parents = []
    one_parent []
  */
  vector<int> zero_parents = solution[0];
  vector<int> one_parent = solution[1];
  for (int i = 0; i < zero_parents.size(); ++i) {
    cout << zero_parents[i] << " ";
  }
  cout << "\n";
  for (int j = 0; j < one_parent.size(); ++j) {
    cout << one_parent[j] << " ";
  }


  return 0;
}


/*
  for (auto it = child_parent_pairs.cbegin(); it != child_parent_pairs.cend(); ++it) {
    cout << (*it).first << " ";
    for (int i = 0; i < ((*it).second).size(); ++i){
      cout << (*it).second[i] << " ";
    }

    cout << "\n";
  }
  */
  /*
  for (auto it = individuals.begin(); it != individuals.end(); ++it){
    cout << *it << " ";
  }
  */
  
  /*
  parentChildPairs = [
    (5, 6), (1, 3), (2, 3), (3, 6), (15, 12),
    (5, 7), (4, 5), (4, 9), (9, 12), (30, 16)
]
  child_parent_pairs -> {
    6: [5, 3]
    3: [1, 2]
    12: [15, 9]
    7: [5]
    9: [4]
    5: [4]
    16: [30]
  }
  }
  */
  // indiviudal = {1 2 3 4 5 6 7 9 12 15 16 30 }
  
  // Solution:
  /*
    [1, 2, 4, 15, 30],   // Individuals with zero parents
    [5, 7, 9, 16]        // Individuals with exactly one parent
  */
