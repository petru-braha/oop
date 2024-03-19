//demonstation of the homework
#include "ex 1\H2_NumberList.h"
void H2_numberList_main()
{
	NumberList A;
	A.Print();
	A.Init(); A.Print();

	A.Add(2); A.Print();

	A.Add(1); A.Add(5); A.Add(4); A.Add(3); A.Print();
	
	A.Sort(); A.Print();

	A.Add(9);
	A.Add(9);
	A.Add(9);
	A.Add(9);
	A.Add(9);
	std::cout<<A.Add(9)<<'\n'; //error
	A.Print();	
}

#include "ex 2\H2_studentFct.h"
void H2_student_main()
{
	student intern;
	intern.setName();
	intern.setENG(); 
	intern.setHST(); 
	intern.setMTH(); 
	std::cout << intern.getName() << "'s average: " << intern.average_grade() << "\n";
	
	//test for global functions
	student bachelor; bachelor.setName(); bachelor.setENG(); bachelor.setHST(); bachelor.setMTH();
	std::cout << "comparison: name, eng, hst, math, avg:\n";
	std::cout << compare_name(intern, bachelor) << compare_ENG(intern, bachelor) << compare_HST(intern, bachelor) << compare_MTH(intern, bachelor) << compare_AVG(intern, bachelor);

	//the test for uninitialised variables

}