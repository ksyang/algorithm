#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

vector<int> v[101];

int cnt = 0;

int bfs(int start){
  bool visited[101];
  memset(visited, false, sizeof(visited));
  queue<int> q;
  q.push(start);
  visited[start] = true;

  while(!q.empty()){
    int cur = q.front();
    q.pop();
    for(int e: v[cur]){
      if(visited[e]) continue;
      q.push(e);
      visited[e] = true;
      cnt++;
    }
  }

  return 0;
}

int main(void){
  int N, S;
  cin >> N;
  cin >> S;
  for(int i=0; i<S; i++){
    int from, to;
    cin >> from >> to;
    v[from].push_back(to);
    v[to].push_back(from);
  }

  bfs(1);
  printf("%d", cnt);
  return 0;
}
