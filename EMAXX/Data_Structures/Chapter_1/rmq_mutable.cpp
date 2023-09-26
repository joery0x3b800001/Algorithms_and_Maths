// Range sum Query - Mutable
// Range sum Query using Sqrt Decomposition
// https://leetcode.com/problems/range-sum-query-mutable/editorial/
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class NumArray {
public:
    NumArray(vector<int>& nums) {
        this->nums = nums;
        double l = sqrt(nums.size());
        len = (int) ceil(nums.size() / l);
        b = new int[len];
        for (int i = 0; i < nums.size(); i++)
            b[i / len] += nums[i];
    }
    
    void update(int index, int val) {
        int b_l = index / len;
        b[b_l] = b[b_l] - nums[index] + val;
        nums[index] = val;
    }
    
    int sumRange(int left, int right) {
        int sum = 0;
        int startBlock = left / len;
        int endBlock = right / len;
        if (startBlock == endBlock) {
            for (int k = left; k <= right; k++)
                sum += nums[k];
        } else {
            for (int k = left; k <= (startBlock + 1) * len - 1; k++)
                sum += nums[k];
            for (int k = startBlock + 1; k <= endBlock - 1; k++)
                sum += b[k];
            for (int k = endBlock * len; k <= right; k++)
                sum += nums[k];
        }
        return sum;
    }

private:
    vector<int> nums;
    int len;
    int *b;
};

int main() {
    vector<int> nums {1, 3, 5};
    NumArray* obj = new NumArray(nums);
    cout << obj->sumRange(0, 2) << endl;
    obj->update(1, 2);
    cout << obj->sumRange(0, 2) << endl;;
}
/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */