#include <iostream>
#include <vector>
using namespace std;


// 가로, 세로, 총 배추 개수
int M = 0;  // 가로
int N = 0;  // 세로
int K = 0;  // 총 배추 개수

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
// 확인한 곳 : 0, // 확인하지 않은 곳 && 배추 있는 곳 : 1
void dfs(int x, int y, vector<vector<int>> &arr)
{
    // 확인 했으니까 일단 0으로 초기화
	arr[x][y] = 0;

	for (int i = 0; i < 4; i++)
    {
		int _x = x + dx[i];
		int _y = y + dy[i];
        // 지금 들어온 좌표기준 동서남북 중 1인 곳이 있으면 다시 dfs
        // 없으면 끝
		if (_x >= 0 && _x < M && _y >= 0 && _y < N && arr[_x][_y] == 1)
        {
			dfs(_x, _y, arr);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    // 테스트 케이스 개수
	int T;
	cin >> T;

	for (int i = 0; i < T; i++)
    {
		cin >> M >> N >> K;

        // 배추밭
        // 주의 : 세로 가로로 설정
		vector<vector<int>> arr(N, vector<int>(M, 0));

        // 배추 심기
		for (int j = 0; j < K; j++)
        {
			int x, y;
			cin >> y >> x;
			arr[x][y] = 1;
		}

        // 지렁이 총 개수
		int count = 0;

        // 세로 먼저
		for (int n = 0; n < N; n++)
        {   
            // 가로에 대해
			for (int m = 0; m < M; m++)
            {
				if (arr[n][m] == 1)
                {
					count++;
					dfs(n, m, arr);
				}
			}
		}

		cout << count << "\n";

	}
}

