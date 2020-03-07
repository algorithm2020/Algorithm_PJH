#include <iostream>
#include <deque>
#include <vector>
#include <cstring>


int N, K, L;
int map[100][100];
int dirmap[100][100];
enum {Right =0, Up, Left, Down};
int dir[4][2] = { {0,1},{-1,0},{0,-1},{1,0} };
std::deque<std::pair<int, int> > time;
std::deque<std::pair<int, int> > snake;
int length = 1;
int howmuch = 0;

bool isRanged(int y, int x) {
	return ((y >=0 && y < N ) && (x >= 0 && x < N ));
}

int rotate(int prepose, int ro) {
	int result;
	switch (prepose) {
	case Right:
		if (ro == Down)
			result = Down;
		else if (ro == Left)
			result = Up;
		break;
	case Down:
		if (ro == Down)
			result = Left;
		else if (ro == Left)
			result = Right;
		break;
	case Left:
		if (ro == Down)
			result = Up;
		else if (ro == Left)
			result = Down;
		break;
	case Up:
		if (ro == Down)
			result = Right;
		else if (ro == Left)
			result = Left;
		break;

	}

	return result;
}



void dfs(int curY, int curX, int pose, int t) {
	if (time.size()) {
		if (time.front().first == t) {
		pose = rotate(pose, time.front().second);

		time.pop_front();
		}
	}
	//dirmap[curY][curX] = pose;

	int nextY = curY + dir[pose][0];
	int nextX = curX + dir[pose][1];
	snake.push_back(std::make_pair(nextY, nextX));
	if(isRanged(nextY, nextX)){
		if (map[nextY][nextX] == 1 ) {//apple
			
			for (int i = 0; i < snake.size(); i++) {
				map[snake[i].first][snake[i].second] = 2;
			}
		}
		else if (map[nextY][nextX] == 0) {
			for (int i = 0; i < snake.size(); i++) {
				map[snake[i].first][snake[i].second] = 0;
			}
			snake.pop_front();
			for (int i = 0; i < snake.size(); i++) {	
				map[snake[i].first][snake[i].second] = 2;
			}
		}
		else if (map[nextY][nextX] == 2) {
			howmuch = t;
			return;
		}
		//printMap(t);
		dfs(nextY, nextX, pose, t + 1);
	}
	else {
		howmuch = t;
		return;
	}
}


int main() {
	std::cin >> N;

	std::cin >> K;
	memset(dirmap, 0, sizeof(dirmap));
	memset(map, 0, sizeof(map));
	for (int i = 0; i < K; i++) {
		int tmpy, tmpx;
		std::cin >> tmpy >> tmpx;
		map[tmpy-1][tmpx-1] = 1;
	}
	std::cin >> L;
	for (int i = 0; i < L; i++) {
		int t, dd;
		char d;
		std::cin >> t >> d;
		if (d == 'L') {
			dd = Left;
		}
		else if (d == 'D') {
			dd = Down;
		}
		time.push_back(std::make_pair(t, dd));
	}

	snake.push_back(std::make_pair(0, 0));
	dfs(0, 0, 0, 0);

	std::cout << howmuch +1;

	

	return 0;
}