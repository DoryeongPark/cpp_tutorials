#include <iostream>
#include <string>	
#include <vector>
#include <algorithm>
#include <stack>

const double M_PI = 3.141592; //������ ��� ����

using namespace std;

/*
*	Circle
*	���� : ���� �߻�ȭ�� Ŭ����
*/
class Circle {
	double radius;//������
	double area;//�� ����
	string name;//�� �̸�
	int num;//�� ��ȣ

protected:
	static int circle_num;//�Ҵ��� �� ��ȣ
public:
	//�⺻ ������
	Circle() {
		num = ++circle_num;//�� ��ȣ�� �Ҵ��Ѵ�.

		for (;;) {//�Է��� ������ �Է����˰� ������ ������ ���ѷ���
			
			cout << "�� " << num << " �� �̸��� ������ >> ";

			string input;//�Է� ���ڿ�

			getline(cin, input, '\n');//���� �Է�

			name = input.substr(0, input.find(' ', 0));//ù ��° ���ڿ� �����Ͽ� �̸��� ����
			auto s_radius = input.substr(input.find(' ', 0) + 1, 
				(input.find(' ', input.find(' ', 0) + 1)) - 
				(input.find(' ', 0) + 1));//�� ��° ���ڿ� ����

			//������ �� ��° ���ڿ��� ��ȯ ������ ������ ���
			if (all_of(s_radius.begin(), s_radius.end(), [&](char c)->bool{
				if (isdigit(c) || c == '.')
					return true;
				else
					return false;
			})) {
				radius = stod(s_radius);//��ȯ�Ͽ� ��������� ����
				area = radius * radius * M_PI;//���� ���̸� ����Ͽ� ��������� ����
				break;
			}//���� ������ �� ��° ���ڿ��� ���ڿ� .�� ������ �̿��� ���ڸ� ���� ���
			else {
				cout << "���ڸ� �Է��� �ּ���." << endl;
			}
		}
	}
	//�� ������ Getter
	double getArea() noexcept {
		return area;
	}
	//�� �̸��� Getter
	string getName() noexcept {
		return name;
	}
};

int Circle::circle_num = 0; //Ŭ���� ���� �ʱ�ȭ

/*
*	CircleManager
*	���� : ������ �����ϴ� Ŭ����
*/
class CircleManager {
private:
	vector<Circle*> circle_arr;//������ �����͸� ������ ����
public:
	//�Է��� �����ŭ ���Ϳ� �̸� �Ҵ�
	CircleManager(const int& size) {
		circle_arr.reserve(size);
	}
	//�Ű������� ��ġ�ϴ� �̸��� ���� ������ ����Ѵ�.
	void searchByName(const string& name) noexcept {
		for (auto c : circle_arr) {//�ݺ���
			if (c->getName() == name)//���� �Ű������� �ش� ���� �̸��� ��ġ�� ���
				cout << c->getName() << "�� ������ " << c->getArea() << endl;//�ش� ���� ���� ���
		}
	}
	//�Ű��������� ū ���� ������ ����Ѵ�.
	void searchByArea(const double& limit_lower) noexcept{

		cout << limit_lower << "���� ū ���� �˻��մϴ�." << endl;
		for_each(circle_arr.begin(), circle_arr.end(), [&](Circle* c) {//�ݺ���
			if (c->getArea() > limit_lower)//���� ������ �Ű��������� Ŭ ���
				cout << c->getName() << "�� ������ " << c->getArea() << endl;//�ش� ���� ���� ���
		});
	}
	//�Ű����� ���� ���Ϳ� �����Ѵ�.
	void storeCircle(Circle* c) {
		circle_arr.push_back(c);
	}
	//���͸� �����Ѵ�.
	vector<Circle*> getVec() noexcept {
		return circle_arr;
	}
};

int main() {

	int num_of_circles;//���� ����

	cout << "���� ���� >> ";

	//���� ���� �Է�, ���ڸ� �Է����� �ʾ��� ���
	while (!(cin >> num_of_circles)) {
		cin.clear();//���۸� ����.

		while (cin.get() != '\n')//���� ���ڸ� �����.
			continue;

		cout << "���ڸ� �Է��ϼ���." << endl;//���� ���
		cout << "���� ���� >> ";
	}

	cin.ignore();//���� �Է¿� ������ ���� �ʵ��� ����
	//�Է��� ������ŭ ������ CircleManager ��ü ����
	CircleManager cm{ num_of_circles };
	
	//�Է��� ������ŭ ���� �����Ѵ�. ������ ���ÿ� �Ŵ����� �����Ѵ�.
	for (int i = 0; i < num_of_circles; ++i) 
		cm.storeCircle(new Circle{});
	
	string name_search;//���� �̸�

	cout << "�˻��ϰ��� �ϴ� ���� �̸� >> ";
	//���� �̸� �Է�
	getline(cin, name_search, '\n');
	//�Է��� ���� �̸��� ��ġ�ϴ� �� ���� ���
	cm.searchByName(name_search);

	double area_search;

	cout << "�ּ� ������ ���� �Է��ϼ��� >> ";
	//���� �ּ� ���� �Է�, ���ڸ� �Է����� �ʾ��� ���
	while (!(cin >> area_search)) {
		cin.clear();//���۸� ����.

		while (cin.get() != '\n')//���๮�ڸ� �����.
			continue;

		cout << "������ �Է��ϼ���." << endl;//���� ���
		cout << "�ּ� ������ ������ �Է��ϼ��� >> " << endl;
	}
	//�Է��� �ּ� �������� ū ������ ������ ����Ѵ�.
	cm.searchByArea(area_search);

	//������ ���� �޸� ��� ����
	for (auto c : cm.getVec()) 
		delete c;
	
}