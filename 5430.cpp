#include <iostream>
#include <cstring>
using namespace std;

char p[100001];                 // RDRDDR 같은 함수들의 문자열
int lst[100000], lstSize;       // 숫자가 들어있는 배열

void solve(void)
{
	bool reverse = false; 
	int lstHead = 0, lstTail = 0, total, printCnt = 0;

	for (int i = 0; i < strlen(p); i++)
    {
		if (p[i] == 'D')
        {
			if (reverse)
                lstTail++;
			else
                lstHead++;
		}
		else
        {
			if (reverse)
                reverse = false;
			else
                reverse = true;
		}
	}

	total = lstSize - (lstHead + lstTail);
	if (total < 0)
	{
		cout << "error\n";
		return;
	}

	cout << '[';
	if (reverse)	//	뒤집어진 경우
    {
		for (int i = lstSize - lstTail - 1; i >= lstHead; i--)
        {
			cout << lst[i]; printCnt++;
			if (printCnt != total)
                cout << ',';
		}
	}

	else		//정상인경우
    {
		for (int i = lstHead; i < lstSize - lstTail; i++)
        {
			cout << lst[i]; printCnt++;
			if (printCnt != total) cout << ',';
		}
	}
	cout << "]\n";
}

int main(void)
{
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t = 0;      // 테스트게이스 개수
    int n = 0;      // 배열에 들어있는 수의 개수
	char temp;

	cin >> t;
	for (int k = 0; k < t; k++)
    {
		lstSize = 0;
		cin >> p >> n;

        for (int i = 0; i < n; i++)
        {
            cin >> temp >> lst[i];
			lstSize++;
        }
		cin >> temp;
		if (n == 0)
			cin >> temp;
		solve();
	}
	return 0;
}