#include <iostream>	
#include <string>
#include <memory>

using namespace std;

/*
*	Person
*	���� : ����� �߻�ȭ�� Ŭ����(���� ������)
*/
class Person {
	string name;//�̸�
public:
	Person() noexcept : name("default_name") {};//�⺻ ������ ȣ�� �� ����Ʈ ���� ����
	//�̸��� Set�� �� �ִ� ������
	Person(const string& _name) noexcept : name(_name) {};
	string getName() { return name; }//�̸��� Getter
	void setName(const string& _name) {//�̸��� Setter
		name = _name;
	}
};

/*
*	Family
*	���� : ������ �߻�ȭ�� Ŭ����
*/
class Family {
private:
	unique_ptr<Person> p = nullptr;//Person ��ü �迭 ������
	string name;//���� �̸�
	int size;//���� ������ ��
public:
	Family(const string& _name, const int& _size)noexcept : name(_name), size(_size) {
		p.reset(new Person[_size]);//�Է��� �����ŭ �迭 ����
	};

	~Family() { p.release(); }//�޸� ���� ����
	
	//�Ű������� ���� �ε����� �̸��� �ִ´�.
	void setName(const int& index, const string& name) {
		index[p.get()].setName(name);
	}

	void show(){//�迭 ���� ���� ������ ���� ���
		cout << name << " ������ ������ ���� " << size << "���Դϴ�." << endl;
		for (int i = 0; i < size; i++) {
			cout << p.get()[i].getName() << " ";
		}
	}
};

int main() {
	
	//������ 3�� Family ��ü �迭 ����
	unique_ptr<Family> simpson{ new Family{ "Simpson", 3 } };
	
	//Family���� ���������� �̸��� ���ʷ� Set
	simpson->setName(0, "Mr. Simpson");
	simpson->setName(1, "Mrs. Simpson");
	simpson->setName(2, "Bart, Simpson");
	
	simpson->show();//�������� ������ �����ش�.

	cout << endl;

	simpson.release();//����Ʈ �����ʹ� �ڵ����� ���������� �޸� ������ �����ϱ� ���� �������� ����
}