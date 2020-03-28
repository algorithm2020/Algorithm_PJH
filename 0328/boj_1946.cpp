#include <iostream>
#include <vector>
#include <algorithm>

bool comp(std::pair<int, int> a, std::pair<int, int> b) {
	return a.second < b.second;
}

int main() {
	int t, n, cnt = 0;
	std::cin >> t;

	std::vector<int> res;

	while (cnt < t) {
		std::cin >> n;
		std::vector<std::pair<int, int> > arr1;
		std::vector<std::pair<int, int> > arr2;

		for (int i = 0; i < n; i++) {
			int temp1, temp2;
			std::cin >> temp1 >> temp2;
			arr1.push_back(std::make_pair(temp1, temp2));
		}

		arr2.assign(arr1.begin(), arr1.end());

		std::sort(arr1.begin(), arr1.end());
		std::sort(arr2.begin(), arr2.end(), comp);
		int arr1Cnt = 0; int arr2Cnt = 0;

		int arr1comp = arr1[0].second;
		for (int i = 1; i < arr1.size(); i++) {
			if (arr1[i].second < arr1comp) {
				//if (arr1[i].first == arr2[0].first && arr1[i].second == arr2[0].second) continue;
				arr1Cnt++;
				arr1comp = arr1[i].second;
			}
		}
		
		/*
		int arr2comp = arr2[0].first;
		for (int i = 1; i < arr2.size(); i++) {
			
			if (arr2[i].first < arr2comp) {
				if (arr2[i].first == arr1[0].first && arr2[i].second == arr1[0].second) continue;
				arr2Cnt++;
				arr2comp = arr2[i].first;
			}
		}

		int result = (arr2Cnt <= arr1Cnt) ? arr2Cnt : arr1Cnt;

		int add = 2;
		if (arr1[0].first == arr2[0].first && arr1[0].second == arr2[0].second) add = 1;
		
		res.push_back(result + add);
		*/
		res.push_back(arr1Cnt + 1);

		cnt++;
	}

	for (int i = 0; i < res.size(); i++) {
		std::cout << res[i]<< '\n';
	}

	return 0;
}