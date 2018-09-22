#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

int main(void){
	int N, C;
	vector<string> pocN;
	map<string, int> pocS;
	scanf("%d %d", &N, &C);
	pocN.resize(N);

	for(int i=0; i<N; i++){
		char poc[21];
		scanf("%s", poc);
		pocN[i] = poc;
		pocS.insert(make_pair(pocN[i], i));
	}

	for(int i=0; i<C; i++){
		char poc[21];
		string tmp;
		scanf("%s", poc);
		if(poc[0] >= '0' && poc[0] <='9'){
			printf("%s\n", pocN[atoi(poc)-1].c_str());
		} else {
			tmp = poc;
			printf("%d\n", pocS[tmp] + 1);
		}
	}
	return 0;
}
