#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 이미지의 'vec_sz'는 보통 vector의 크기를 나타내는 타입을 별칭으로 지정한 것입니다.
typedef vector<int>::size_type vec_sz;

int main(void) {
    // 프로그램 설명 하기
    cout << "Enter all values, then EOF: ";

    vector<int> val;
    int in;

    // 입력 받기 (Windows는 Ctrl+Z, Mac/Linux는 Ctrl+D로 입력 종료)
    while (cin >> in) {
        val.push_back(in);
    }

    // 오류 채킹
    vec_sz size = val.size();
    if (size == 0) {
        cout << "No values. Try again!" << endl;
        return 1; // 오류
    }

    // 정렬 (사분위수 계산을 위해 필수)
    sort(val.begin(), val.end());

    // 인덱스 계산
    vec_sz q1 = size / 4;      // 제1사분위수 (25%)
    vec_sz q2 = size / 2;      // 제2사분위수 (50%, 중앙값)
    vec_sz q3 = size / 4 * 3;  // 제3사분위수 (75%)

    int q1_val, q2_val, q3_val;

    // 짝수/홀수 여부에 따른 사분위값 계산 (삼항 연산자 사용)
    q1_val = size % 4 == 0 ? (val[q1] + val[q1 - 1]) / 2 : val[q1];
    q2_val = size % 2 == 0 ? (val[q2] + val[q2 - 1]) / 2 : val[q2];
    q3_val = 3 * size % 4 == 0 ? (val[q3] + val[q3 - 1]) / 2 : val[q3];

    // 결과 출력
    cout <<
        "Q1: " << q1_val << endl <<
        "Q2 (중앙값): " << q2_val << endl <<
        "Q3: " << q3_val << endl;

    return 0;
}