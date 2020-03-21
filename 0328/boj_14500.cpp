#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

int n, m;
int map[501][501];
bool visited[501][501];
int dir[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };
std::vector<int> result;
std::vector<std::pair<int,int> > keep;
std::vector<int> pose;
int max = 0;


void dfs(int curY, int curX, int cnt, int sum, std::vector<int> pos, std::vector<std::pair<int, int> > keeep) {
	if (cnt >= 4) {
		if (sum > max) {
			result.push_back(sum);
			max = sum;
		}
		return;
	}
	
	for (int i = 0; i < 4; i++) {
		int nextY = curY + dir[i][0];
		int nextX = curX + dir[i][1];

		if (nextY >= 0 && nextY < n && nextX >= 0 && nextX < m) {
			if (!visited[nextY][nextX]) {
				if (cnt == 2) {
					if (pos[0] == i) {
						if (pos[0] == 0 || pos[0] == 2) {
							if (curY >= 0 && curY < n && curX + 1>= 0 && curX + 1 < m) {
								if (!visited[curY][curX + 1 ]) {
									keeep.push_back(std::make_pair(map[curY][curX + 1], i));
								}
							}
							if (curY >= 0 && curY < n && curX -1  >= 0 && curX - 1 < m) {
								if (!visited[curY][curX - 1]) {
									keeep.push_back(std::make_pair(map[curY][curX - 1], i));
								}
							}
						}
						else {
							if (curY - 1>= 0 && curY - 1< n && curX >= 0 && curX  < m) {
								if (!visited[curY -1][curX]) {
									keeep.push_back(std::make_pair(map[curY -1 ][curX ], i));
								}
							}
							if (curY + 1 >= 0 && curY + 1< n && curX >= 0 && curX  < m) {
								if (!visited[curY + 1][curX]) {
									keeep.push_back(std::make_pair(map[curY + 1][curX], i));
								}
							}
						}
					}
				}
				if (cnt == 3) {
					if (pos[0] == pos[1]) {
						for (int k = 0; k < keeep.size(); k++) {
							if (keeep[k].first + sum > max) {
								result.push_back(keeep[k].first + sum);
								max = keeep[k].first + sum;
							}
						}
						keeep.clear();
					}
				}
				visited[nextY][nextX] = true;
				pos.push_back(i);
				dfs(nextY, nextX, cnt + 1, sum + map[nextY][nextX], pos, keeep);
				visited[nextY][nextX] = false;
				pos.pop_back();
			}
		}
	}
}

int main() {
	std::cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			std::cin >> map[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			visited[i][j] = true;
			dfs(i, j, 1, map[i][j], pose, keep);
			visited[i][j] = false;
		}
	}

	std::sort(result.begin(), result.end());

	std::cout << result.back();
		

	return 0;
}

///와 미친 https://www.acmicpc.net/source/18275852