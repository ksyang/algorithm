#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;
int M, N;
int findArea(int m, int n, vector<vector<int > > &pictureA) {
	int cntArea = 1;
	int cur = pictureA[m][n];
	pictureA[m][n] = 0;
	if (m != 0 && cur == pictureA[m - 1][n]) {
		cntArea += findArea(m - 1, n, pictureA);
	}
	if (m != M-1 && cur == pictureA[m + 1][n]) {
		cntArea += findArea(m + 1, n, pictureA);
	}
	if (n != 0 && cur == pictureA[m][n - 1]) {
		cntArea += findArea(m, n - 1, pictureA);
	}
	if (n != N-1 && cur == pictureA[m][n + 1]) {
		cntArea += findArea(m, n + 1, pictureA);
	}

	return cntArea;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int > > picture) {
	M = m;
	N = n;
	int number_of_area = 0;
	int max_size_of_one_area = 0;

	for (int i = 0; i<m; i++) {
		for (int j = 0; j<n; j++) {
			if (picture[i][j] != 0) {
				number_of_area++;
				max_size_of_one_area = max(findArea(i, j, picture), max_size_of_one_area);
			}
		}
	}

	vector<int> answer(2);
	answer[0] = number_of_area;
	answer[1] = max_size_of_one_area;
	return answer;
}

int main()
{
	int m, n;

	cin >> m >> n;

	vector<vector<int > > picture;
	picture.resize(m);
	for (int i = 0; i<m; i++)
		picture[i].resize(n);

	for (int i = 0; i<m; i++) {
		for (int j = 0; j<n; j++)
			scanf("%d", &picture[i][j]);
	}

	vector<int> ans = solution(m, n, picture);

	printf("%d %d", ans[0], ans[1]);

	return 0;
}
