#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int N = 0;  // N*N 크기
    int M = 0;  // 합을 구해야하는 횟수
    // 열 기준 각 인덱스까지 숫자의 합이 채워진 표
    // MaxBoard[X][Y]
    vector<vector<int>> MaxBoard;
    
    cin >> N >> M;
    MaxBoard.resize(N+1, vector<int>(N+1, 0));

    // X값 (행)
    for (int i = 1; i < N+1; i++)
    {
        // Y값 (열)
        for (int j = 1; j < N+1; j++)
        {
            cin >> MaxBoard[i][j];
            // 같은 열, 이전 행값을 추가로 더함
            // 같은 열의 누적값
            MaxBoard[i][j] += MaxBoard[i-1][j];
        }
    }

    for (int i = 0; i < M; i++)
    {
        int x1, x2, y1, y2;
        int answer = 0;
        cin >> x1 >> y1 >> x2 >> y2;
        
        // 같은 좌표일 때
        if (x1 == x2 && y1 == y2)
            answer = MaxBoard[x1][y1] - MaxBoard[x1-1][y1];
        // 다른 좌표일 때
        else
        {
            for (int num = y1; num < y2+1; num++)
            {
                answer = answer + (MaxBoard[x2][num] - MaxBoard[x1-1][num]);
            }
        }
        cout << answer << "\n";
    }
    return 0;
}