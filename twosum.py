from typing import List

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        n = len(nums)
        twoSum = []
        pairs = {}
        # Build dictionary of key: element, val: index
        for i in range(0, n):
            pairs[nums[i]] = i
        # Iterate through list and search for complement number that adds to target
        for j in range(0, n):
            difference = target - nums[j]
            # If complement found, return solution
            if difference in pairs:
                if j == pairs[difference]: continue
                twoSum.append(j)
                twoSum.append(pairs[difference])
                return twoSum
        return twoSum





def main():
    twoSum = Solution().twoSum
    print(twoSum([1, 3, 5, 7], 6))
    print(twoSum([1, 3, 5, 5, 7], 10))

if __name__ == "__main__":
    main()