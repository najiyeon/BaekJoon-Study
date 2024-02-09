#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    vector <int> val;

    int temp;
    for(int i=0; i<n; i++){
        cin >> temp;
        val.push_back(temp);
    }

    sort(val.rbegin(), val.rend()); // 내림차순 정렬

    int count = 0;
    for(int i=0; i<n; i++){
        if(k/val[i] != 0){
            count += k / val[i];
            k = k % val[i];
        }
    }

    cout << count << endl;

    return 0;
}