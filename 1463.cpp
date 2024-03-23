#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N = 0;  // 정수 N
    int dp[1000001];  // 최종적으로 각 인덱스 N을 1로 만드는데 연산한 최소횟수
    cin >> N;

    dp[1] = 0;
    
    for(int i = 2; i < N + 1; i++)
    {
        // 최종 연산의 기본 최소값(이거보다 작거나 같아야함)
        dp[i] = dp[i - 1] + 1;

        // 3으로 나눠질 경우
        // 3으로 나누는게 더 최소 연산 횟수이므로 먼저 조건문 실행
        if (i % 3 == 0)
            dp[i] = min(dp[i], dp[i/3] + 1);
        // 2로 나눠질 경우
        if(i % 2 == 0)
            dp[i] = min(dp[i], dp[i/2] + 1);
    }

    cout << dp[N];

    return 0;
}