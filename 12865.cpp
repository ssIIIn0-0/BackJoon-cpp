#include <iostream>
#include<vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int N = 0;  // 물건의 수
    int K = 0;  // 최대 무게

    int answer = 0;
    vector<pair<int, int>> Things;
    int DP[100001];  // 자기자신을 포함한 총 무게 K 무게 이하의 물건의 최대 가치
    
    cin >> N >> K;
    Things.resize(N+1, pair<int, int>(0, 0));

    for (int i = 1; i < N+1; i++)
    {
        cin >> Things[i].first >> Things[i].second;
    }

    for(int i = 1; i < N+1; i++)  // i : 각각의 물건
    {
        for (int j = K; j > 0; j--) // j : 무게 (최대 무게~ 최소 무게)
        {
            // 최대무게부터 자신의 무게까지 해당되는 DP의 인덱스만 골라서 넣을 거임
            if (Things[i].first <= j)
            {
                // DP[j] : j이하 무게만큼 물건들을 조합해서 최대 가치를 저장
                // 기존 최대 가치 vs 자신의 물건을 포함한 새로운 가치 
                DP[j] = max(DP[j], DP[j - Things[i].first] + Things[i].second);
                
                //cout << "i = " << i << ", DP[j] = " << DP[j] << "\n";
            }
            //cout << "\n";
        }
    }
    //for (int i = 0; i < K+2; i++)
    //    cout << DP[i] << "\n";
    cout << DP[K];
    return 0;
}