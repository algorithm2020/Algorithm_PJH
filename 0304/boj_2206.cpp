#include <iostream>
#include <string>
#include <queue>

int n, m;
int map[1000][1000];
int mem[1000][1000][2];
std::queue<std::pair<std::pair<int,int> ,int> > que;
int dir[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };

int bfs() {
	que.push(std::make_pair(std::make_pair(0, 0), 1));
	mem[0][0][1] = 1;
	
	while (!que.empty()) {
		int curY = que.front().first.first;
		int curX = que.front().first.second;
		int curB = que.front().second;
		que.pop();

		if (curY == n - 1 && curX == m - 1) return mem[curY][curX][curB];

		for (int i = 0; i < 4; i++) {
			int nextY = curY + dir[i][0];
			int nextX = curX + dir[i][1];
			
			if (nextY >= 0 && nextY < n && nextX >= 0 && nextX < m) {
				if (map[nextY][nextX] == 1 && curB) {
					mem[nextY][nextX][curB - 1] = mem[curY][curX][curB] + 1;
					que.push(std::make_pair(std::make_pair(nextY, nextX), curB - 1));
				}
				else if (map[nextY][nextX] == 0 && mem[nextY][nextX][curB] == 0) {
					mem[nextY][nextX][curB] = mem[curY][curX][curB] + 1;
					que.push(std::make_pair(std::make_pair(nextY, nextX), curB));
				}
			}
		}
	}
	return -1;
}

int main() {
	std::cin >> n >> m;

	for (int i = 0; i < n; i++) {
		std::string temp;
		std::cin >> temp;
		for (int j = 0; j < m; j++) {
			map[i][j] = temp[j] - '0';
		}
	}

	std::cout << bfs();


	return 0;
}