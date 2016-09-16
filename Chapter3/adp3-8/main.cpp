#include <iostream>	
#include <string>
#include <memory>

using namespace std;

/*
*	Person
*	설명 : 사람을 추상화한 클래스(가족 구성원)
*/
class Person {
	string name;//이름
public:
	Person() noexcept : name("default_name") {};//기본 생성자 호출 시 디폴트 변수 대입
	//이름을 Set할 수 있는 생성자
	Person(const string& _name) noexcept : name(_name) {};
	string getName() { return name; }//이름의 Getter
	void setName(const string& _name) {//이름의 Setter
		name = _name;
	}
};

/*
*	Family
*	설명 : 가족을 추상화한 클래스
*/
class Family {
private:
	unique_ptr<Person> p = nullptr;//Person 객체 배열 포인터
	string name;//가족 이름
	int size;//가족 구성원 수
public:
	Family(const string& _name, const int& _size)noexcept : name(_name), size(_size) {
		p.reset(new Person[_size]);//입력한 사이즈만큼 배열 생성
	};

	~Family() { p.release(); }//메모리 수동 해제
	
	//매개변수로 받은 인덱스에 이름을 넣는다.
	void setName(const int& index, const string& name) {
		index[p.get()].setName(name);
	}

	void show(){//배열 내의 가족 구성원 정보 출력
		cout << name << " 가족은 다음과 같이 " << size << "명입니다." << endl;
		for (int i = 0; i < size; i++) {
			cout << p.get()[i].getName() << " ";
		}
	}
};

int main() {
	
	//사이즈 3의 Family 객체 배열 생성
	unique_ptr<Family> simpson{ new Family{ "Simpson", 3 } };
	
	//Family안의 구성원들의 이름을 차례로 Set
	simpson->setName(0, "Mr. Simpson");
	simpson->setName(1, "Mrs. Simpson");
	simpson->setName(2, "Bart, Simpson");
	
	simpson->show();//가족들의 정보를 보여준다.

	cout << endl;

	simpson.release();//스마트 포인터는 자동으로 지워지지만 메모리 해제를 구현하기 위해 수동으로 지움
}