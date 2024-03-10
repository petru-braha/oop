#pragma warning(disable:4996)
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
int conversion(char number[])
{
    int element = 0;
    short int nr_digits = 0;

    bool is_negative = 0;
    if (number[nr_digits] == '-')
    {
        nr_digits++;
        is_negative = 1;
    }
    while (number[nr_digits + 1])
        nr_digits++;

    int p = 1;
    while (nr_digits > 0)
    {
        element += (number[nr_digits] - '0') * p;
        p *= 10;
        nr_digits--;
    }
    if (is_negative)
        return element * -1;
    return element += (number[0] - '0') * p;
}

void H1_sum()
{
    int s = 0;
    FILE* input = fopen("numbers.txt", "r");
    if (input == nullptr) { std::cout << "error at opening.\n"; return; }

    char number[300] = { 0 };

    while (number)
    {
        fread(number, 300, 1, input);
        s += conversion(number);
    }
    printf("the sum of the numbers is %d .\n", s);
    fclose(input);
}

    

/*
bool isPrime(int n)//with the assumption that n is natural
{
    for (int tr = 2; tr < n / 2; tr++)
        if (n % tr == 0)
            return false;
    if (n == 0 || n == 1)
        return false;
    return true;
}
int main()
{
    int n;
    std::cout << "Enter a number:";
    std::cin >> n;
    if (isPrime(n))
        std::cout << n << " is prime !";
    else
        std::cout << n << " is NOT prime !";
    return 0;
}

*/