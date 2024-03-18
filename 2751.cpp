#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{

    ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

    int numLength = 0;  // 입력받을 숫자 총 개수
    int num = 0;        // 입력받을 숫자들

    cin >> numLength;
    vector<int> numV(numLength);

    for (int i = 0; i < numLength; i++)
    {
        cin >> numV[i];
    }

    sort(numV.begin(), numV.end());

    for (int i = 0; i < numLength; i++)
    {
        cout << numV[i] << '\n';
    }
}
