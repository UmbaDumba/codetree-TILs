#include <iostream>
#include <algorithm>

#define MAX_N 100
#define MAX_M 10000

using namespace std;

// 변수 선언
int n, m;
int weight[MAX_N];
int value[MAX_N];

int dp[MAX_M + 1]; // dp[i] : 지금까지 고른 보석 무게의 합이 i일 때
                   //         얻을 수 있는 최대 가치

                   int main() {
                       // 입력:
                           cin >> n >> m;
                               for(int i = 0; i < n; i++)
                                       cin >> weight[i] >> value[i];
                                           
                                               // 초기 조건은
                                                   // 아직 아무런 보석도 고르지 않은 경우인
                                                       // 합이 0이며, 얻을 수 있는 가치가 0이라는 정보입니다.
                                                           dp[0] = 0;

                                                               // 점화식에 따라 값을 채워줍니다.
                                                                   for(int i = 1; i <= m; i++) {
                                                                           // 보석 무게의 합 i를 만들기 위해
                                                                                   // 마지막으로 길이가 j번 보석을 고른 경우에 대해 조사합니다.
                                                                                           // 그 중 얻을 수 있는 최대 가치를 계산합니다.
                                                                                                   for(int j = 0; j < n; j++) {
                                                                                                               // i가 j번 보석의 무게인 weight[j]보다는 같거나 커야만
                                                                                                                           // 가능한 경우입니다.
                                                                                                                                       if(i >= weight[j])
                                                                                                                                                       dp[i] = max(dp[i], dp[i - weight[j]] + value[j]);
                                                                                                                                                               }
                                                                                                                                                                   }

                                                                                                                                                                       // 무게의 합이 m을 넘지만 않으면 되기에
                                                                                                                                                                           // 0부터 m까지 무게를 전부 보며
                                                                                                                                                                               // 그 중 얻을 수 있는 최대 가치를 구해줍니다.
                                                                                                                                                                                   int ans = 0;
                                                                                                                                                                                       for(int i = 0; i <= m; i++)
                                                                                                                                                                                               ans = max(ans, dp[i]);

                                                                                                                                                                                                   cout << ans;
                                                                                                                                                                                                       return 0;
                                                                                                                                                                                                       }