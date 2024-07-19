#include <iostream>
using namespace std;

bool is_yoon(int year){
    if(year % 400 == 0){
        return true;
    }else if(year % 100 == 0){
        return false;
    }else if(year % 4 == 0){
        return true;
    }
    return false;
}

int main() {
    // 여기에 코드를 작성해주세요.
    int y, m, d;
    cin >> y;
    cin >> m;
    cin >> d;

    int daysyoon[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int daysnotyoon[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int *days;
    if(is_yoon(y)){
        days = daysyoon;
    }else{
        days = daysnotyoon;
    }
    if(days[m-1] < d){
        cout << "-1"<<endl;
        return 0;
    }

    if(m >= 3 && m <= 5){
        cout << "Spring"<<endl;
    }else if(m >= 6 && m <= 8){
        cout << "Summer"<<endl;
    }else if(m >= 9 && m <= 11){
        cout << "Fall"<<endl;
    }else if(m >= 12 || m <= 2){
        cout << "Winter"<<endl;
    }

    return 0;
}