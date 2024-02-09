#include <iostream>

using namespace std;

int main(){
    int n;
    int count = 0;
    cin >> n;
    n = 1000 - n;

    int temp[6] = {500, 100, 50, 10 , 5, 1};

    for(int i=0; i < sizeof(temp) / sizeof(temp[0]); i++){
        count += n / temp[i];
        n = n % temp[i];
    }

    cout << count;

    return 0;
}