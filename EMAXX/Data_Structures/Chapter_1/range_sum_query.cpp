// Range query using bruteforce
// https://leetcode.com/problems/range-sum-query-immutable/description/
class NumArray {
public:
	NumArray(vector<int> &nums) {
		int len = nums.size();
		sum = new int*[len];
		for (int i = 0; i < len; i++) {
			sum[i] = new int[len];
		}

		for (int i = 0; i < len; i++) {
			int k = 0;
			for (int j = i; j < len; j++) {
				k += nums[j];
				sum[i][j] = k;
			}
		}
	}

	int sumRange(int i, int j) {
		return sum[i][j];
	}
private:
	int **sum;
};


// Range Query using Prefix sum
typedef unsigned long long int64;
 
class NumArray {
public:
    NumArray(vector<int> &nums) {
        int len = nums.size();
        sum = new int64[len];
        int k = 0;
        for (int i = 0; i < len; i ++) {
            k += nums[i];
            sum[i] = k;
        }
    }
 
    int sumRange(int i, int j) {
        if (i == 0) {
            return sum[j];
        }
        if (j == 0) {
            return sum[0];
        }
        return sum[j] - sum[i - 1];
    }
    
    ~NumArray() {
        delete [] sum;
    }
private:
    int64 *sum;
};