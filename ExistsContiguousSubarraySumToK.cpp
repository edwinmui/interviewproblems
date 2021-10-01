#include <iostream>
#include <vector>
#include <assert.h>

using namespace std;

  // return if there exists a contiguous subarray whose total sum equals to target
  /*
- e.g.
- Input: [1, 2, 3, 4, 9] sum = 8
- Output: true, because a contiguous subarray is [2, 3, 4]
- Input: [2, 1, 3, 4, 9] sum = 8
l         ^
r         ^
- Output: false, because there is no contiguous subarray that sums to 8
- Input: [5, 6, 7, 3, 2] sum = 1;
l                     ^
r                     ^
sum = 5 --> 0 --> 6 --> 0 --> 3 --> 4
*/
// Time complexity: O(N)
// Space complexity: O(1)
bool contiguous_subarray(vector<int> arr, int target) {
  int l = 0;
  int r = 0;
  int sum = arr[0];
  while (l <= arr.size() && r <= arr.size()) {
    if (sum == target) {
      return true;
    }
    else if (sum > target) {
      sum -= arr[l++];
    } else {
      if (r < arr.size() - 1) {
        sum += arr[++r];
      }
    }
  }
  return false;
}

int main() {
  std::cout << "Hello World!\n";
  vector<int> ex1 {1, 2, 3, 4, 9};
  int target1 = 9;
  assert(contiguous_subarray(ex1, target1) == true);
  vector<int> ex2 {2, 1, 3, 4, 9};
  int target2 = 8;
  assert(contiguous_subarray(ex2, target2) == true);
  vector<int> ex3 {10, 1};
  int target3 = 10;
  assert(contiguous_subarray(ex3, target3) == true);
}
