#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;
//Components consisted of debugging informations 
struct debug_component {
	static int content_size;//charactor size of Debugging informations
	static vector<pair<string, string>> logs;//Storage for debug informations(tag, information) 
};
//Initializes debug components
int debug_component::content_size = 0;
vector<pair<string, string>> debug_component::logs = vector<pair<string, string>>();

//Function 1 : Puts debug informations into storage
auto f1 = [](const string& tag, const string& info) {
	if (debug_component::content_size + info.size() > 100) {//If added size is bigger than 100 characters
		cout << "����� ������ 100���� �Ѿ����Ƿ� �� �̻� �������� �ʽ��ϴ�." << endl;
		return;//Informs it can't store it and exits
	}
	//Stores debug information(tag, information)
	debug_component::logs.push_back(pair<string, string>(tag, info));
	debug_component::content_size += info.size();//Adds charactor size 
};

//Function 2 : Prints debug information(default tag = "")
auto f2 = [](const string& tag = "") {

	if (tag != "") //If no argument exists
		cout << "----" + tag + "�±��� Trace ������ ����մϴ�.----" << endl;
	else //If there was argument
		cout << "---- ��� Trace ������ ����մϴ�.----" << endl;
	
	for_each(debug_component::logs.begin(), debug_component::logs.end(), [&](pair<string, string> a) {
		if (a.first == tag || tag == "")//tag == "" : Prints all components, tag is determined : Prints only tag's information
			cout << a.first << " : " << a.second << endl;
	});
};

class Trace {
public://static member functions
	static decltype(f1) put;
	static decltype(f2) print;
};
//Initializes static member functions
decltype(f1) Trace::put = f1;
decltype(f2) Trace::print = f2;

void f() {
	int a, b, c;

	cout << "�� ���� ������ �Է��ϼ���>>";
	cin >> a >> b;
	Trace::put("f()", "������ �Է¹޾���");//Stores information
	c = a + b;
	Trace::put("f()", "�� ���");//Stores information
	cout << "���� " << c << endl;
}
int main() {
	Trace::put("main()", "���α׷� �����մϴ�.");//Stores information
	f();
	Trace::put("main()", "����");//Stores information

	Trace::print("f()");//Prints only information of "f()"
	
	cout << endl;

	Trace::print();//Prints all of information

}