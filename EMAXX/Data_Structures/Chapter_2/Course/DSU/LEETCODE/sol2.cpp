#include <iostream>
#include <unordered_map>
using namespace std;


class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int,int> mp;

		int n = nums.size();

		vector<int> res;
		for (int i = 0; i < n; i++) {
			int curr = nums[i];
			int rem = target - curr;

			if (mp.find(rem) != mp.end()) {
				res.push_back(mp[rem]);
				res.push_back(i);
				return res;
			}
			mp[curr] = i;
		}
		return res;
	}
};

int main() {

}