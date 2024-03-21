#include <iostream>
#include <set>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N = 0;  // 입력 받을 좌표의 총 개수
    multiset<pair<int, int>> pairs;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int X = 0;
        int Y = 0;

        cin >> X >> Y;
        pairs.insert(make_pair(X, Y));
    }

    for(auto p : pairs)
    {
        cout << p.first << ' ' << p.second << '\n';
    }
    return 0;
}