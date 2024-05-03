# Singleton++
Simple header-only multi-instance-option singleton class for C++ 20

# Usage example
```c++
#include <iostream>
#include <singleton.hxx>

class A: public Singleton<A,> {
	public:
		A() {
			std::cout << "Created instance of A with address=" << this << std::endl;
		}
};

int main(void) {
	A* a = A::instance();
	std::cout << "Address in main: " << a << std::endl;
	delete a;
	A* a1 = A::instance("one");
	A* a2 = A::instance("two");
	s
}
```
