#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <iterator>
#include <vector>	

using namespace std;
//Return vector added by 2 Vectors
auto f1 = [](const vector<int>& a, const vector<int>& b)->vector<int>{
	vector<int> ab;
	ab.insert(ab.end(), a.begin(), a.end());//Inserts components of vector a
	ab.insert(ab.end(), b.begin(), b.end());//Inserts components of vector b
	return ab;//Returns result vector
};
//Return vector components of result of vector a - vector b
auto f2 = [](vector<int> a, vector<int> b)->vector<int>{
	vector<int> rst;
	sort(a.begin(), a.end());//Sorts a's components(Ascending order)
	sort(b.begin(), b.end());//Sorts b's components(Ascending order)
	set_difference(a.begin(), a.end(), b.begin(), b.end(), back_inserter(rst));//Gets difference of a and b
	sort(rst.begin(), rst.end(), greater<int>());//Sorts results with Descending order

	if (rst.size() == 0)//If all components were substrated
		return static_cast<vector<int>>(NULL);//

	return rst;//return result vector
};

class ArrayUtility {
public://static member functions
	static decltype(f1) concat;
	static decltype(f2) remove;
};
//Initializes static member functions
decltype(f1) ArrayUtility::concat = f1;
decltype(f2) ArrayUtility::remove = f2;

/*
*  tokenize
*  매개 변수 : str(문자열 원본) / tokens(나눈 문자열을 저장할 정수형 벡터) / delemeters (구분 문자)
*  설명 : 문자열 원본을 구분 문자로 나눈 문자열을 정수로 변환하여 벡터에 저장한다.
*/
void tokenize(const string& str, vector<int>& tokens, const string& delimiters = " ")
{
	int lastPos = str.find_first_not_of(delimiters, 0);
	//구분자가 아닌 첫 번째 문자의 인덱스
	int pos = str.find_first_of(delimiters, lastPos);
	//위치 lastPos로 부터 구분자를 찾고 구분자의 인덱스를 얻는다.

	string token;//한 토큰

	while (string::npos != pos || string::npos != lastPos)
		//값 pos와 npos가 모두 범위를 벗어난 값이 아닐 동안 루프문 실행
	{
		token = str.substr(lastPos, pos - lastPos);
		//lastPos부터 pos - lastPos 위치 까지의 문자열을 때어낸다.
		tokens.push_back(stoi(token));
		//정수형으로 변환하여 벡터에 저장한다.
		lastPos = str.find_first_not_of(delimiters, pos);
		//lastPos에 pos로부터 탐색하여 구분자가 아닌 첫 번째 문자의 위치를 대입한다. 
		pos = str.find_first_of(delimiters, lastPos);
		//pos에 lastPos로부터 탐색하여 구분자가 검색된 위치를 대입한다.
	}
}

int main() {

	string input1;//Input for vector x
	string input2;//Input for vector y

	vector<int> x;//vector x
	vector<int> y;//vector y

	//Exception handling for Input
	try {
		cout << "정수 5개를 입력하라 배열 x에 삽입한다. >> ";
		getline(cin, input1, '\n');
		tokenize(input1, x);//Tokenizes each numbers from Input and stores them in x
		
		cout << "정수 2개를 입력하라 배열 y에 삽입한다. >> ";
		getline(cin, input2, '\n');
		tokenize(input2, y);//Tokenizes each numbers from Input and stores them in y
	}
	catch(exception e){//Prints error
		cout << "Error : " << e.what() << endl;
	}

	cout << "합친 배열을 출력한다." << endl;
	//Concatenates x and y
	vector<int> rst1 = ArrayUtility::concat(x, y);
	//Prints result
	for_each(rst1.cbegin(), rst1.cend(), [&](int a) {
		cout << a << " ";
	});

	cout << endl;
	//Gets differances between x and y
	vector<int> rst2 = ArrayUtility::remove(x, y);
	//Prints result
	cout << "배열 x에서 y를 뺸 결과를 출력한다. 개수는 " << rst2.size() << endl;
	for_each(rst2.cbegin(), rst2.cend(), [&](int a) {
		cout << a << " ";
	});

	cout << endl;
}