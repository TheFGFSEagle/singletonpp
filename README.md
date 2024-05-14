# Singleton++
Simple header-only multi-instance-option singleton class for C++ 20 (earlier is supported too)

# Usage example
```c++
#include <iostream>
#include <singleton.hxx>

class A: public Singleton<A,> {
	public:
		A() {
			std::cout << "Created instance of A with address=" << this << std::endl;
		}
		A(std::string name) {
			std::cout << "Created instance of A with address=" << this << " and name=" << name << std::endl;
		}
};

int main(void) {
	A* a = A::instance();
	std::cout << "Address in main: " << a << std::endl;
	delete a;
	
	A* a1 = A::instance("one");
	A* a2 = A::instance("two");
	std::cout << "Addresses are equal ? " << (a1 == a2) << std::endl;
	return 0;
}
```

If `Singleton::instance` is called with an argument like in the second part of the example `main` function, the class inheriting from `Singleton` must define a constructor taking one argument of type `std::string` - doing anything with it is of course optional.
