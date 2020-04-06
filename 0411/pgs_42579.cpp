#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

bool comp(pair<string, int> a, pair<string, int> b){
    return a.second > b.second;
}

bool comp2(pair<string, pair<int,int>> a, pair<string, pair<int,int>>b){
    if(a.first == b.first){
        if(a.second.first == b.second.first) return a.second.second < b.second.second;
        else return a.second.first > b.second.first;
    }
    else return a.first < b.first;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    vector<pair<string, pair<int,int>>> arr;
    map<string,int> m;
    
    for(int i =0; i< genres.size(); i++){
        arr.push_back(make_pair(genres[i], make_pair(plays[i], i)) );
        if(m.count(genres[i]) > 0){
            m[genres[i]] = m[genres[i]] + plays[i];    
        }
        else{
            m[genres[i]] = plays[i];
        }
    }
    
    vector<pair<string, int>> temp(m.begin(), m.end());
    
    sort(temp.begin(), temp.end(), comp);
    sort(arr.begin(), arr.end(), comp2);
    
    
    for(int i =0; i< temp.size(); i++){
        int cnt = 0;
        for(int j =0; j < arr.size(); j++){
            if(cnt >= 2) break;
            if(temp[i].first == arr[j].first){
                answer.push_back(arr[j].second.second);
                cnt++;
            }
        }
    }
    
    return answer;
}