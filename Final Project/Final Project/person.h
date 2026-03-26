#ifndef PERSON_H_
#define PERSON_H_
#include <string>
using namespace std;
class Person
{
protected:
	string name;
public:

	virtual void set_name(string n);
	virtual string get_name();

};
#endif // !PERSON_H_



