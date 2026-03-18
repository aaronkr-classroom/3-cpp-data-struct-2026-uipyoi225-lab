#include<iostream>
#include<string>
#include<ios>
#include<iomanip>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::setprecision;
using std::streamsize;

int main(void) {
	int option = 0;
	string name="", fname, lname;
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

	   if (name !=" "){
		   cout << "hello" << name << "!" << endl;

	   }
	}
	//중간고사와 기말고사 점수를 묻고 입력받기 
	double midterm, final, sum = 0;
	int count = 0;  //과제 몇개?
	
	cout << "midterm + final grades: ";
	cin >> midterm >> final; //45 65=> 45줄바꿈 65
	//과제 점수를 물음
	cout << "all hw grades + EOF:";//EOF : 컨트롤d 컨트롤 z
	//입력을 의한 변수
	double in; //임시변수(과제 읽을때만)
	//불변성 지금까지 count개 점수를 입력받았으며
	//압력받은 점수의합은 sum
	while (cin >> in) {
		++count;
		sum += in;
	}
	//결과를 출력
	streamsize prec = cout.precision();
	//정밀도가 다시 리셋
	/*
	cout << name << "'s final grade:" << setprecision(3)
		<< 0.2 * midterm + 0.4 * final + 0.4 * (sum/count)
		<<setprecision(prec) << endl;
	*/
	cout << name << "'s final grade:"
		<< (att * 100)
		+ (mid * midterm)
		+ (fin * final)
		+ (hw * (sum / count))
		+ (project * 100)
	    << endl;

	return 0;
}
