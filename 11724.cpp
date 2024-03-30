#include <iostream>
#include <vector>
using namespace std;

int N = 0;      // 정점의 개수
int M = 0;      // 간선의 개수
int answer = 0; // 연결 요소의 개수

vector<vector<int>> Nodes(1001);        // 해당 인덱스(정점)에 연결된 정점들 (간선들)
bool isvisited[1001];                    // 해당 정점에 접근했는지 확인

void DFS(int num)
{
    isvisited[num] = true;
    for (int i : Nodes[num])
    {
        if(isvisited[i] == false)
            DFS(i);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    cin >> N;
    cin >> M;

    for (int i = 0; i < M; i++)
    {
        int start_node = 0;
        int end_node = 0;

        cin >> start_node >> end_node;

        Nodes[start_node].push_back(end_node);
        Nodes[end_node].push_back(start_node);
    }

    for (int i = 1; i < N+1; i++)
    {
        if (isvisited[i] == false)
            answer++;
        DFS(i);
    }

    cout << answer;
    return 0;
}