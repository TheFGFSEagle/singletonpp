#ifndef SINGLETON_HXX
#define SINGLETON_HXX

#include <map>
#include <string>
#include <memory>

template<typename Class, typename... Bases>
class Singleton: public Bases... {
	protected:
		Singleton(std::string name = ""): name(name) {};
	
	public:
		std::string name;
		
		Singleton(Singleton const&) = delete;
		void operator=(Singleton const&) = delete;
		
		static std::shared_ptr<Class> instance() {
			static std::shared_ptr<Class> instance = std::shared_ptr<Class>(new Class);
			return instance;
		}
		
		static std::shared_ptr<Class> instance(std::string key) {
			if (key.empty()) {
				return instance();
			}
			static std::map<std::string, std::shared_ptr<Class>> instanceMap;
			if (!instanceMap.contains(key)) {
				instanceMap[key] = std::shared_ptr<Class>(new Class(key));
			}
			return instanceMap[key];
		}
};

#endif

