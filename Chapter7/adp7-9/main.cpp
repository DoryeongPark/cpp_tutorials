#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <iomanip>
#include <ctime>

using namespace std;
using namespace chrono;

//class Seat
class Seat {
	string reservation_time;//Reservation time expressed by string
	string name; //Reservation name
	bool reserved; //true : reserved, false : not reserved
public:
	//Constructor : Initiates members
	Seat() {
		reservation_time = "";
		name = "---";//Default name
		reserved = false;
	}
	//Makes reservation with name
	bool make_reservation(const string& _name) {
		if (reserved) {//if it is reserved... 
			return false;
		}
		else {
			char c_str_now[26];//Temp variable to get reservation time
			auto now = system_clock::to_time_t(system_clock::now());//Gets current time
			ctime_s(c_str_now, 26, &now);//Gets current time as type char*
			reservation_time = string{ c_str_now };//Converts it into string
			name = _name;//Sets name
			reserved = true;//Sets true
			return true;
		}
	}
	//Cancel reservation - Sets members with default values
	void cancel_reservation() {
		reservation_time = "";
		name = "---";
		reserved = false;
	}
	//Reservation time getter
	auto get_reservation_time() {
		return reservation_time;
	}
	//Reserved flag getter
	auto is_reserved() {
		return reserved;
	}
	//Shows name
	auto show() {
		return name;
	}
};
//class Airplane - Manages 8 seats
class Airplane {
	string time; //Takeoff time
	vector<Seat> seat; //Seats
public:
	//Constructor : Initializes 8 seats
	Airplane() {
		seat.resize(8);
	}
	//Setter constructor : Initializes 8 seats and sets takeoff time
	Airplane(const string& _time) {
		seat.resize(8);
		time = _time;
	}
	//Takeoff time getter
	auto get_time() {
		return time;
	}
	//Prints current time
	void show_current_state() {
		
		cout.setf(ios::left);//Arrages text left
		cout << setw(5) << time << " : "; //Prints takeoff time
		
		for (auto& a : seat)//Prints Seats
			cout << setw(8) << a.show();

		cout << endl;
	}
	//Operator function : Gets seats from index
	Seat& operator[](const int& index) {
		return seat[index];
	}
};
//Reservation System - Manages airplanes
class ReservationSystem {
	vector<Airplane> airplanes;//Array of airplanes
public:
	//Constructor - Creates 3 airplanes and stores them
	ReservationSystem() {
		airplanes.emplace_back(Airplane{ "7시" });
		airplanes.emplace_back(Airplane{ "12시" });
		airplanes.emplace_back(Airplane{ "17시" });
	}
	//Excutes Reservation system
	void excute() {

		int menu;

		cout << "한성항공에 오신 것을 환영합니다." << endl << endl;

		while (true) {
			cout << endl << "예약 : 1, 취소 : 2, 보기 : 3, 끝내기 : 4 >> ";
			cin >> menu;//Input menu option
			
			switch (menu) {
			case 1:
				reservation();//Reservation
				break;
			case 2:
				cancel();//Cancel
				break;
			case 3:
				show();//Shows all seats
				break;
			case 4:
				quit();//Quit program
				break;
			default:
				cout << "올바른 입력 값을 입력하여 주십시오." << endl;
				break;
			}
		}
	}
private:
	//Makes reservation
	void reservation() {
		int airplane = get_airplane(); //Gets input for airplane(1 ~ 3)
		airplanes[airplane - 1].show_current_state();//Shows selected airplane's state
		int seat = get_seat(); string name = get_name();//Gets input seat number(1 ~ 8) and reservation name
		//Makes reservation on selected seat with name
		if (airplanes[airplane - 1][seat - 1].make_reservation(name)) {//If it is successed...
			cout << name << "님 좌석이 예약 되었습니다. " << endl; 
			cout << "예약 시각 : " << airplanes[airplane - 1][seat - 1].get_reservation_time();
		}
		else {//If it is failed
			cout << "이미 예약된 좌석입니다." << endl;
			cout << "예약된 시각 : " << airplanes[airplane - 1][seat - 1].get_reservation_time();
		}
	}
	//Cancels reservation
	void cancel() {
		int airplane = get_airplane(); //Gets input for airplane(1 ~ 3)
		airplanes[airplane - 1].show_current_state();//Shows selected airplane's state
		int seat = get_seat(); string name = get_name();//Gets input seat number(1 ~ 8) and reservation name
		airplanes[airplane - 1][seat - 1].cancel_reservation();//Cancel reservation on selected seat
	}
	//Shows each airplane's seat states
	void show() {
		for (auto& a : airplanes)
			a.show_current_state();
	}
	//Quits system
	void quit() {
		cout << "예약 시스템을 종료합니다." << endl;
		exit(1);
	}
	//Gets input airplane - Returns airplane number
	int get_airplane() {
		int input; 
		while (true) {
			cout << "7시 : 1, 12시 : 2, 17시 : 3 >> ";
			cin >> input; //Gets input

			if (input >= 1 && input <= 3)//If input is correct
				break;
			cout << "올바른 비행기 번호를 입력해 주십시오." << endl;
		}
		return input;
	}
	//Gets input seat - Returns seat number
	int get_seat() {
		int input;  
		while (true) {
			cout << "좌석 번호 >> ";
			cin >> input; //Gets input
			
			if (input >= 1 && input <= 8)//If input is correct
				break;

			cout << "올바른 좌석 번호를 입력해 주십시오. " << endl;
		}
		return input;
	}
	//Gets input reservation name - Returns reservation name
	string get_name() {
		string input;
		cout << "이름 입력 >> ";
		cin.ignore();
		getline(cin, input);
		return input;
	}
};

int main() {
	ReservationSystem hansung;//Creates reservation system
	hansung.excute();//Runs reservation system
}