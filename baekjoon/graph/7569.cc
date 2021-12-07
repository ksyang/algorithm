#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <tuple>

using namespace std;

int pan[101][101][101];
int days = 0;
queue<tuple<int, int, int>> q;
int M, N, H;

void bfs(){
  while(!q.empty()){
    int h = get<0>(q.front());
    int m = get<1>(q.front());
    int n = get<2>(q.front());
    q.pop();
    if(h+1<H && pan[h+1][m][n] == 0){
      pan[h+1][m][n]=pan[h][m][n]+1;
      q.push(make_tuple(h+1, m, n));
    }
    if(h-1>=0 && pan[h-1][m][n] == 0){
      pan[h-1][m][n]=pan[h][m][n]+1;
      q.push(make_tuple(h-1, m, n));
    }
    if(m+1<M && pan[h][m+1][n] == 0){
      pan[h][m+1][n]=pan[h][m][n]+1;
      q.push(make_tuple(h, m+1, n));
    }
    if(m-1>=0 && pan[h][m-1][n] == 0){
      pan[h][m-1][n]=pan[h][m][n]+1;
      q.push(make_tuple(h, m-1, n));
    }
    if(n+1<N && pan[h][m][n+1] == 0){
      pan[h][m][n+1]=pan[h][m][n]+1;
      q.push(make_tuple(h, m, n+1));
    }
    if(n-1>=0 && pan[h][m][n-1] == 0){
      pan[h][m][n-1]=pan[h][m][n]+1;
      q.push(make_tuple(h, m, n-1));
    }
  }
}

int main(void){
  cin >> N >> M >> H;
  for(int k=0; k<H; k++){
    for(int i=0; i<M; i++){
      for(int j=0; j<N; j++){
        cin >> pan[k][i][j];
        if(pan[k][i][j] == 1) q.push(make_tuple(k, i, j));
      }
    }
  }
  bfs();
  int max=0;
  bool flag = 0;
  for(int k=0; k<H; k++){
    for(int i=0; i<M; i++){
      for(int j=0; j<N; j++){
        if(pan[k][i][j]==0) flag = 1;
        if(pan[k][i][j]>0){
          if(pan[k][i][j]>max) max = pan[k][i][j];
        }
      }
    }
  }
  if(flag) printf("-1");
  else printf("%d", max-1);
  return 0;
}
