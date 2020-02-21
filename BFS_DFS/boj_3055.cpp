#include <iostream>
#include <deque>
#include <string>
#include <algorithm>
#include <utility>

#define w -1 //water
#define d 1 //dest
#define ww -3 //wall
#define s -4 //start

int r, c;
char map[50][50];
int visited[50][50] = { 0, };
int path[50][50] = { 0, };
std::pair<int, int> Skeep;
std::deque <std::pair<char, std::pair<int, int> > > que;
std::pair<int, int> D;

int dir[4][2] = { {1,0},{-1,0},{0,-1},{0,1} };

bool isRanged(int y, int x) {
	return ((y >= 0 && y < r) && (x >= 0 && x < c));
}

bool bfs() {
	
	while (!que.empty()) {
		char curState = que.front().first;
		int curY = que.front().second.first;
		int curX = que.front().second.second;
		que.pop_front();

		for (int i = 0; i < 4; i++) {
			int nextY = curY + dir[i][0];
			int nextX = curX + dir[i][1];

			if (isRanged(nextY, nextX) && map[nextY][nextX] != 'X'&& visited[nextY][nextX] >= 0) {
				if (curState == '*' && visited[nextY][nextX] != d) {
					visited[nextY][nextX] = w;
					que.push_back({ '*', {nextY,nextX} });
				}
				else if (curState == 'S' && visited[nextY][nextX] != w) {
					path[nextY][nextX] = path[curY][curX]+1;
					visited[nextY][nextX] = s;
					que.push_back({ 'S',{ nextY,nextX } });
					if (nextY == D.first && nextX == D.second) {
						return true;
					}
				}
			}
		}
		
	}
	return false;
}



int main() {
	std::cin >> r>> c;
	std::string str;
	char init;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			std::cin >> init;
			map[i][j] = init;
			if (init == 'S') {
				Skeep = { i,j };
				visited[i][j] = s;
			}
			else if (init == '*') {
				que.push_back({ '*',{ i,j } });
				visited[i][j] = w;
			}
			else if (init == 'D') {
				D = { i,j };
				visited[i][j] = d;
			}
			else if (init == 'X') {
				visited[i][j] = ww;
			}
		}
	}
	que.push_back({ 'S',Skeep });
	
	bool result;
	result = bfs();

	if (result == false) {
		std::cout << "KAKTUS\n";
		return 0;
	}
    
	std::cout << path[D.first][D.second]<< std::endl;

	return 0;
}