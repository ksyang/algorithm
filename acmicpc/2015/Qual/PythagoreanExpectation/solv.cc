#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>

using namespace std;

int main(void){
	int T;
	cin >> T;

	while(T--){
		int n, m;
		cin >> n >> m;
		vector<pair<int, int > > winRate;
		long long int PE[1001];
		winRate.resize(n);

		for(int i=0; i<n; i++){
			winRate[i].first = winRate[i].second = 0;
		}

		int a, b, p, q;
		for(int i=0; i<m; i++){
			scanf("%d%d%d%d", &a, &b, &p, &q);
			winRate[a-1].first += p;
			winRate[a-1].second += q;
			winRate[b-1].first += q;
			winRate[b-1].second += p;
		}

		for(int i=0; i<n; i++){
			if(!winRate[i].first && !winRate[i].second) PE[i] = 0;
			else 
				PE[i] = (pow(winRate[i].first, 2) * 1000) / (pow(winRate[i].first, 2) + pow(winRate[i].second, 2));
		}

		sort(PE, PE+n);
		printf("%lld\n%lld\n", PE[n-1], PE[0]);
	}
	return 0;
}
