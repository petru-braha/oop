/* 
clase derivate
protected: pentru obiecte derivate
exceptiile din c++ sunt diferite de cele din c

doua tipuri de exceptii:
1. try, throw => catch
- i'm aware when the alg can crash (which line)
2. windows c: __try (structural exceptions) => __except == handeler (apelat de kernel)
- i'm not aware of ..
- implementations depend of O.S.

exceptii vectorizate (priority queue

putem apela functii specifice unei clase fara sa folosim clasa? da, trebuie ptr la functie
*/

#include <iostream>

class Aa
{
	int x, y;
public:
	Aa(int x_var, int y_var);
	int computation();
	virtual ~Aa(); //let's us deconstruct the last line from this main
};

class Bb : public Aa
{
	int x, y;
public:
	Bb(int x_var, int y_var);
	int computation();
	~Bb();
};

Aa::Aa(int x_var, int y_var)
{
	printf("(");
	x = x_var;
	y = y_var;
}

Aa::~Aa()
{
	printf(")");
}

int Aa::computation()
{
	return x + y;
}

Bb::Bb(int x_var, int y_var) : Aa(x_var, y_var)
{
	printf("[");
	x = x_var;
	y = y_var;
}

Bb::~Bb()
{
	printf("]");
}

int Bb::computation()
{
	return x * y;
}

int derivations_main()
{
	Bb b(5, 5);
	Aa a = (Aa)b; //castare == elimina functiile B
	//sizeof(Bb)
	printf("%d ", a.computation());
	printf("%d ", b.computation());
	printf("%d ", b.Aa::computation());
	~Aa();
	~Bb();
	std::cout<<"\n\n";

	Aa* bbb = (Aa*)new Bb(5, 5);
	//lucreaza cu Aa dar aloca Bb
	printf(" %d ", bbb->computation());
	printf("%d ", ((Bb*)bbb)->computation());//bbb trebuie castat nu rezultatul

	//delete (Bb*)bbb; // nu e bun => destructor virtual
	delete bbb;
	//destructorul clasei A
	// B este mostenitor a lui A
	// ce e derivat din radacina este mai mare == A este inclus in B
	return 0;
}