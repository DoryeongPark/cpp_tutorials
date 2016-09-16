#include <iostream>
#include <string>	

using namespace std;

//Class Printer 
class Printer 
{
protected: //Members protected
	pair<string, string> printer_info; //Model name, Company
	int printed_count = 0;//number of Papers printed
	int available_count = 0;//number of Papers available
public:
	Printer() = default; //Default constructor

	//Setter constructor : Sets model name, company, pages
	Printer(const string& model, const string& manu, const int& pages) {
		printer_info.first = model; printer_info.second = manu;
		available_count = pages;
	}
	//Virtual constructor
	virtual ~Printer(){}
	//Exposes papers available
	auto& paper_storage() 
	{
		return available_count;
	}

	//Print as number of pages
	virtual bool print(const int pages) 
	{
		printed_count   += pages; 
		available_count -= pages;
		return true;
	}
	//Exposes papers available
	auto get_available_count() {
		return available_count;
	}
	//Abstract function : Checks if it is possible to print pages
	virtual bool check_state(const int pages) abstract;
	//Shows current printer state
	virtual void show_current_state() {
		cout << printer_info.first << ", " 
			<< printer_info.second << ", " 
			<< "���� ���� " << available_count << ", ";
	}
};
//InkjetPrinter inherits Printer class
class InkjetPrinter : public Printer{
	double available_ink; //number of inks available
public:
	//Constructor : Calls Printer's constructor and sets numbers of ink
	InkjetPrinter(const string& model, 
		          const string& manu, 
		          const int& pages, 
		          const double& ink) : 
		Printer(model, manu, pages)
	{
		available_ink = ink;
	}

	~InkjetPrinter() = default;//Default destructor
	//If it is possible to print pages prints papers or adds papers in printer
	virtual bool print(const int pages) override
	{
		if (check_state(pages)) {//If it is possible to print
			Printer::print(pages);//Prints pages
			available_ink -= (double)pages * 0.5; //Consumes ink 0.5 per paper
			cout << "����Ʈ �Ͽ����ϴ�." << endl;
			return true;
		}
		else {
			cout << "���� �Ǵ� ��ũ�� �����մϴ�." << endl;
			return false;//Fail to print
		}
	}
	//Shows current state of Inkjet printer
	virtual void show_current_state() override {
		cout << "��ũ�� : ";
		Printer::show_current_state();
		cout << "���� ��ũ " << available_ink << endl;
	}

private:
	//Checks if it is possible to print pages
	virtual bool check_state(const int pages) override
	{   //Checks current ink and papers
		if (available_ink - (double)pages * 0.5 < 0 || get_available_count() - pages < 0)
			return false;
		else
			true;
	}
};
//class LaserPrinter inherits Printer class
class LaserPrinter : public Printer{
	double toner;//number of toners
public:
	//Constructor : Calls Printer's constructor and sets number of tonerf
	LaserPrinter(const string& model, const string& manu, const int& pages, 
		const double& ton) : Printer(model, manu, pages) {
		toner = ton;
	}
	//Default destructor
	~LaserPrinter() = default;
	//Prints number of pages
	virtual bool print(const int pages) override 
	{	
		//Checks if it is possible to print
		if (check_state(pages)) {//If it is possible...
			Printer::print(pages);//Prints paper
			toner -= (double)pages * 0.5;//Decreases toner(Consumes 0.5 toner per paper)
			cout << "����Ʈ �Ͽ����ϴ�." << endl;
			return true;
		}
		else {
			cout << "���� �Ǵ� ��ʰ� �����մϴ�." << endl;
			return false;
		}
	}
	//Shows current Printer state
	virtual void show_current_state()
	{
		cout << "������ : ";
		Printer::show_current_state();
		cout << "���� ��� " << toner << endl;
	}
	
private:
	//Checks if it is possible to print
	virtual bool check_state(const int pages) override {
		//Checks current toner and papers
		if (toner - (double)pages * 0.5 < 0 || get_available_count() - pages < 0)
			return false;
		else
			return true;
	}
};
//Person who uses printer
class Person {
	string name;
public:
	Person() = default;//Default constructor
	//Setter constructor - Sets name
	Person(const string& _name) {
		name = _name;
	}
	//Puts paper into printer
	void put_paper(Printer& p, 
		           const int pages) {
		p.paper_storage() += pages;//Add papers
	}
	//Uses printer(Prints paper)
	void use_printer(Printer& p, 
					 const int pages) {
		//If printing isn't possible...
		if (!p.print(pages)) {
			int add;
			
			cout << "�����Ϳ� ������ �߰��մϴ�. >> ";
			cin >> add;//Input number of papers to add
			put_paper(p, abs(add));
		}
		p.show_current_state();//Shows current state of printer
	}
};

int main() {

	char reprint;//Asks whether continue printing or not
	int printer;//Determines which printer will be used
	int pages;//Number of pages

	Person p{ "�ڵ���" };//Creates one person gonna use printer

	Printer& inkjet = InkjetPrinter{ "Officejet V40", "HP", 5, 10 };//Creates Inkjet Printer
	Printer& laser = LaserPrinter{ "SCX-6x45", "�Ｚ����", 3, 20 };//Creates Laser Printer

	cout << "���� �۵����� 2���� �����ʹ� �Ʒ��� ����." << endl;
	
	inkjet.show_current_state();//Shows Inkjet Printer's state
	laser.show_current_state();//Shows Laser Printer's state
	
	for (;;) {
		
		cout << endl;

		cout << "������(1 : ��ũ��, 2 : ������)�� �ż� �Է� >>";
		cin >> printer >> pages; //Input No. of printer and number of papers
		
		if (printer == 1) {//No.1 printer : Inkjet Printer
			p.use_printer(inkjet, abs(pages));
		}
		else if(printer == 2) {//No. 2 printer : Laser Printer
			p.use_printer(laser, abs(pages));
		}
		else {
			cout << "Input Error" << endl;
			continue;//Restarts loop
		}

		cout << "��� ����Ʈ �Ͻðڽ��ϱ�?(y/n) >> ";
		cin >> reprint;//y or n
		
		if (tolower(reprint) == 'n')
			break;
	}
}