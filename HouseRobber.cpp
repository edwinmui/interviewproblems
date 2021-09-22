class Solution {
public:
    int rob(vector<int>& nums) {
        int nums_size = nums.size();
        // base cases
        if (nums_size == 0) return 0;
        if (nums_size == 1) return nums[0];
        // setup bottom-up memoization
        int house_max_sums[nums_size];
        house_max_sums[0] = nums[0];
        house_max_sums[1] = max(nums[1], nums[0]);
        // calculates the max sums for each house and its previous houses 
        for (int i = 2; i < nums_size; ++i){
            house_max_sums[i] = max(house_max_sums[i-2] + nums[i], house_max_sums[i-1]);
        }
        // max sum of all houses is at the last index
        return house_max_sums[nums_size - 1];
    }
};
