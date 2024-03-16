#include <iostream>
#include <vector>
using namespace std;

void isPrime(int n)
{
   // n개 동적할당
   vector<bool> savePrime(1001);

   int countPrime = 0;  // 소수 개수

   savePrime[1] = true; // 1은 소수가 아니므로 true처리
  
   for (int i = 2; i*i < 1001; i++)
   {
      // 해당수가 소수라면, 출력하고 해당수를 제외한 배수들을 모두 제외
      if (savePrime[i] == false)
      {
         for (int j = i * 2; j <= 1001; j += i)
         {
            savePrime[j] = true;
         }
      }
   }

   // 값 읽으면서 소수 찾기
   for (int i = 0; i < n; i++)
   {
      int num = 0;
      cin >> num;
      if(savePrime[num] == false)
         countPrime++;
   }

   cout << countPrime;

}

int main()
 {
   int N = 0;
   
   cin >> N;

   isPrime(N);
   
 }