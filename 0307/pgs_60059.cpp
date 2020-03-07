#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<pair<int, int> >hole;
int size;

bool comp(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	return a.second < b.second;
}

void rotate() {
	for (int i = 0; i < hole.size(); i++) {
		int temp = hole[i].second;
		hole[i].second = size - hole[i].first;
		hole[i].first = temp;
	}
}

bool check(int y, int x, int s, vector<vector<int>> keyCp) {
	int cnt = 0;
	for (int i = y; i < y + s; i++) {
		for (int j = x; j < x + s; j++) {

			for (int k = 0; k < hole.size(); k++) {
				// if(i == 1) cout << i - y<< hole[k].first<< j - x<< hole[k].second << endl;
				if ((i - y) == (hole[k].first) && (j - x) == (hole[k].second)) {
					if (keyCp[i][j] == 1) {
						cnt++;
					}
					if (keyCp[i][j] == 0) return false;
				}
			}

		}
	}

	if (cnt == hole.size()) return true;
	else return false;
}


bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
	bool answer = false;

	for (int i = 0; i < lock.size(); i++) {
		for (int j = 0; j < lock[i].size(); j++) {
			if (lock[i][j] == 0) hole.push_back(make_pair(i, j));
		}
	}

	if (hole.size() == 0) {
		return true;
	}

	vector<pair<int, int> >holeCp;
	holeCp = hole;
	sort(holeCp.begin(), holeCp.end());
	int xMax, xMin, yMax, yMin;
	yMin = holeCp.front().first;
	yMax = holeCp.back().first;

	sort(holeCp.begin(), holeCp.end(), comp);
	xMin = holeCp.front().second;
	xMax = holeCp.back().second;

	size = ((yMax - yMin) >= (xMax - xMin)) ? (yMax - yMin) : (xMax - xMin);

	if (size + 1 > key.size()) return false;


	if (size == 0) {
		hole[0].first = 0;
		hole[0].second = 0;
	}
	else {
		for (int i = 0; i < hole.size(); i++) {
			hole[i].first -= yMin;
			hole[i].second -= xMin;
		}
	}
	
	for (int i = 0; i < key.size() - size; i++) {
		for (int j = 0; j< key[i].size() - size; j++) {
			for (int k = 0; k < 4; k++) {
				bool res = check(i, j, size + 1, key);
				if (res) {
					return true;
				}
				else {
					rotate();
				}
			}
		}
	}

	return answer;
}