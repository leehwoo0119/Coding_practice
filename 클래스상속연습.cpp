#include <iostream>
#pragma warning(disable : 4996)
using namespace std;

class Info
{
protected:
	char name[256];
	int score;
public:
	char* getName() { return name; }
	int getScore() { return score; }
};
class c_Class : public Info
{
public:
	void setName() { strcpy(getName(), "Ã¶¼ö"); };
	void setScore(int value) { score = value; };
};
class y_Class : public Info
{
public:
	void setName() { strcpy(getName(), "¿µÈñ"); };
	void setScore(int value) { score = value; };
};
int main()
{
	c_Class* p_c = new c_Class;
	y_Class* p_y = new y_Class;
	p_c->setName();
	p_y->setName();
	int score_c = 0; int score_y = 0;
	cin >> score_c;
	p_c->setScore(score_c);
	cin >> score_y;
	p_y->setScore(score_y);

	cout << p_c->getName()<<endl;
	cout << p_c->getScore() << endl;
	cout << p_y->getName() << endl;
	cout << p_y->getScore() << endl;
	return 0;
}
