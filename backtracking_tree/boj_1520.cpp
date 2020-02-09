#include <iostream>
#include <deque>

int M, N, res = 0;
int arr[500][500];
int visited[500][500];
int dir[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };

bool isRanged(int y, int x) {
	return ((y >= 0 && y < M) && (x >= 0 && x < N));
}

void printMap() {
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			std::cout << visited[i][j] << ' ';
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}


int dfs(int curY, int curX) {
	if (curY == M -1 && curX == N-1) {
		return 1;
	}
	//printMap();
	if (visited[curY][curX] == -1) {

		visited[curY][curX] = 0;
		for (int i = 0; i < 4; i++) {
			int nextY = curY + dir[i][0];
			int nextX = curX + dir[i][1];

			if (arr[nextY][nextX] >= arr[curY][curX]) continue;
			if (!isRanged(nextY, nextX)) continue;

			visited[curY][curX] += dfs(nextY, nextX);

		}
	}
	return visited[curY][curX];
}


int main() {
	std::cin >> M >> N;

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &arr[i][j]);
			visited[i][j] = -1;
		}
	}
        res = dfs(0,0);	
	std::cout << res;

	return 0;
}
