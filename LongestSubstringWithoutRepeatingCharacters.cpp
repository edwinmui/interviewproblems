class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Linear solution
        int n = s.size();
        int result = 0;
        int NUM_CHARS = 256;
        int i = 0;
        vector<int> lastIndex(NUM_CHARS, -1);
        for (int j = 0; j < n; ++j) {
            i = max(i, lastIndex[s[j]] + 1);
            result = max(result, j - i + 1);
            lastIndex[s[j]] = j;
        }
        return result;
        
        /*
        // edge cases
        if (s.length() == 0) return 0;
        if (s.length() == 1) return 1;
        string solution;
        // try every letter as starting point
        for (int i = 0; i < s.size(); ++i){
            unordered_map<char, int> frequencies;
            string curr_solution;
            for (int j = i; j < s.size(); ++j){
                // non-repeating sequence
                if (frequencies.find(s[j]) == frequencies.end()) {
                    frequencies[s[j]] = 1;
                    curr_solution += s[j];
                } else {
                    break;
                }
            }
            if (curr_solution.length() > solution.length()){
                        solution = curr_solution;
                }
        }
        return solution.length();
        */
    }
};
