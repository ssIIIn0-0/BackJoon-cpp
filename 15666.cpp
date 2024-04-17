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

void DFS(int start, int count)
{
    // cout << 1 << "\n";
    // 원하는 숫자만큼 수열을 채웠으면 출력
    if(count == M+1) 
    // 이전 자리 숫자를 파악하느라 count-1을 넣었고,
    // 이로인해 0부터 M-1이 아닌 1부터 M까지 number의 배열에 수를 넣게 되어 M+1일 때 출력하도록 수정
    {
        for (int i = 1; i < M+1; i++)
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
            // 이미 출력된 이전 수열의 같은 자리 숫자가 지금 숫자와 같지 않으면
            // == 지금까지 나왔던 수열이 아니면
            // 그리고 현재 수열의 이전 자리 숫자가 지금 숫자보다 작으면 (오름차순에 의해서)
            if (sortNum[i] != finalNum && number[count-1] <= sortNum[i])
            {
                number[count] = sortNum[i];
                finalNum = sortNum[i];
                DFS(i+1, count+1);
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> M;
    number.resize(M+1, 0);
    sortNum.resize(N+1, 0);

    for (int i = 0; i < N; i++)
    {
        cin >> sortNum[i];
    }

    sort(sortNum.begin(), sortNum.end());

    DFS(1,1);
}