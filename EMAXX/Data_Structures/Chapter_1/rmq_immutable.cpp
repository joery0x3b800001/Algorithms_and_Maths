#include <iostream>
#include<vector>
using namespace std;
// https://leetcode.com/problems/range-sum-query-immutable/description/

class NumArray {
public:
	vector<int> &preSum;

	NumArray(vector<int>& nums) :preSum(nums) {
		for (int i = 1; i < preSum.size(); i++)
			preSum[i] += preSum[i-1];
	}

	int sumRange(int left, int right) {
		if (left == 0) return preSum[right];
		return preSum[right] - preSum[left-1];
	}
};

int main() {
	vector<int> nums {-2, 0, 3, -5, 2, -1};
	NumArray *obj = new NumArray(nums);
	cout << obj->sumRange(0, 2) << endl;
	cout << obj->sumRange(2, 5) << endl;
	cout << obj->sumRange(0, 5) << endl;
}

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */