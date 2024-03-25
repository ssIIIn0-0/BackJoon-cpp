#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N = 0;      // 총 계단 개수
    int Arr[301];   // 계단 개수는 300 이하 이므로
    int DP[301];    // N번째 계단에서의 최대값

    cin >> N;

    for (int i = 1; i < N + 1; i++)
    {
        cin >> Arr[i];
    }

    DP[1] = Arr[1];
    DP[2] = Arr[1] + Arr[2];
    DP[3] = max(Arr[1] + Arr[3], Arr[2] + Arr[3]);

    for (int i = 4; i < N + 1; i++)
    {
        DP[i] = max(DP[i-3] + Arr[i-1] + Arr[i], DP[i-2] + Arr[i]);
    }
    
    cout << DP[N];
    return 0;
}