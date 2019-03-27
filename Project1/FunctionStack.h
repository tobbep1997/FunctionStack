#pragma once
#include <stack>

template <typename T>
class FunctionStack
{
	struct Function
	{
		void * (T::*Func)(void*);
		void * Object;
	};

	std::stack<Function> m_stack;

	static void* _execute(Function function, void* input)
	{
		return (*reinterpret_cast<T*>(function.Object).*function.Func)(input);
	}

public:
	FunctionStack() = default;
	~FunctionStack() = default;
	
	void* Execute(void* input)
	{
		return _execute(m_stack.top(), input);
	}

	void Push(void*(T::*func)(void*), T* object)
	{
		m_stack.push({func, object});
	}
};
