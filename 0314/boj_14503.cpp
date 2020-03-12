#include <iostream>
#include <deque>

#define up 0
#define right 1
#define down 2
#define left 3

struct bot {
	int Y;
	int X;
	int Dir;
};

std::deque<bot> que;
int map[50][50];
bool visited[50][50];
int N, M;
int r, c, d;
int dir[4][2] = { {0,-1},{1,0},{0,1},{-1,0} };

bool isRanged(int y, int x) {
	return ((y >= 1 && y < N - 1) && (x >= 1 && x < M - 1));
}

bot direction(bot p) {
	bot tmp;
	switch (p.Dir) {
	case up:
		tmp.Y = p.Y + dir[0][0];
		tmp.X = p.X + dir[0][1];
		tmp.Dir = left;
		break;
	case right:
		tmp.Y = p.Y + dir[3][0];
		tmp.X = p.X + dir[3][1];
		tmp.Dir = up;
		break;
	case down:
		tmp.Y = p.Y + dir[2][0];
		tmp.X = p.X + dir[2][1];
		tmp.Dir = right;
		break;
	case left:
		tmp.Y = p.Y + dir[1][0];
		tmp.X = p.X + dir[1][1];
		tmp.Dir = down;
		break;
	}

	return tmp;
}

bot back(bot p) {
	bot tmp;
	switch (p.Dir) {
	case up:
		tmp.Y = p.Y + dir[1][0];
		tmp.X = p.X + dir[1][1];
		break;
	case right:
		tmp.Y = p.Y + dir[0][0];
		tmp.X = p.X + dir[0][1];
		break;
	case down:
		tmp.Y = p.Y + dir[3][0];
		tmp.X = p.X + dir[3][1];
		break;
	case left:
		tmp.Y = p.Y + dir[2][0];
		tmp.X = p.X + dir[2][1];
		break;
	}
    tmp.Dir = p.Dir;
	return tmp;
}


int bfs() {

	int cnt = 1;
	while (true) {

		bot cur;
		cur.Y = que.front().Y;
		cur.X = que.front().X;
		cur.Dir = que.front().Dir;
		
		visited[cur.Y][cur.X] = true; 
		que.pop_front();
		
		bot next;
		for (int i = 0; i < 4; i++) {
			next = direction(cur); 

			if (isRanged(next.Y, next.X) && !visited[next.Y][next.X] && !map[next.Y][next.X]) {

				que.push_back(next);
				cnt++;
				break;
			}
			cur.Dir = next.Dir; 
		}
		if (que.empty()) {
			cur = back(cur);
			if (map[cur.Y][cur.X] == 1 || !isRanged(cur.Y, cur.X)) {
				return cnt;
			}
			que.push_back(cur);
		}	
	}
}

int main() {
	std::cin >> N >> M;
	std::cin >> r >> c >> d;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			std::cin >> map[i][j];
		}
	}

	que.push_back({r,c,d});

	int res = bfs();

	std::cout << res;

	return 0;
}