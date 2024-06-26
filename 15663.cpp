#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N = 0;  // 1~N
int M = 0;  // 1줄당 M개의 숫자를 가진 수열
vector<int> sortNum;    // 받은 숫자를 정렬

// number[i] = j : number자체가 하나의 수열이 된다.(벡터를 재활용할거임)
// 하나의 수열에서 i번째 숫자가 j가 된다.
vector<int> number; // 숫자를 넣어둘 벡터
vector<bool> isVisited; // 해당 숫자를 포함했는지(방문했는지) 파악하는 벡터

void DFS(int start, int count)
{
    // cout << 1 << "\n";
    // 원하는 숫자만큼 수열을 채웠으면 출력
    if(count == M)
    {
        for (int i = 0; i < M; i++)
            cout << number[i] << " ";
        cout << "\n";
        return;
    }
    // 원하는 숫자만큼 수열을 채울때까지 수열 채우기
    else
    {
        // cout << 2 << "\n";
        int finalNum = 0;

        for (int i = 1; i < N+1; i++)
        {
            // 해당 수열에 숫자를 포함하지 않았으면,
            // 이미 출력된 이전 수열의 같은 자리 숫자가 지금 숫자와 같지 않으면
            // == 지금까지 나왔던 수열이 아니면
            // cout << "finalNum : " << finalNum <<" count : " << count << " i : " << i << " number[count] : " << number[count] << " sortNum[i] : " << sortNum[i] << "\n";
            // cout << 3 << "\n";
            if (isVisited[i] == false && sortNum[i] != finalNum)
            {
                // cout << 4 << "\n";
                isVisited[i] = true;
                number[count] = sortNum[i];
                finalNum = sortNum[i];
                DFS(i+1, count+1);
                // cout << 5 << "\n";
                // DFS가 한번 끝나고 다시 돌아올 때(백트래킹)
                // isVisited를 false로 만들어줘서 number에는 숫자가 있더라도 없는 것처럼 구현
                // 초기화!! 딱 초기화 같은 느낌
                isVisited[i] = false;
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> M;
    number.resize(N+1, 0);
    sortNum.resize(N+1, 0);
    isVisited.resize(N+1, false);

    for (int i = 0; i < N; i++)
    {
        cin >> sortNum[i];
    }

    sort(sortNum.begin(), sortNum.end());

    DFS(1,0);
}