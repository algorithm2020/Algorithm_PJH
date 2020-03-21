#include <iostream>
#include <algorithm>

int dp[16][3];
int map[16][2];
int N, result;

void dfs(int day, int sum) {

	if (day == N + 1) {
		result = std::max(result,sum);
		return;
	}
	
	if (day + map[day][0] <= N + 1) {
		dfs(day + map[day][0], sum + map[day][1]);
	}
	if (day + 1 <= N + 1) {
		dfs(day + 1, sum);
	}
}

int main() {
	std::cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < 2; j++) {
			std::cin >> map[i][j];
		}
	}

	dfs(1, 0);

	std::cout << result;

	return 0;
}