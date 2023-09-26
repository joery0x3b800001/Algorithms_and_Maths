// Range sum Query - Mutable
// Range sum Query using Segment Tree.
// https://leetcode.com/problems/range-sum-query-immutable/description/

#include <iostream>
#include <vector>
using namespace std;

class NumArray {
public:
    NumArray(vector<int>& nums) {
        if (nums.size() > 0) {
            n = nums.size();
            tree = new int[n * 2];
            buildTree(nums);
        }
    }

    void buildTree(vector<int> &nums) {
        for (int i = n, j = 0; i < 2 * n; i++, j++)
            tree[i] = nums[j];
        for (int i = n - 1; i > 0; --i)
            tree[i] = tree[i * 2] + tree[i * 2 + 1];
    }
    
    void update(int index, int val) {
        index += n;
        tree[index] = val;
        while (index > 0) {
            int left = index;
            int right = index;
            if (index % 2 == 0) {
                right = index + 1;
            } else {
                left = index - 1;
            }

            tree[index / 2] = tree[left] + tree[right];
            index /= 2;
        }
    }
    
    int sumRange(int left, int right) {
        // get a leaf with value 'left'
        left += n;
        //  get a leaf with value 'right'
        right += n;
        int sum = 0;
        while (left <= right) {
            if ((left % 2) == 1) {
                sum += tree[left];
                left++;
            }

            if ((right % 2) == 0) {
                sum += tree[right];
                right--;
            }
            left /= 2;
            right /= 2;
        }
        return sum;
    }

private:
    int *tree;
    int n;
};

int main() {
    vector<int> nums {1, 3, 5};
    NumArray* obj = new NumArray(nums);
    cout << obj->sumRange(0, 2) << endl;
    obj->update(1, 2);
    cout << obj->sumRange(0, 2) << endl;
}

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */