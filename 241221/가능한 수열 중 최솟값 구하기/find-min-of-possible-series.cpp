#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>

#define NUM_LEN 3

using namespace std;

int n;
vector<int> series;
int numbers[NUM_LEN] = {4, 5, 6};

// 시작과 끝 인덱스가 주어진 두 수열이 동일한지 여부를 판별합니다.
bool IsEqual(int start1, int end1, int start2, int end2) {
    for(int i = 0; i <= end1 - start1; i++) {
            if(series[start1 + i] != series[start2 + i])
                        return false;
                            }

                                return true;
                                }

                                // 가능한 수열인지 여부를 판별합니다.
                                bool IsPossibleSeries() {
                                    int len = 1;
                                        while(true) {
                                                // 연속 부분 수열의 시작과 끝 인덱스를 설정하여 줍니다.
                                                        int end1 = (int) series.size() - 1, start1 = end1 - len + 1;
                                                                int end2 = start1 - 1, start2 = end2 - len + 1;

                                                                        if(start2 < 0)
                                                                                    break;

                                                                                            // 인접한 연속 부분 수열이 같은지 여부를 확인합니다.
                                                                                                    if(IsEqual(start1, end1, start2, end2))
                                                                                                                return false;

                                                                                                                        len++;
                                                                                                                            }

                                                                                                                                return true;
                                                                                                                                }

                                                                                                                                void FindMinSeries(int cnt) {
                                                                                                                                    // n개의 숫자가 선택됐을 때 불가능한 수열인 경우 탐색을 종료합니다.
                                                                                                                                        // 가능한 수열인 경우 이를 출력하고 프로그램을 종료합니다.
                                                                                                                                            if(cnt == n) {
                                                                                                                                                    for(int i = 0; i < series.size(); i++)
                                                                                                                                                                cout << series[i];
                                                                                                                                                                        exit(0);
                                                                                                                                                                            }

                                                                                                                                                                                // 사용 가능한 각 숫자가 뽑혔을 때의 경우를 탐색합니다.
                                                                                                                                                                                    for(int i = 0; i < NUM_LEN; i++) {
                                                                                                                                                                                            series.push_back(numbers[i]);
                                                                                                                                                                                                    // 해당 시점까지 만들 수열이 조건을 만족하는 경우에만
                                                                                                                                                                                                            // 탐색을 진행합니다.
                                                                                                                                                                                                                    if(IsPossibleSeries())
                                                                                                                                                                                                                                FindMinSeries(cnt + 1);
                                                                                                                                                                                                                                        
                                                                                                                                                                                                                                                series.pop_back();
                                                                                                                                                                                                                                                    }
                                                                                                                                                                                                                                                    }

                                                                                                                                                                                                                                                    int main() {
                                                                                                                                                                                                                                                        cin >> n;

                                                                                                                                                                                                                                                            FindMinSeries(0);
                                                                                                                                                                                                                                                                return 0;
                                                                                                                                                                                                                                                                }