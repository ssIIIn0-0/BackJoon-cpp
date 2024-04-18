#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


int people = 0;                 // 총 사람의 수
int partyNum = 0;               // 총 파티의 수
int knowTruth = 0;              // 진실을 아는 사람의 수
int answer = 0;                 // 과장된 이야기를 할 수 있는 파티 개수

queue<int> knowTruthQueue;              // 진실을 아는 사람의 queue
vector<vector<int>> partyArray;         // 각 파티에 참가한 사람의 번호


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> people >> partyNum;

    cin >> knowTruth;
    for (int i = 0; i < knowTruth; i++)
    {
        int temp = 0;
        cin >> temp;
        knowTruthQueue.push(temp);
    }

    for (int i = 0; i < partyNum; i++)
    {
        int number = 0;     // 해당 파티에 참석하는 사람의 수
        cin >> number;
        vector<int> temp;

        for (int j = 0; j < number; j++)
        {
            int k = 0;
            cin >> k;
            temp.push_back(k);
        }
        partyArray.push_back(temp);
    }

    while (knowTruthQueue.empty() == false)
    {
        // 진실을 아는 사람 한명씩 빼오기
        int knowPerson = knowTruthQueue.front();
        knowTruthQueue.pop();

        // 모든 파티 순회
        for (int i = 0; i < partyArray.size(); i++)
        {
            // 해당 파티에 진실을 아는 사람이 포함되어있으면,
            auto it = find(partyArray[i].begin(), partyArray[i].end(), knowPerson);
            if(it != partyArray[i].end())
            {
                // 진실을 아는 사람들 queue에 추가
                for (int k : partyArray[i])
                    knowTruthQueue.push(k);
                // 해당파티에서는 과장된이야기 못하니까 파티 삭제
                partyArray.erase(partyArray.begin()+i);
                i--;
            }
        }
    }

    cout << partyArray.size();
}