#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
   int maximumGap(vector<int>& nums) {
      if (nums.size() < 2) return 0;
      if (nums.size() == 2) return abs(nums[0] - nums[1]);

      int minV = INT_MAX;
      int maxV = 0;
      for (auto i : nums) {
         minV = min(minV, i);
         maxV = max(maxV, i);
      }

      int bSize = ceil((double)(maxV - minV) / (nums.size() - 1));
      if (bSize == 0) return 0;

      vector<int> maxBucket(nums.size(), INT_MIN);
      vector<int> minBucket(nums.size(), INT_MAX);

      for (auto i : nums) {
         int bIndex = (i - minV) / bSize;
         if (i < minBucket[bIndex]) {
            minBucket[bIndex] = i;
         }

         if (i > maxBucket[bIndex]) {
            maxBucket[bIndex] = i;
         }
      }

      int res = 0;
      int i = 0;
      while (i < nums.size() - 2) {
         if (maxBucket[i] == INT_MIN) {
            i++;
            continue;
         }
         int st = i;
         while (i <= nums.size() - 2 && minBucket[i + 1] == INT_MAX) {
            i++;
         }
         if (i > nums.size() - 2) return res;
         res = max(minBucket[i + 1] - maxBucket[st], res);
         i++;
      }
      return res;
   }
};

int main() {
   vector<int> nums = {3,6,9,1};

   Solution* sol = new Solution();
   cout << sol->maximumGap(nums) << '\n';
}

// {
//    const int n = nums.size();
//    if (n <= 1) return 0;
//    int maxE = *max_element(nums.begin(), nums.end());
//    int minE = *min_element(nums.begin(), nums.end());
//    double len = double(maxE - minE) / double(n - 1);
//    vector<int> maxA(n, INT_MIN);
//    vector<int> minA(n, INT_MAX);
//    for (int i = 0; i < n; i++) {
//       int index = (nums[i] - minE) / len;
//       maxA[index] = max(maxA[index], nums[i]);
//       minA[index] = min(minA[index], nums[i]);
//    }

//    int gap = 0, prev = maxA[0];
//    for (int i = 1; i < n; i++) {
//       if (minA[i] == INT_MAX) continue;
//       gap = max(gap, minA[i] - prev);
//       prev = maxA[i];
//    }
//    return gap;
// }