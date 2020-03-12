#include <iostream>
#include <string.h>

int map[50][50] = {0,};
int dir[8][2] = { {-1,-1},{-1,0},{-1,1}, {0,-1},{0,1}, {1,-1},{1,0},{1,1} };
int w, h;

bool isRanged(int y, int x) {
	return ((y >= 0 && y < h) && (x >= 0 && x < w));
}

void dfs(int curY, int curX) {
	map[curY][curX] = 2;

	for (int i = 0; i < 8; i++) {
		int dy = curY + dir[i][0];
		int dx = curX + dir[i][1];

		if (isRanged(dy, dx) && map[dy][dx] == 1) {
			dfs(dy, dx);
		}
	}
}

int main() {

	int tmp1, tmp2;


	while (1) {
        std::cin >> w >> h;

		if (w == 0 && h == 0) {
			return 0;
		}

		memset(map, 0, sizeof(map));

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
                std::cin >> map[i][j];
			}
		}

		int cnt = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (map[i][j] == 1) {
					dfs(i, j);
					cnt++;
				}
			}
		}

        std::cout << cnt;
	}

	return 0;
}