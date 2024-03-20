#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N = 0;  // 주어지는 총 수의 개수
    vector<int> NVec(10001);
    // vector<int> NVec(10000); : 10000개 크기, 원소 0으로 초기화
    // vector<int> NVec = {10000}; : 1개 크기, 원소 10000으로 초기화

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int num = 0;    // N번만큼 입력받는 숫자
        cin >> num;

        NVec[num]++;
    }

    for (int i = 1; i < NVec.size(); i++)
    {
        if (NVec[i] == 0)
            continue;
        else
        {
            for (int j = 0; j < NVec[i]; j++)
                cout << i << "\n";
        }
    }

    return 0;
}