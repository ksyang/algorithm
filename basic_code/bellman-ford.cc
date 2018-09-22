#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <climits>

using namespace std;

int main(void){
	int N, M;
	int dist[502];
	vector<pair<int, int> > v[502];
	bool cycle = false;

	cin >> N >> M;

	int A, B, C;
	for(int i=0; i<M; i++){
		scanf("%d%d%d", &A, &B, &C);
		v[A].push_back(make_pair(B, C));
	}

	for(int i=1; i<=N; i++)
		dist[i] = INT_MAX;
	
	dist[1] = 0;
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			for(auto &n : v[j]){
				if(dist[j] != INT_MAX && dist[n.first] > n.second + dist[j]){
					dist[n.first] = n.second + dist[j];
					if(i == N) cycle = 1;
				}
			}
		}
	}

	if(cycle) printf("-1\n");
	else {
		for(int i=2; i<=N; i++){
			if(dist[i] == INT_MAX)
				printf("-1\n");
			else
				printf("%d\n", dist[i]);
		}
	}
	return 0;
}
