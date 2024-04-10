#include <iostream>
#include <vector>

using namespace std;


int N = 0;                  // 노드의 개수
vector<int> Node[100001];   // 노드의 부모
bool visited[100001];       // 방문 여부
int parentNode[100001];     // 부모 노드

void DFS(int num)
{
    visited[num] = true;
    for(int i = 0; i < Node[num].size(); i++)
    {
        int next = Node[num][i];
        if (visited[next] == false)
        {
            // 부모노드는 지금 num에 해당하는 숫자
            // next는 num과 연결된 노드이기 때문
            parentNode[next] = num;
            DFS(next);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;

    for (int i = 2; i < N+1; i++)
    {
        int node1, node2;
        cin >> node1 >> node2;
        Node[node1].push_back(node2);
        Node[node2].push_back(node1);
    }

    // 루트 노드를 1로 설정함
    DFS(1);

    for (int i = 2; i < N+1; i++)
    {
        cout << parentNode[i] << "\n";
    }

    return 0;
}