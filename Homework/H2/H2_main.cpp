#include "H2_NumberList.h"
void H2_main()
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