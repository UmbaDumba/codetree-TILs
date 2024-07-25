#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    string phonenum;
    cin >> phonenum;

    stringstream phone(phonenum);

    string first, middle, end;

    getline(phone, first, '-');
    getline(phone, middle, '-');
    getline(phone, end, '-');
    cout << first<<"-"<<end<<"-"<<middle<<endl;

    return 0;
}