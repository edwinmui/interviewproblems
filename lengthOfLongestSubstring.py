from typing import List
from collections import Counter

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        left = right = 0
        longest = 0
        freqs = Counter()
        
        # If empty string, return 0
        if len(s) == 0: return longest

        while (right < len(s)):
            c = s[right]
            freqs[c] += 1

            # While duplicate exists on right pointer, remove characters using left pointer until no dupes remain
            while freqs[c] > 1:
                freqs[s[left]] -= 1
                left += 1
            
            longest = max(longest, right - left + 1)

            right += 1

        return longest
        
# T: O(2n)
# S: O(min(n, m)) where n = # of chars in string, and m = # letters in the charset/alphabet

    def optimizedLengthOfLongestSubstring(self, s: str) -> int:
        longest = 0
        indices = {}

        l = 0
        for r in range(0, len(s)):
            c = s[r]
            
            if c in indices:
                l = max(l, indices[c])
            
            longest = max(longest, r - l + 1)
            indices[c] = r + 1

        return longest


def main():
    test1 = "abbbcd"
    actual1 = "3"

    test2 = "bbb"
    actual2 = "1"

    test3 = "abcd"
    actual3 = 4

    test4 = "abbb"
    actual4 = "2"

    longestSub = Solution().optimizedLengthOfLongestSubstring
    print("Test:", actual1)
    print("Actual:", longestSub(test1))

    print("Test:", actual2)
    print("Actual:", longestSub(test2))

    print("Test:", actual3)
    print("Actual:", longestSub(test3))

    print("Test:", actual4)
    print("Actual:", longestSub(test4))

if __name__ == "__main__":
    main()