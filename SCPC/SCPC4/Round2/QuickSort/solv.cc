#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class MinTree {
public:
	typedef int dtype;

	vector <dtype> tree;

	int s;

	void insert(vector <dtype> &d) {
		for (int i = s; i < s + d.size(); i++)
			tree[i] = d[i - s];
		for (int i = s - 1; i >= 1; i--)
			tree[i] = min(tree[i * 2], tree[i * 2 + 1]);
	}

	MinTree(int n) {
		for (s = 1; s < n; s *= 2) {}
		tree.resize(s * 2);
		for (int i = 1; i < s * 2; i++) tree[i] = numeric_limits<dtype>::max();
	}

	dtype getMin(int Left, int Right) {
		int l = Left + s, r = Right + s;
		dtype rval = numeric_limits<dtype>::max();
		while (l <= r) {
			if (l % 2 == 0) l /= 2;
			else {
				rval = min(rval, tree[l]);
				l = (l / 2) + 1;
			}
			if (r % 2 == 1) r /= 2;
			else {
				rval = min(rval, tree[r]);
				r = (r / 2) - 1;
			}
		}
		return rval;
	}
};

class MaxTree {
public:
	typedef int dtype;

	vector <dtype> tree;

	int s;

	void insert(vector <dtype> &d) {
		for (int i = s; i < s + d.size(); i++)
			tree[i] = d[i - s];
		for (int i = s - 1; i >= 1; i--)
			tree[i] = max(tree[i * 2], tree[i * 2 + 1]);
	}

	MaxTree(int n) {
		for (s = 1; s < n; s *= 2) {}
		tree.resize(s * 2);
		for (int i = 1; i < s * 2; i++) tree[i] = numeric_limits<dtype>::min();
	}

	dtype getMax(int Left, int Right) {
		int l = Left + s, r = Right + s;
		dtype rval = numeric_limits<dtype>::min();
		while (l <= r) {
			if (l % 2 == 0) l /= 2;
			else {
				rval = max(rval, tree[l]);
				l = (l / 2) + 1;
			}
			if (r % 2 == 1) r /= 2;
			else {
				rval = max(rval, tree[r]);
				r = (r / 2) - 1;
			}
		}
		return rval;
	}
};

int main(void) {
	int T, caseCnt = 0;

	cin >> T;
	while (T--) {
		caseCnt++;

		int N;

		cin >> N;

		MinTree minT(N);
		MaxTree maxT(N);
		vector <int> v(N);

		for (int i = 0; i<N; i++) {
			cin >> v[i];
		}

		minT.insert(v);
		maxT.insert(v);

		int numPivot = 0;

		for (int i = 0; i<N; i++) {
			if (i == 0 && v[i] < minT.getMin(i + 1, N - 1)) {
				numPivot++;
			}
			else if (i == (N - 1) && v[i] > maxT.getMax(0, i - 1)) {
				numPivot++;
			}
			else if (v[i] < minT.getMin(i + 1, N - 1) && v[i] > maxT.getMax(0, i - 1)) {
				numPivot++;
			}
		}

		cout << "Case #" << caseCnt << "\n";
		cout << numPivot << "\n";
	}
	return 0;
}



