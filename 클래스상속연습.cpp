#include <iostream>
//#include <combaseapi.h>
#pragma warning(disable : 4996)
using namespace std;


class _Student
{
protected:
	int ID;
public:
	virtual void SetID(int value) = 0;
	virtual int GetID() = 0;
};

class Sujin:public _Student
{
public:
	void Print()
	{
		cout << ID;
	}

	virtual void SetID(int value) { ID = value; };
	virtual int GetID() { return ID; };
};
int main()
{
	
	Sujin* ps = new Sujin;

	int ID = 0;
	cin >> ID;
	ps->SetID(ID);
	ps->Print();
	delete ps;
	return 0;
}
