#include <string>
#include <cstring>
#include <vector>

using namespace std;

int map[101][101];
int visited[101][101];
int dir[4][2] = { { -1,0 } ,{ 0,1 } ,{ 1,0 }, {0, -1} };

int find(int curY, int curX, int n, int m) {
	if (curY == n && curX == m) {
		return 1;
	}
	if (visited[curY][curX] == -1) {
		visited[curY][curX] = 0;
		for (int i = 1; i< 3; i++) {
			int nextY = curY + dir[i][0];
			int nextX = curX + dir[i][1];

			if (nextY >= 1 && nextY <= n && nextX >= 1 && nextX <= m) {
				if (map[nextY][nextX] == -1) continue;
				visited[curY][curX] += find(nextY, nextX, n, m) % 1000000007;
			}
		}
	}
	return visited[curY][curX] % 1000000007;
}

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    
	for (int i = 0; i< puddles.size(); i++) {
		map[puddles[i][1]][puddles[i][0]] = -1;
	}
    
    memset(visited, -1, sizeof(visited));
    answer = find(1, 1, n, m);
    
    return answer % 1000000007;
}