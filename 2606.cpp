#include <iostream>
#include <vector>
using namespace std;

int node = 0;           // 컴퓨터 수
int edge = 0;           // 컴퓨터 쌍 개수
int answer = 0;         // 바이러스에 감염된 컴퓨터 개수
bool isvisted[101];     // 해당 인덱스에 해당하는 컴퓨터에 접근했는지 확인
vector<vector<int>> computer(101);

void DFS(int num)
{
    //cout << num << ":" << computer[num].size() << "\n";
    isvisted[num] = true;
    for(int i : computer[num])
    {
        if (isvisted[i] == false)
        {
            answer++;
            DFS(i);
        }
    }
}
int main()
{
    cin >> node;
    cin >> edge;

    for(int i = 0; i < edge; i++)
    {
        int start_node = 0;
        int end_node = 0;
        cin >> start_node >> end_node;

        computer[start_node].push_back(end_node);
        computer[end_node].push_back(start_node);
    }
    
    DFS(1);
    cout << answer;
    return 0;
}