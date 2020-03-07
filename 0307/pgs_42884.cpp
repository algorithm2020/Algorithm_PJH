#include <string>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 0;
    
    vector<pair<int,int> > load; 
    vector<int> keep;
    int visited[10000];
    
    for(int i = 0; i< routes.size(); i++ ){
        for(int j =0; j< routes[i].size(); j++){
            load.push_back(make_pair(routes[i][j], i  ) );
        }
    }
    
    sort(load.begin(), load.end());
    
    for(int i = 0; i < load.size(); i++){
        if(visited[ load[i].second ] == 0){
            visited[load[i].second ] = 1;
            keep.push_back(load[i].second);
        }
        else if( visited[ load[i].second ] == 1){
            for(int j =0; j< keep.size(); j++){
                visited[ keep[j] ] = -1;
            }
            answer++;
            keep.clear();
        }
    }
    return answer;
}