#include <iostream>
#include <deque>
#include <algorithm>
#include <cstring>

int map[100][100] = { 0, };
int visited[100][100] = { 0, };
int n;
int dir[4][2] = { { 1,0 },{ -1,0 },{ 0,-1 },{ 0,1 } };
std::deque<std::pair<int, int> > que;


bool isRanged(int y, int x) {
	return ((y >= 0 && y < n) && (x >= 0 && x < n));
}

void bfs(int startY, int startX, int cnt) {
	visited[startY][startX] = 1;
	map[startY][startX] = cnt;
	que.push_back(std::make_pair(startY, startX));

	while (!que.empty()) {

		int curX = que.front().second;
		int curY = que.front().first;

		que.pop_front();

		for (int i = 0; i < 4; i++) {
			int nextY = curY + dir[i][0];
			int nextX = curX + dir[i][1];

			if (isRanged(nextY, nextX) && visited[nextY][nextX] == 0) {

				if (map[nextY][nextX] == 1) {
					map[nextY][nextX] = cnt;
					visited[nextY][nextX] = 1;
					que.push_back(std::make_pair(nextY, nextX));
				}
			}
		}
	}
}

int bfs2(int cnt) {
	std::deque<std::pair<int, int> > q;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == cnt) {
				visited[i][j] = 1;
				q.push_back(std::make_pair(i, j));
			}
		}
	}

	int min = 0;
	while (!q.empty()) {
		int size = q.size();
		for (int j = 0; j < size; j++) {
			int curX = q.front().second;
			int curY = q.front().first;
			q.pop_front();

			for (int i = 0; i < 4; i++) {
				int nextY = curY + dir[i][0];
				int nextX = curX + dir[i][1];

				if (isRanged(nextY, nextX)) {
					if (map[nextY][nextX] && map[nextY][nextX] != cnt) {
						return min;
					}
					else if (!map[nextY][nextX] && !visited[nextY][nextX]) {
						visited[nextY][nextX] = 1;
						q.push_back(std::make_pair(nextY, nextX));
					}
				}

			}
		}
		min++;
	}
}


int main() {

	std::cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			std::cin >> map[i][j];
		}
	}

	int cnt = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 0 || visited[i][j]) continue;
			else {
				bfs(i, j, cnt);
				cnt++;
			}
		}
	}

	int result = 10000;
	for (int i = 1; i < cnt; i++) {
		memset(visited, 0, sizeof(visited));
		result = std::min(result, bfs2(i));
	}

	std::cout << result;
	return 0;
}