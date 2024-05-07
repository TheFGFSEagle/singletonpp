#include <iostream>
#include <string>

#include <singleton.hxx>

class A: public Singleton<A> {
	public:
		void set_data(std::string data) {
			_data = data;
		}
		std::string get_data() {
			return _data;
		}
	
	protected:
		using Singleton::Singleton;
		std::string _data;
};

int main(int argc, char* argv[]) {
	A::instance("1")->set_data("one");
	A::instance("2")->set_data("two");
	
	bool result = true;
	result &= A::instance("1")->get_data() == "one";
	result &= A::instance("2")->get_data() == "two";
	result &= A::instance("3")->get_data() == "";
	result &= A::instance()->get_data() == "";
	return (int)(!result);
}
