#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool a[2000][2000];             // 인접 행렬, 전체 정점 저장
vector<int> g[2000];            // 인접 리스트, 내 주위 정점 저장
vector<pair<int, int>> edges;   // 간선 리스트, 전체 간선 저장

// A->B, C->D 는 간선 리스트 (edges)
// B->C 는 인접 행렬 (a)
// D->E 는 인접 리스트 (g)

int main(void){
  int n, m;
  cin >> n >> m;
  for(int i=0; i<m; i++){
    int from, to;
    cin >> from >> to;
    a[from][to] = a[to][from] = true;
    g[from].push_back(to);
    g[to].push_back(from);
    edges.push_back({from, to});
    edges.push_back({to, from});
  }
  
  // 모든 간선과 정점에 대해
  for(int i=0; i<m*2; i++){
    for(int j=0; j<m*2; j++){
      int A = edges[i].first;
      int B = edges[i].second;
      int C = edges[j].first;
      int D = edges[j].second;
      if(A==B||A==C||A==D||B==C||B==D||C==D) continue;
      if(!a[B][C]) continue;
      for(int E: g[D]){
        if(E==A||E==B||E==C||E==D) continue;
        cout << 1 << endl;
        return 0;
      }
    }
  }
  cout << 0 << endl;
  return 0;
}
