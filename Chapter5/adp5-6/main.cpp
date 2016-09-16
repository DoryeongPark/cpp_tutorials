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
*  �Ű� ���� : str(���ڿ� ����) / tokens(���� ���ڿ��� ������ ������ ����) / delemeters (���� ����)
*  ���� : ���ڿ� ������ ���� ���ڷ� ���� ���ڿ��� ������ ��ȯ�Ͽ� ���Ϳ� �����Ѵ�.
*/
void tokenize(const string& str, vector<int>& tokens, const string& delimiters = " ")
{
	int lastPos = str.find_first_not_of(delimiters, 0);
	//�����ڰ� �ƴ� ù ��° ������ �ε���
	int pos = str.find_first_of(delimiters, lastPos);
	//��ġ lastPos�� ���� �����ڸ� ã�� �������� �ε����� ��´�.

	string token;//�� ��ū

	while (string::npos != pos || string::npos != lastPos)
		//�� pos�� npos�� ��� ������ ��� ���� �ƴ� ���� ������ ����
	{
		token = str.substr(lastPos, pos - lastPos);
		//lastPos���� pos - lastPos ��ġ ������ ���ڿ��� �����.
		tokens.push_back(stoi(token));
		//���������� ��ȯ�Ͽ� ���Ϳ� �����Ѵ�.
		lastPos = str.find_first_not_of(delimiters, pos);
		//lastPos�� pos�κ��� Ž���Ͽ� �����ڰ� �ƴ� ù ��° ������ ��ġ�� �����Ѵ�. 
		pos = str.find_first_of(delimiters, lastPos);
		//pos�� lastPos�κ��� Ž���Ͽ� �����ڰ� �˻��� ��ġ�� �����Ѵ�.
	}
}

int main() {

	string input1;//Input for vector x
	string input2;//Input for vector y

	vector<int> x;//vector x
	vector<int> y;//vector y

	//Exception handling for Input
	try {
		cout << "���� 5���� �Է��϶� �迭 x�� �����Ѵ�. >> ";
		getline(cin, input1, '\n');
		tokenize(input1, x);//Tokenizes each numbers from Input and stores them in x
		
		cout << "���� 2���� �Է��϶� �迭 y�� �����Ѵ�. >> ";
		getline(cin, input2, '\n');
		tokenize(input2, y);//Tokenizes each numbers from Input and stores them in y
	}
	catch(exception e){//Prints error
		cout << "Error : " << e.what() << endl;
	}

	cout << "��ģ �迭�� ����Ѵ�." << endl;
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
	cout << "�迭 x���� y�� �A ����� ����Ѵ�. ������ " << rst2.size() << endl;
	for_each(rst2.cbegin(), rst2.cend(), [&](int a) {
		cout << a << " ";
	});

	cout << endl;
}