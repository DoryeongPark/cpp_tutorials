#include <iostream>
#include <string>
#include <vector>

using namespace std;

/* tokenize
*  �Ű� ���� : str(���ڿ� ����) / tokens(���� ���ڿ��� ������ ���ڿ� ����) / delemeters (���� ����)
*  ���� : ���ڿ� ������ ���� ���ڷ� ���� ���ڿ��� ��Ʈ�� ���Ϳ� �����Ѵ�.
*/
void tokenize(const string& str, vector<string>& tokens, const string& delimiters = " ")
{
	int lastPos = str.find_first_not_of(delimiters, 0);
	//�����ڰ� �ƴ� ù ��° ������ �ε���
	int pos = str.find_first_of(delimiters, lastPos);
	//��ġ lastPos�� ���� �����ڸ� ã�� �������� �ε����� ��´�.

	while (string::npos != pos || string::npos != lastPos)
		//�� pos�� npos�� ��� ������ ��� ���� �ƴ� ���� ������ ����
	{
		tokens.push_back(str.substr(lastPos, pos - lastPos));
		//lastPos���� pos - lastPos ��ġ ������ ���ڿ��� ����� ���Ϳ� �����Ѵ�.
		lastPos = str.find_first_not_of(delimiters, pos);
		//lastPos�� pos�κ��� Ž���Ͽ� �����ڰ� �ƴ� ù ��° ������ ��ġ�� �����Ѵ�. 
		pos = str.find_first_of(delimiters, lastPos);
		//pos�� lastPos�κ��� Ž���Ͽ� �����ڰ� �˻��� ��ġ�� �����Ѵ�.
	}
}
/*
*	Date
*	������� : year - �⵵ / month - �� / day - ��
*	���� : ��¥�� �߻�ȭ�� Ŭ����
*/
class Date {
private:
	int year;
	int month;
	int day;
public:
	Date() = default;//����Ʈ ������
					 //�Ű������� 3���� ������ �޴� ������
	Date(const int& y, const int& m,
		const int& d) noexcept {
		year = y; month = m; day = d;
		//�Ű����� ��, ��, �� ����
	}
	//�Ű������� ���ڷ� �޴� ������
	Date(const string& input) noexcept {

		vector<string> tokens{};
		//�����ڷ� ������ ���ڿ����� ������ ����
		tokenize(input, tokens, "/");
		//input�� ���ڿ��� '/'�� ���� ���ڷ� ���ڿ��� ������ ���Ϳ� �����Ѵ�.
		year = stoi(tokens.at(0));//���� ù ��° ���ڿ� ����
		month = stoi(tokens.at(1));//���� �� ��° ���ڿ� ����
		day = stoi(tokens.at(2));//���� �� ��° ���ڿ� ����
	}
	~Date() = default;//����Ʈ �Ҹ���
	int getYear() { return year; }//���� �⵵ ��ȯ
	int getMonth() { return month; }//���� �� ��ȯ
	int getDay() { return day; }//���� �� ��ȯ
								//���� ��, ��, �Ͽ� ���� ������ ����Ѵ�.
	void show() { cout << year << "��" << month << "��" << day << "��" << endl; }
};
int main() {
	Date birth{ 2014, 3, 20 };//��, ��, ���� 2014, 3, 20�� ��¥ ����
	Date independenceDay{ "1945/8/15" };//��, ��, ���� 1945, 8, 15 ��¥ ����

	independenceDay.show();//indpendeceDay ��ü ���� ���
	cout << birth.getYear() << "," << birth.getMonth() << "," <<
		birth.getDay() << endl;
	//birth ��ü�� ���� ���� ���
}