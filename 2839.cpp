#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int sugarNum = 0;   // 설탕 총 kg
    int answer = 0;     // 총 봉지 개수

    cin >> sugarNum;

    while(sugarNum >= 0)
    {
        if(sugarNum % 5 == 0)
        {
            answer += sugarNum / 5;
            cout << answer;
            return 0;
        }
        else
        {
            sugarNum -= 3;
            answer++;
        }
    }

    cout << -1;
}