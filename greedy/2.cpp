#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const pair<int, int>& a, const pair<int, int>& b) {
    // 먼저 second 값을 비교하고, 같으면 first 값을 비교
    if (a.second != b.second) {
        return a.second < b.second;
    } else {
        return a.first < b.first;
    }
}

int main(){
    int n;
    cin >> n;
    int temp1;
    int temp2;

    vector<pair<int, int>> v;
    for (int i=0; i<n; i++){
        cin >> temp1 >> temp2;
        v.push_back(make_pair(temp1, temp2));
    }

    sort(v.begin(), v.end(), compare);

    int index = 0;
    int end = v[0].second;
    int count = 1;

    while(index < n){
        index++;
        if (v[index].first >= end){
            end = v[index].second;
            count++;
        }
    }

    cout << count << endl;

    return 0;
}