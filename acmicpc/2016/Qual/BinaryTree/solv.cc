#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int main(void){
	int H;
	vector<int> node;
	vector<int> leaf;
	int numNode, numLeaf;

	scanf("%d", &H);
	
	numNode = pow(2, H+1) - 1;
	node.resize(numNode + 1);
	node[1] = 0;

	numLeaf = pow(2, H);
	leaf.resize(numLeaf);
	
	int sumNode = 0;
	for(int i=2; i<=numNode; i++){
		scanf("%d", &node[i]);
		sumNode += node[i];
	}

	for(int i=numNode - numLeaf + 1; i<=numNode; i++){
		int sumTmp = 0;
		int itor = i;
		while(node[itor] != 0){
			sumTmp += node[itor];
			itor = itor/2;
		}
		leaf[i - numNode + numLeaf - 1] = sumTmp;
	}

	vector<int>::iterator pivot = max_element(leaf.begin(), leaf.end());

	
	return 0;
}
