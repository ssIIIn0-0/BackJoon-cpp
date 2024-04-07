#include <iostream>
using namespace std;

long long A = 0;  // 곱할 자연수
long long B = 0;  // 곱해질 횟수
long long C = 0;  // 나눌 자연수

long long answer = 0;   // 정답 (A^B%C)


long long power (long long b)
{
    // 0번 곱할 경우 A, C값과 상관없이 1이다.
    if (b == 0)
        return 1;
    // B가 1이면 그냥 A%C 해서 나머지를 구하면 된다.
    if (b == 1)
        return A % C;
    
    long long k = power(b / 2) % C;

    // 지수가 짝수면
    if (b % 2 == 0)
        return k * k % C;
    // 지수가 홀수면
    else 
        return k * k % C * A % C;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> A >> B >> C;

    answer = power(B);

    cout << answer;
    return 0;
}