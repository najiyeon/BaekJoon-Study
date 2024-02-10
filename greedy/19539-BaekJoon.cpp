/* 백준 19539: 사과나무 */

#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif  // ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int result = 0;
    int n;
    cin >> n;
    int tree[n];

    for(int i=0; i<n; i++){
        cin >> tree[i];
    }

    int one = 0;
    int two = 0;

    for(int i=0; i<n; i++){
        two += tree[i] / 2;
        one += tree[i] % 2;
    }

    if(two >= one){
        if((two - one) % 3 == 0){
            result = 1;
        }
    }

    if(result == 0) cout << "NO" << endl;
    else cout << "YES" << endl;

    return 0;
}