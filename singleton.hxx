#ifndef SINGLETON_HXX
#define SINGLETON_HXX

#include <map>
#include <string>

template<typename Class, typename... Bases>
class Singleton: public Bases... {
	private:
		Singleton(std::string name = ""): name(name) {};
	public:
		std::string name;
		
		static Class* instance() {
			static Class* instance = new Class;
			return instance;
		}
		
		static Class* instance(std::string key) {
			if (key.empty()) {
				return instance();
			}
			static std::map<std::string, Class*> instanceMap;
			if (!instanceMap.contains(key)) {
				instanceMap[key] = new Class(key);
			}
			return instanceMap[key];
		}
};
#endif

