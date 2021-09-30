class Solution {
public:
    string minRemoveToMakeValid(string s) {
        deque<int> parenth;
        set<int> ignore_index;
        // add all incorrect '(' parenthesis to stack and ')' to ignore_index
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                parenth.push_back(i);
            } else if (s[i] == ')' && !parenth.empty() && s[parenth.back()] == '(') {
                parenth.pop_back();
            } else if (s[i] == ')') {
                ignore_index.insert(i);
            } else{
                continue;
            }
        }
        // add rest of wrong indices in stack to ignore index
        while (!parenth.empty()) {
            ignore_index.insert(parenth.back());
            parenth.pop_back();
        }
        // builds string with removed invalid parenthesis
        string solution = "";
        for (int i = 0; i < s.length(); ++i) {
            if (ignore_index.find(i) == ignore_index.end()) solution += s[i];
        }
        return solution;
    }
};
