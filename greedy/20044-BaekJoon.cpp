/* 백준 20044: Project Teams */

#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;

    int weight[2*n];
    for(int i=0; i<2*n; i++){
        cin >> weight[i];
    }

    sort(weight, weight + 2*n);

    int sum[n];

    for(int i=0; i<n; i++){
        sum[i] = weight[i] + weight[2*n - 1 - i];
    }

    int min = *min_element(sum, sum + n);

    cout << min << endl;

    return 0;
}