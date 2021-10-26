#include <iostream>
#include <vector>

using namespace std;

/*
  Solution:
    1. Find shift index
    2. Perform binary search on shiftArr[0] - shiftArr[index-1]
    3. Perform binary search on shiftArr[index] - shiftArr[N - 1]
*/

/*
  Testcases:
  [2, 1]
  l = 0
  r = 1
  
  [9, 12, 17, 2, 4, 5]
  N = 6
  l = 0
  r = 5
  mid = 
*/
int find_shift(const vector<int>& shiftArr) {
  int N = shiftArr.size();
  int anchor = shiftArr[0];
  int l = 0;
  int r = N - 1;
  while (l <= r) {
    int mid = l + (r-l)/2;
    // If mid is right before shift index, returns
    if (mid == 0 || shiftArr[mid] < shiftArr[mid-1]) {
      return mid;
    }
    // If mid is before shift, adjust left pointer
    if (shiftArr[mid] > anchor) {
      l = mid + 1;
    }
    // If mid is after shift, adjust right pointer
    else {
      r = mid - 1;
    }
  }
  // Here, the shift point is the beginning
  return 0;
}

int binary_search(int start, int end, const vector<int>& shiftArr, int val) {
  int l = start;
  int r = end;
  while (l <= r) {
    int mid = l + (r-l)/2;
    if (shiftArr[mid] == val) return mid;
    // If mid is less than val, move left pointer
    if (shiftArr[mid] < val) {
      l = mid + 1;
    }
    // If mis is greater than val, move rigth pointer
    else {
      r = mid - 1;
    }
  }
  // Not found
  return -1;
}


int shiftedArrSearch( const vector<int>& shiftArr, int num ) 
{
  int N = shiftArr.size();
  int pivot = find_shift(shiftArr);
  if (pivot == 0) {
    return binary_search(0, N-1, shiftArr, num);
  } else {
    int left_search = binary_search(0, pivot-1, shiftArr, num);
    int right_search = binary_search(pivot, N-1, shiftArr, num);
    if (left_search != -1) return left_search;
    if (right_search != -1) return right_search;
  }
  return -1;
}

int main() {
  return 0;
}
