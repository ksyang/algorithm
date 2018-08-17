#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

int set[1000001];
int height[1000001];

int getGroup(int u){
	if(set[u] == u) return u;
	set[u] = getGroup(set[u]);
	return set[u];
}

void mergeSet(int u, int v){
	u = getGroup(u);
	v = getGroup(v);
	if(u == v) return;
	if(height[u] < height[v]) swap(u, v);
	set[v] = u;
	if(height[u] == height[v]) height[u]++;
}

bool isSet(int u, int v){
	if(getGroup(u) == getGroup(v)) return 1;
	else return 0;
}

int main(void){
	int n, m;
	scanf("%d %d", &n, &m);

	for(int i=0; i<=n; i++){
		set[i] = i;
		height[i] = 1;
	}

	for(int i=0; i<m; i++){
		int type, src, dest;
		scanf("%d %d %d", &type, &src, &dest);

		if(type == 0){
			mergeSet(src, dest);
		} else {
			if(isSet(src, dest)) printf("YES\n");
			else printf("NO\n");
		}
	}
	return 0;
}

