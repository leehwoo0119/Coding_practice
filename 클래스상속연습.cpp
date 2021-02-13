#include <iostream>
#pragma warning(disable : 4996)
using namespace std;


class CarInfo
{
private:
	char color[256]="red";
	int num = 11;

public:
	void setcolor(char* value) { strcpy(color, value); }
	void setnum(int value) { value = num; }

	char* getcolor() { return color; };
	int getnum() { return num; };

	void print() {};

};

class C_Car :public CarInfo
{
private:
	int ID = 1223;
	char name[256]="eea";

public:
	void setname(char* value) { strcpy(name, value); }
	void setid(int value) { value = ID; }

	char* getname() { return name; };
	int getid() { return ID; };

	void print() {
		cout << getname() << getid() << getcolor() << getnum();
	};
};
int main()
{
	C_Car* p_c_car = nullptr;

	if (p_c_car == nullptr)
		p_c_car = new C_Car;

	p_c_car->print();

	delete p_c_car;
	return 0;
}
