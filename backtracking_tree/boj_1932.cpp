#include <iostream>
#include <vector>

int arr[500][500];
bool visited[500];


int main() {
	int n;
	std::cin >> n;

	int temp;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i + 1; j++) {
			std::cin >> arr[i][j];
		}
	}

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i + 1; j++) {

			if (j == 0) {
				arr[i][j] += arr[i - 1][j];
				continue;
			}
			if (j == i) {
				arr[i][j] += arr[i - 1][j - 1];
				continue;
			}

			int bigger = ( arr[i - 1][j - 1] >= arr[i - 1][j]) 
				? arr[i - 1][j - 1] : arr[i-1][j];
			arr[i][j] += bigger;
		}
	}

	int res = 0;
	
	for (int i = 0; i < n; i++) {
		if (arr[n - 1][i] > res) {
			res = arr[n - 1][i];
		}
	}
	

	
	std::cout << res;

	return 0;
}
