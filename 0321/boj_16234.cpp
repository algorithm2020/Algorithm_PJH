#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <queue>

int A[51][51];
int visited[51][51];
int groups[2500];
int N, R, L;
bool boolean = false;
int dir[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };

std::vector<std::pair<int,int> >united;
int sum = 0;
int cnt = 0;


void bfs(int initY, int initX, int group) {

	std::queue<std::pair<int, int> > que;
	que.push(std::make_pair(initY, initX));
	united.push_back(std::make_pair(initY, initX));
	visited[initY][initX] = group;
	sum += A[initY][initX];
	cnt++;

	while(!que.empty()){
			int curY = que.front().first;
			int curX = que.front().second;
			que.pop();

			bool self = false;
			
			for (int k = 0; k < 4; k++) {
				int nextY = curY + dir[k][0];
				int nextX = curX + dir[k][1];

				if (nextY >= 0 && nextY < N && nextX >= 0 && nextX < N && visited[nextY][nextX] == 0) {
					int subs = abs(A[nextY][nextX] - A[curY][curX]);
					if (L <= subs && R >= subs) {
						sum += A[nextY][nextX];
						cnt++;
						self = true;
						visited[nextY][nextX] = group;
						que.push(std::make_pair(nextY, nextX));
						united.push_back(std::make_pair(nextY, nextX));
					}
				}
			}
			//if (self) {
			//	sum += A[curY][curX];
			//	cnt++;
			//	visited[curY][curX] = group;
			//	united.push_back(std::make_pair(curY, curX));
			//}
		}

	if (united.size() - 1) {
		int avg = sum / cnt;
		boolean = true;
		for (int i = 0; i< united.size(); i++) {
			int x = united[i].first;
			int y = united[i].second;
			A[x][y] = avg;
		}

	}
}

int main() {

	std::cin >> N >> L >> R;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			std::cin >> A[i][j];
		}
	}
	
	int center = N / 2;

	int result = 0;

	while (true) {
		boolean = false;
		cnt = 0; sum = 0;
		memset(visited, 0, sizeof(visited));
		int group = 1;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (visited[i][j] == 0) {
					bfs(i, j, group);
					cnt = 0; sum = 0; group++;
					united.clear();
				}
			}
		}
		if (boolean) result++;
		else break;
	}
	std::cout << result;
	return 0;
}