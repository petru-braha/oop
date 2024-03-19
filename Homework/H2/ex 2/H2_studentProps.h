#define mathematics 0 
#define english 1
#define history 2
#include <cstring>
class student
{
private:
	char name[100]; //set + get
	float marks[3];
public:
	void setName();
	char* getName();

	void setMTH();
	float getMTH();

	void setENG();
	float getENG();

	void setHST();
	float getHST();

	float average_grade();
};

/*
a cpp file for the global functions implementation
a main.cpp file that shows how the methods and global functions can be used.
*/