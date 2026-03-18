#include<iostream>
#include<string>
#include<ios>
#include<iomanip>
#include<vector>
#include<algorithm> //sort()

using namespace std;

int main(void) {
	int option = 0;
	string name = "", fname, lname;
	double att = 0.1,
		mid = 0.3,
		fin = 0.3,
		hw = 0.25,
		project = 0.05;

	while (option != 1 && option != 2) {
		cout << "select country: 1. korea 2.usa>>>";
		cin >> option;


		if (option == 1) {
			cout << "name:";
			cin >> name;
			cout << "hello," << name << "!" << endl;
		}
		else if (option == 2) {

			cout << "first name + last name : ";
			name = fname + " " + lname;
			cin >> name >> lname;
		}

		if (name != " ") {
			cout << "hello" << name << "!" << endl;

		}
	}
	//중간고사와 기말고사 점수를 묻고 입력받기 
	double midterm, final;

	cout << "midterm + final grades: ";
	cin >> midterm >> final; //45 65=> 45줄바꿈 65

	vector<double>homework;
	//과제 점수를 물음
	cout << "all hw grades + EOF:";//EOF : 컨트롤d 컨트롤 z
	//입력을 의한 변수

	double in; //임시변수(과제 읽을때만)
	//불변성 지금까지 count개 점수를 입력받았으며
	//압력받은 점수의합은 sum
	while (cin >> in) {
		homework.push_back(in);
	}

	//과제 점수의 입력 유무를 확인
	typedef vector<double>::size_type vec_sz;
	vec_sz size = homework.size();//배열크기
	if (size == 0) {
		cout << endl << "error enter your hw grades! try again"
			<< endl;
		return 1;

	}
	//점수를 정렬
	sort(homework.begin(), homework.end());

	//결과를 출력
	cout << "sorted grades:";
	for (int i = 0; i < homework.size(); i++) {
		cout << homework[i] << " ";

	}
	cout << endl;
	//과제 줨수의 중앙값을 구함
	vec_sz mid_pt = size / 2;
	double median;
	median = size % 2 == 0 ?
		(homework[mid_pt] + homework[mid_pt - 1]) / 2:
		homework[mid_pt]; //else 거짓
	//추가 중앙값과  평균비교
	double average, sum = 0;
	for (int i = 0; i < homework.size(); i++) {
		sum += homework[i];
	}
	average = sum / homework.size();
	//결과물 출력
	streamsize prec = cout.precision();
	//정밀도가 다시 리셋
	/*
	cout << name << "'s final grade:" << setprecision(3)
		<< 0.2 * midterm + 0.4 * final + 0.4 * median
		<<setprecision(prec) << endl;
	*/
	cout << name << "'s final grade:중앙값"
		<< (att * 100)
		+ (mid * midterm)
		+ (fin * final)
		+ (hw * median)//수정
		+ (project * 100)
		<< endl;

	cout << name << "'s final grade:평균"
		<< (att * 100)
		+ (mid * midterm)
		+ (fin * final)
		+ (hw * average)//수정
		+ (project * 100)
		<< endl;
	return 0;
}
//	
