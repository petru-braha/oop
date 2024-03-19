#include <iostream>
#pragma warning(disable:4996)
//don NOT use global variables (it is C) use singletons instead (C++)!!!!

class lab3_class//sigleton: global data structure ex: system files
{
    int x, y;
    lab3_class(int x, int y) : x(x), y(y) { std::cout << "("; }//exclusive constructor
    static lab3_class* inst;
public:
    int computation()
    {
        return x + y;
    }
    static lab3_class* create(int x, int y);
    static void deconstruct();
    ~lab3_class() { std::cout << ")"; }
};
lab3_class* lab3_class::inst = 0; //can't be initialised in the class, it has to be somewhere s.t. it can create
lab3_class* lab3_class::create(int x = 0, int y = 0)
{
    if (inst == 0)
        inst = new lab3_class(x, y);
    return inst;
}

void lab3_class::deconstruct()
{
    delete(inst);
}

class B
{
    int x;
    char str[100];//constant char
public:
    B(int value, const char* point_array); //regular constructor
    B(const B& inst); //the copy constructor has to be made before getting into this function
    void print()const { std::cout << "element values: " << this->x << ' ' << this->str; }
    ~B() { std::cout << ")"; }
};
B::B(int value, const char* point_array)
{
    this->x = value; //equivalent to say after the definition of the parameters ": x(value)"
    strcpy(this->str, point_array);
    std::cout << "(";
}
B::B(const B& inst) 
{
    //inst. //acces only to the members and NOT methods without const at the end
    this->x = inst.x;
    strcpy(str, inst.str);
    std::cout << "(";
}

void constructors_main()
{
    //explicit distructor for static variables
    //implicit distructor is called at return by default
    //lab3_class a(3, 4);
    //part of the class just by the binding, the location is far away: static
    std::cout << "lab3_class: " << lab3_class::create(1, 2)->computation() << ' ' << lab3_class::create()->computation();
    lab3_class::deconstruct(); std::cout << '\n';

    B b1(5, "abc");
    B b2(10, "xyz");
    B b3(b1);
    B b4 = b2;

    B* bb = (B*)malloc(sizeof(B));
    new(bb)B(7, "bcde");
    bb->print();
    bb->~B();
    //new - allocates mammory + calls construction for clases
}
//something is wrong, ((( -3 ))))) -5 