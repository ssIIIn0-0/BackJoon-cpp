#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int HouseNum = 0;   // 집의 수
int answer = 0;     // 모든 집을 색칠하는 최소 비용
vector<vector<int>> RGBCost (2, vector<int>(3, 0));     // 색칠하는 비용(총 집의 개수, RGB 비용)
vector<vector<int>> DP (2, vector<int>(3, 0));          // index번째 집기준 최소값을 저장


int main()
{
    cin >> HouseNum;
    RGBCost.resize(HouseNum+1, vector<int>(3, 0));
    DP.resize(HouseNum+1, vector<int>(3, 0));

    for (int i = 1; i < HouseNum+1; i++)
    {
        cin >> RGBCost[i][0] >> RGBCost[i][1] >> RGBCost[i][2];
        DP[i][0] = RGBCost[i][0] + min(DP[i-1][1], DP[i-1][2]);
        DP[i][1] = RGBCost[i][1] + min(DP[i-1][0], DP[i-1][2]);
        DP[i][2] = RGBCost[i][2] + min(DP[i-1][0], DP[i-1][1]);
    }

    answer = min({DP[HouseNum][0], DP[HouseNum][1], DP[HouseNum][2]});
    cout << answer;

    return 0;
}