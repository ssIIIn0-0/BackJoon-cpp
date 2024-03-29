#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int M = 0;      // 상자 가로
int N = 0;      // 상자 세로
int H = 0;      // 상자 높이
int date = 0;   // 토마토가 다 익을 때까지 걸리는 최소 일수

vector<vector<vector<int>>> Box;                // 상자에 담긴 토마토를 받을 3차원벡터
queue<pair<pair<int, int>, int>> Tomato;        // 오늘 기준 익은 토마토의 위치를 담을 큐 (N, M), H
queue<pair<pair<int, int>, int>> NextTomato;    // 내일 기준 익을 토마토의 위치를 담을 큐


int dx[] = {1, 0, -1, 0, 0, 0};
int dy[] = {0, -1, 0, 1, 0, 0};
int dz[] = {0, 0, 0, 0, 1, -1};

void BFS(int x, int y, int z)
{
    // 동서남북 위아래로 토마토 탐색시작
    for (int i = 0; i < 6; i++)
    {
		int nx = x + dx[i];
		int ny = y + dy[i];
		int nz = z + dz[i];

        // 탐색하는 좌표가 상자 범위안에 있고, 익지 않은 토마토가 있을 경우
        if (nx >= 0 && nx < N && ny >= 0 && ny < M && nz >= 0 && nz < H && Box[nx][ny][nz] == 0)
        {
            // 익은 토마토로 변경
            Box[nx][ny][nz] = 1;
            // 새로운 익은 토마토(새로운 정점)의 좌표 저장
            NextTomato.push(pair<pair<int, int>, int> (pair<int, int>(nx, ny),nz));
        }

    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> M >> N >> H;
    // 입력받은 토마토 박스 크기만큼 벡터 크기 설정
    // 1012처럼 세로먼저!
    Box.resize(N, vector<vector<int>>(M, vector<int>(H)));
    
    // 토마토 담기 및 익은 토마토는 위치 기억하지
    for (int k = 0; k < H; k++)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                cin >> Box[i][j][k];
                if (Box[i][j][k] == 1)  // 들어있는 토마토가 익었으면, 큐에 익은 토마토 위치 저장
                    Tomato.push(pair<pair<int, int>, int> (pair<int, int> (i, j), k));
            }
        }
    }

    // 익은 토마토가 있으면,
    while (!Tomato.empty())
    {
        // BFS(x, y, z) 입력
        BFS(Tomato.front().first.first, Tomato.front().first.second, Tomato.front().second);
        // 익은 토마토(한개의 정점)를 기준으로 BFS돌렸으므로, 이 토마토를 제외하고 BFS탐색을 해야함
        Tomato.pop();

        // 만약 방금 토마토가 마지막 토마토였다면, 
        if(Tomato.empty())
        {
            // 날짜를 추가
            date++;
            // 새로운 토마토를 메인토마토를 다루는 큐에 저장
            while (!NextTomato.empty())
            {
                Tomato.push(pair<pair<int, int>, int> (pair<int, int> (NextTomato.front().first.first, NextTomato.front().first.second), NextTomato.front().second));
                NextTomato.pop();
            }
        }
    }

    // 정답출력
    // 모든 토마토가 익지 않았을 경우를 찾기 위해 3차원 벡터 전체 탐색
    for (int k = 0; k < H; k++)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (Box[i][j][k] == 0)
                {
                    cout << -1;
                    return 0;
                }
            }
        }
    }

    cout << date - 1;
    return 0;

}
