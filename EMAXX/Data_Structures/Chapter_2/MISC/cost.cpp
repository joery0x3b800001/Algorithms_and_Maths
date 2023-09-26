// https://weoi.org/wp-content/uploads/2023/07/WEOI-2023-Problemset-Editorial.pdf
#include <algorithm>
#include <stack>
#include <vector>
#include <iostream>
using namespace std;
typedef long long int ll;

ll mod = 1000003;

struct road {
	int weight, index;
	road() {}
	road(int w, int i) {
		weight = w;
		index = i;
	}

	bool operator<(const road &other) const {
		if (weight != other.weight)
			return weight > other.weight;
		return index < other.index;
	}
};

vector<int> leftGeq(vector<int> &A) {
	vector<int> indices(A.size());
	indices[0] = -1;
	stack<int> S;
	S.push(0);

	for (int i = 1; i < (int)A.size(); i++) {
		while (S.size() && A[S.top()] < A[i]) {
			S.pop();
		}
		if (S.size())  {
			indices[i] = S.top();
		} else {
			indices[i] = -1;
		}
		S.push(i);
	}
	return indices;
}

vector<int> rightGeq(vector<int> &A) {
	vector<int> indices(A.size());
	int N = (int)A.size();
	indices[N - 1] = N;
	stack<int> S;
	S.push(N - 1);
	for (int i = N - 2; i >= 0; i--) {
		while (S.size() && A[S.top()] <= A[i]) {
			S.pop();
		}

		if (S.size()) {
			indices[i] = S.top();
		} else {
			indices[i] = N;
		}
		S.push(i);
	}
	return indices;
}

vector<road> createRoadsSet(vector<int> &C) {
	vector<road> roads(C.size());
	for (int i = 0; i < (int)C.size(); i++) {
		roads[i] = road(C[i], i);
	}
	sort(roads.begin(), roads.end());
	return roads;
}

void update(ll left, ll right, ll k, ll &result, ll &pairCurDir,
	ll pairOtherDir) {
	ll pairsToRemove = (((left * right * 2) % mod) + mod - 1) % mod;
	ll pairsInterRemove = (pairsToRemove * pairOtherDir) % mod;
	k %= mod;
	result += (pairsInterRemove * k) % mod;
	result %= mod;
	pairCurDir = (pairCurDir - pairsToRemove + mod) % mod;
}

int solve(int N, int M, int K, vector<int> A, vector<int> B) {
	vector<int> leftBoundsStreets = leftGeq(A);
	vector<int> leftBoundsAvenues = leftGeq(B);
	vector<int> rightBoundsStreets = rightGeq(A);
	vector<int> rightBoundsAvenues = rightGeq(B);
	
	vector<road> streets = createRoadsSet(A);
	vector<road> avenues = createRoadsSet(B);

	ll pairStreets = ((ll)N * (ll)N) % mod;
	ll pairAvenues = ((ll)M * (ll)M) % mod;
	ll result = 0;
	K = max(streets[0].weight, avenues[0].weight);

	int left, right, idx;
	int streetsIt = 0, avenuesIt = 0;
	for (int k = K; k > 0; k--) {
		while (streetsIt < N) {
			if (streets[streetsIt].weight != k)
				break;
			idx = streets[streetsIt].index;
			left = idx - leftBoundsStreets[idx];
			right = rightBoundsStreets[idx] - idx;
			update(left, right, k, result, pairStreets, pairAvenues);
			streetsIt++;
		}

		while (avenuesIt < M) {
			if (avenues[avenuesIt].weight != k)
				break;
			idx = avenues[avenuesIt].index;
			left = idx - leftBoundsAvenues[idx];
			right = rightBoundsAvenues[idx] - idx;
			update(left, right, k, result, pairAvenues, pairStreets);
			avenuesIt++;
		}
	}
	return result;
}

int main() {
	int N, M, K;
	cin >> N >> M >> K;

	vector<int> A(N), B(M);

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	for (int i = 0; i < M; i++) {
		cin >> B[i];
	}

	cout << solve(N, M, K, A, B) << endl;
}