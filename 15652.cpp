#include <iostream>
#include <vector>
using namespace std;

int N = 0;  // 1~N
int M = 0;  // 1줄당 M개의 숫자를 가진 수열

// number[i] = j : number자체가 하나의 수열이 된다.(재활용할거임)
// 하나의 수열에서 i번째 숫자가 j가 된다.
vector<int> number; // 숫자를 넣어둘 벡터


void DFS(int start, int count)
{
    // 원하는 숫자만큼 수열을 채웠으면 출력
    if(count == M)
    {
        for (int i = 0; i < M; i++)
            cout << number[i] << " ";
        cout << "\n";
    }

    // 원하는 숫자만큼 수열을 채울때까지 수열 채우기
    else
    {
        for (int i = start; i < N+1; i++)
        {
            number[count] = i;
            // 15650과 다르게 시작을 본인 번호부터 시작해야 하기때문에
            // i+1이 아닌 i를 넣어준다.
            DFS(i, count+1);
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> M;
    number.resize(N+1, 0);
    DFS(1,0);
}