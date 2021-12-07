#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> v[1001];

bool dfs_visited[1001];

void dfs(int s){
  dfs_visited[s] = true;
  printf("%d ", s);
  for(int e: v[s]){
    if(!dfs_visited[e]){
      dfs(e);
    }
  }
}

void bfs(int start){
  bool visited[1001];
  memset(visited, false, sizeof(visited));
  queue<int> q;
  q.push(start);
  visited[start] = true;
  while(!q.empty()){
    int cur = q.front();
    q.pop();
    printf("%d ", cur);
    for(int e: v[cur]){
      if(!visited[e]){
        q.push(e);
        visited[e] = true;
      }
    }
  }
}

int main(void){
  int N, M, V;
  cin >> N >> M >> V;
  for(int i=0; i<M; i++){
    int from, to;
    cin >> from >> to;
    v[from].push_back(to);
    v[to].push_back(from);
  }

  for(int i=1; i<=N; i++){
    sort(v[i].begin(), v[i].end());
  }

  dfs(V);
  printf("\n");
  bfs(V);
  return 0;
}
