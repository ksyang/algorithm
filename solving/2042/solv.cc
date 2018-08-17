#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void init_vector(vector<long long> &L1, vector<long long> &tree, int node, int start, int end){
	if(start == end){
		return tree[node] = L1[start];
	} else {
		return tree[node] = init(L1, tree, node*2, start, (start+end)/2)  + init(L1, tree, node*2+1, (start+end)/2+1, end);
	}
}

void changeTree(x, y){
	
}

int getSum(x, y){

}

int main(void){
	int N, M, K;
	vector<long long> L1;

	cin >> N;
	L1.resize(N);

	int h = (int)ceil(log2(n));
	int tree_size = (1 << (h+1));

	vector<long long> tree(tree_size);

	for(int i=0; i<N; i++){
		cin >> L1[i];
	}
	
	init_tree(L1, tree, 1, 0, n-1);

	for(int i=0; i<M+K; i++){
		int type, x, y;
		cin >> type >> x >> y;
		if(type == 1) {		//case change
			changeTree(x, y);
		}
		else {
			cout << getSum(x, y);
		}	
	}
	return 0;
}
