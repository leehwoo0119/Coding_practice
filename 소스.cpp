#include <iostream>
#include <cstring>
#include <cstdlib>
#include <iomanip>

#pragma warning(disable : 4996)

using namespace std;

class info
{
private:
	int id = 0;
	char name[256] = { 0, };
public:
	void IDSetter(int value);
	int IDGetter() { return id; };

	void NameSetter(char* value);
	char* NameGetter() { return name; };
	
	info() {id = 1234; strcpy(name, "이름없음");}
	~info() { cout << "소멸자 호출"; };
};

void info::IDSetter(int value)
{
	id = value;
}
void info::NameSetter(char* value)
{
	strcpy(name, value);
}
int main()
{
	info userinfo;
	cout << userinfo.IDGetter() << endl;
	cout << userinfo.NameGetter() << endl;
	int idTemp = 0;
	char nameTemp[256] = { 0, };
	cin >> idTemp;
	cin >> nameTemp;
	userinfo.IDSetter(idTemp);
	userinfo.NameSetter(nameTemp);

	cout << userinfo.IDGetter() << endl;
	cout << userinfo.NameGetter() << endl;
	return 0;
}