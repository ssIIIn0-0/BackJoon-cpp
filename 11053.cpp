#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int N = 0;      // 수열의 크기
    vector<int> A;  // 수열을 받을 벡터
    vector<int> DP; // 최고 길이를 받을 벡터
    int answer = 0; // 가장 긴 증가하는 부분의 길이
    int temp = 0;   // 수열을 받을 때 최고값 임시 저장

    cin >> N;
    A.resize(N);
    DP.resize(N);

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    for (int i = 0; i < N; i++)
    {
        // 본인값을 포함해서 최소값은 1이다.
        DP[i] = 1;

        for(int j = i - 1; j >= 0; j--)
        {
            // i번째 숫자보다 작은 숫자를 찾으면,
            if (A[i] > A[j])
            {
                DP[i] = max(DP[i], DP[j]+1);
            }
        }
        answer = max(DP[i], answer);
    }
    cout << answer;
    return 0;
}