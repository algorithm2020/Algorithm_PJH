#include <iostream>
#include <deque>
#include <cstring>

std::deque<int> que;
int visited[100001];
int n, k;

int find() {
	while (!que.empty()) {
		int curPos = que.front();
		que.pop_front();
		
		if (curPos == k) {
			return visited[curPos];
		}

		int nextPos = curPos * 2;
		if(nextPos >= 0 && nextPos <= 100000 && visited[nextPos] == -1){
			visited[nextPos] = visited[curPos] + 1;
			que.push_back(nextPos);
		}

		nextPos = curPos + 1;
		if (nextPos >= 0 && nextPos <= 100000 && visited[nextPos] == -1) {
			visited[nextPos] = visited[curPos] + 1;
			que.push_back(nextPos);
		}
		nextPos = curPos - 1;
		if (nextPos >= 0 && nextPos <= 100000 && visited[nextPos] == -1) {
			visited[nextPos] = visited[curPos] + 1;
			que.push_back(nextPos);
		}
	}
}


int main() {
	std::cin >> n >> k;

	memset(visited, -1, sizeof(visited));
	que.push_back(n);
	visited[n] = 0;
	
	std::cout << find();

	return 0;
}