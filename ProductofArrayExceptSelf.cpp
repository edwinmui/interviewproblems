class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // creates two helpers arrays with left and right products of each index
        int left_products[nums.size()];
        int right_products[nums.size()];
        // initializes both ends with 1
        left_products[0] = 1;
        right_products[nums.size()-1] = 1;
        // calculates products arrays
        for (int i = 1; i < nums.size(); ++i){
            left_products[i] = left_products[i-1] * nums[i-1];
        }
        for (int j = nums.size() - 2; j >= 0; --j){
            right_products[j] = right_products[j+1] * nums[j+1];
        }
        vector<int> solution;
        // multiplies left products and right products of current index to get answer
        for (int k = 0; k < nums.size(); ++k){
            solution.push_back(left_products[k] * right_products[k]);
        }
        return solution;
    }
};
