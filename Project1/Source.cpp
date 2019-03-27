#include <iostream>
#include "FunctionStack.h"

class Test
{
public:
	int test = 1;
	float test2 = 0;

	void * function(void * i)
	{
		test += *reinterpret_cast<int*>(i);
		return reinterpret_cast<void*>(&test);
	}

	void * func2(void * i)
	{
		test2 = *reinterpret_cast<float*>(i);
		return nullptr;
	}
};

int main ()
{
	FunctionStack<Test> functionStack;

	Test t;

	functionStack.Push(&Test::function, &t);
	functionStack.Push(&Test::func2, &t);

	int i = 5;

	float f = 0.1f;

	functionStack.Execute(&f);

	std::cout << t.test2 << std::endl;

	std::cin.get();

	return 0;
}
