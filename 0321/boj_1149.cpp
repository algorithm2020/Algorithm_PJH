#include <iostream>
#include <algorithm>

int dp[1001][3];
int map[1001][3];
int n;

int dpdp() {
	for (int i = 1; i <= n; i++)
	{
		dp[i][0] = map[i][0] + std::min(dp[i - 1][1], dp[i - 1][2]);
		dp[i][1] = map[i][1] + std::min(dp[i - 1][0], dp[i - 1][2]);
		dp[i][2] = map[i][2] + std::min(dp[i - 1][0], dp[i - 1][1]);
	}
	return std::min( std::min(dp[n][0], dp[n][1]), dp[n][2]);
}

int main() {
	
	std::cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 3; j++) {
			std::cin >> map[i][j];
		}
	}
	
	dp[0][0] = dp[0][1] = dp[0][2] = 0;
	map[0][0] = map[0][1] = map[0][2] = 0;

	int result = dpdp();

	std::cout << result;
	
	return 0;
}