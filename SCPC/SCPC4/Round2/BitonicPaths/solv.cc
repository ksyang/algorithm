#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
long long int N, M, u, v, d, S;
vector<pair<long long int, long long int> > edge[200002];
vector<long long int> Dijkstra(long long int start) {
	vector<long long int> dist(N + 1, -1);
	vector<long long int> privEdge(N + 1, -1);
	priority_queue<pair<long long int, long long int> > pq; // first : dist , second : vertex_pos
	dist[start] = 0;
	privEdge[start] = -1;
	pq.push(make_pair(-dist[start], start)); // Min-Heap처럼 사용하기 위해 앞의 거리 인자에 -값을 곱해줌.
	while (!pq.empty()) {
		long long int here = pq.top().second;
		long long int heredist = -pq.top().first;
		pq.pop();
		if (heredist > dist[here]) continue;
		for (long long int i = 0; i < edge[here].size(); i++) {  //노드에 연결된 엣지들 탐색
			long long int there = edge[here][i].first;
			long long int nextdist = heredist + edge[here][i].second;
			if(edge[here][i].second >= privEdge[here]){
				if (dist[there] == -1 || dist[there] > nextdist) { //최단 거리 갱신
					privEdge[there] = edge[here][i].second;
					dist[there] = nextdist;
					pq.push(make_pair(-nextdist, there));
				}
			}
		}
	}
	return dist;
}

int main() {
	int T, caseCnt = 0;
	cin >> T;

	while(T--){
		caseCnt++;
		cin >> N >> M;
		for (int i = 0; i < M; i++) {
			cin >> u >> v >> d;
			edge[u].push_back(make_pair(v, d));
			edge[v].push_back(make_pair(u, d));
		}
		vector<long long int> dist = Dijkstra(1);
		vector<long long int> dist2 = Dijkstra(N);
		
		long long int minPath = -1;

		for(int i=1; i<=N; i++){
			if(dist[i] != -1 && dist2[i] != -1){
				if(minPath == -1){
					minPath = dist[i] + dist2[i];
				}
				else minPath = min(dist[i] + dist2[i], minPath);
			}
		}
		
		for(int i=0; i<200002; i++){
			vector<pair<long long int, long long int> >().swap(edge[i]);
		}

		cout << "Case #" << caseCnt <<"\n";
		cout << minPath << "\n";
	}
	return 0;
}
