#include <iostream>
#include <deque>
#include <cstring>

int n, m;
int map[301][301];
std::deque<std::pair<int,int> > que;
bool visited[301][301];
int dir[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };
int cnt;

void bfs() {

	std::deque<std::pair<int, int> > copyQue;
	copyQue = que;
	que.clear();

	while (!copyQue.empty()) {
		int curY = copyQue.front().first;
		int curX = copyQue.front().second;
		copyQue.pop_front();

		for (int i = 0; i < 4; i++) {
			int nextY = curY + dir[i][0];
			int nextX = curX + dir[i][1];

			if (nextY >= 0 && nextY < n && nextX >= 0 && nextX < m) {
				if (map[nextY][nextX] == 0 && map[curY][curX] > 0 && !visited[nextY][nextX]) {
					map[curY][curX]--;
					visited[curY][curX] = true;
				}
			}
		}
		if (map[curY][curX] > 0) que.push_back(std::make_pair(curY, curX));
	}

}

void dfs(int curY, int curX) {

	visited[curY][curX] = true;
	for (int i = 0; i < 4; i++) {
		int nextY = curY + dir[i][0];
		int nextX = curX + dir[i][1];

		if (nextY >= 0 && nextY < n && nextX >= 0 && nextX < m) {
			if (map[nextY][nextX] > 0 && !visited[nextY][nextX]) {
				cnt++;
				dfs(nextY, nextX);
			}
		}
	}
	//visited[curY][curX] = false;
}

int main() {
	
	std::cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			std::cin >> map[i][j];
			if (map[i][j] != 0) que.push_back(std::make_pair(i, j));
		}
	}
	int year = 1;
	while (true) {
		bfs();
		memset(visited, false, sizeof(visited));
		if (que.empty()) {
			std::cout << '0';
			break;
		}
		cnt = 1;
		dfs(que.front().first, que.front().second);
		memset(visited, false, sizeof(visited));
		if (cnt != que.size()) {
			std::cout << year;
			break;
		}

		year++;
	}

	return 0;
}