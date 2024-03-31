#include <iostream>
#include<algorithm>
#include <cmath>
using namespace std;

int N = 0;                 // 이동하려는 채널
int M = 0;                 // 고장난 버튼의 개수
bool buttons[10]; // 리모컨 버튼

bool canMake(int num)
{
    if (num == 0)
    {
        if (buttons[0])
            return true;
        return false;
    }
    while (num)
    {
        if (!buttons[num % 10])
            return false;
        num /= 10;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    // bool buttons[10] = {true}; 로 선언할 시 오답처리가 됨;
    fill(buttons, buttons + 10, true);
    cin >> N >> M;

    // 고장난 버튼 파악하기
    for(int i = 0; i < M; i++)
    {
        int num = 0;
        cin >> num;
        buttons[num] = false;
    }

    // +, -만 사용한 횟수
    int answer = abs(N - 100);

    // 숫자 버튼 & +, - 버튼 모두 사용한 횟수
    // 백만개의 채널을 대상으로 가능한지 안한지 파악
    for(int i = 0; i <= 1000000; i++)
    {   
        // 고장난 버튼이 없다면,
        if(canMake(i))
        {
            int move = to_string(i).length();
            move += abs(i - N);
            answer = min(answer, move);
        }
    }

    cout << answer;
}