/* 백준 1026: 보물 */

#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int N;
    cin >> N;
    vector <int> arr[2];

    int temp;
    for(int i=0; i<2; i++){
        for(int j=0; j<N; j++){
            cin >> temp;
            arr[i].push_back(temp);
        }
    }

    sort(arr[0].begin(), arr[0].end());
    sort(arr[1].rbegin(), arr[1].rend());

    int ans = 0;
    for(int i=0; i<N; i++){
        ans += arr[0][i] * arr[1][i];
    }

    cout << ans << endl;

    return 0;
}