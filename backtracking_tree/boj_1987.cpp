#include <iostream>
#include <string>

int r, c;
char arr[21][21];
bool checked[26] = { false, };
int dir[4][2] = { { -1,0 },{ 0,1 },{ 1,0 },{ 0,-1 } };
int res = 0;

bool isRanged(int y, int x) {
	return (y >= 0 && y < r && x >= 0 && x < c);
}

int toInt(char a) {
	return (int)a - 'A';
}

void dfs(int curY, int curX, int cnt) {
	for (int i = 0; i < 4; i++) {
		int nextY = curY + dir[i][0];
		int nextX = curX + dir[i][1];

		if (isRanged(nextY, nextX) && !checked[toInt(arr[nextY][nextX])]) {
			checked[toInt(arr[nextY][nextX])] = true;
			dfs(nextY, nextX, cnt + 1);
			checked[toInt(arr[nextY][nextX])] = false;
		}
	}
	res = (res < cnt) ? cnt : res;
}

int main() {

	std::cin >> r >> c;

	for (int i = 0; i< r; i++) {
		for (int j = 0; j< c; j++) {
			std::cin >> arr[i][j];
		}
	}
	checked[toInt(arr[0][0])] = true;
	dfs(0, 0, 1);
	std::cout << res;
	return 0;
}