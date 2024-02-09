#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main(){
    int N; // 책의 개수
    int M; // 한 번에 들 수 있는 책의 개수
    cin >> N >> M;

    int temp;
    vector <int> pos1; // negative pos
    vector <int> pos2; // positive pos
    for (int i=0; i<N; i++){
        cin >> temp;
        if (temp > 0) pos2.push_back(temp);
        else pos1.push_back(-temp); // 절대값으로 저장
    }

    sort(pos1.begin(), pos1.end()); // 오름차순 정렬
    sort(pos2.begin(), pos2.end()); // 오름차순 정렬 

    int steps = 0; // 걸음 수

    // negative part
    int first = pos1.size() % M;
    int count = pos1.size() / M;
    
    if(count != 0){
        for (int i=1; i<count; i++){
            steps += 2 * pos1[first - 1 + (M*i)];
        }
        if(pos2.size() == 0){
            steps += pos1[first - 1 + (M*count)];
        }
        else if(pos1[pos1.size()-1] > pos2[pos2.size()-1]){
            steps += pos1[first - 1 + (M*count)];
        }
        else{
            steps += 2 * pos1[first - 1 + (M*count)];
        }

        if(first!= 0) steps += 2 * pos1[first - 1];
    }
    else if (first!= 0){
        if(pos2.size() == 0) steps += pos1[first - 1];
        else if(pos1[pos1.size()-1] > pos2[pos2.size()-1]) steps += pos1[first - 1];
        else steps += 2 * pos1[first - 1];
    }

    // positive part
    first = pos2.size() % M;
    count = pos2.size() / M;

    if(count != 0){
        for (int i=1; i<count; i++){
            steps += 2 * pos2[first - 1 + (M*i)];
        }
        if(pos1.size() == 0) steps += pos2[first - 1 + (M*count)];
        else if(pos1[pos1.size()-1] > pos2[pos2.size()-1]){
            steps += 2 * pos2[first - 1 + (M*count)];
        }
        else{
            steps += pos2[first - 1 + (M*count)];
        }

        if(first!= 0) steps += 2 * pos2[first - 1];
    }
    else if (first!= 0){
        if(pos1.size() == 0) steps += pos2[first - 1 + (M*count)];
        else if(pos2[pos2.size()-1] > pos1[pos1.size()-1]) steps += pos2[first - 1];
        else steps += 2 * pos2[first - 1];
    }

    cout << steps <<endl;

    return 0;
}

/*

#include <iostream>

using namespace std;


int main(void) {

    int n,m,temp,loc;
    int far = 0;
    cin >> n >> m;
    vector<int> p[2];
    for(int i=0;i<n;i++){
        cin >> temp;
        if(temp>0) p[0].push_back(temp); // 양수 저장
        else{ // 음수 저장
            temp *= -1;
            p[1].push_back(temp);
        }
        far = far > temp ? far : temp; // 가장 먼 애
    }

    int ans = -far; // 제일 멀리있는 애들은 갔다가 안돌아오니까

    for(int i=0;i<2;i++){
        sort(p[i].begin(), p[i].end());  // 오름차순 정렬
        loc = p[i].size()-1; // 가장 먼 위치
        while(loc>=0){ 
            ans += 2 * p[i][loc];
            loc -= m;
        }
    }

    cout << ans;
    return 0;
}

*/