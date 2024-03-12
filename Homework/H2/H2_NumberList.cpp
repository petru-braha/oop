#include "H2_NumberList.h"

void NumberList::Init()
{
	this->count = 0;
}

bool NumberList::Add(int x)
{
	if (this->count < 10)
	{
		this->numbers[this->count++] = x;
		return 1;
	}
	return 0;
}

void NumberList::Sort()
{
    int n = this->count;
    for (int i = 1; i < n; i++) 
    {
        int key = this->numbers[i];
        int j = i - 1;

        while (j >= 0 && this->numbers[j] > key) {
            arr[j + 1] = this->numbers[j];
            j = j - 1;
        }
        this->numbers[j + 1] = key;
    }
}

void NumberList::Print()
{
	for (int i = 0; i < this->count; i++)
		std::cout << this->numbers[i] << ' ';
}