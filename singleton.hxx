#ifndef SINGLETON_HXX
#define SINGLETON_HXX

#include <map>
#include <string>
#include <memory>

template<typename Class, typename... Bases>
class SmartPtrSingleton: public Bases... {
	protected:
		SmartPtrSingleton(std::string name = ""): name(name) {};
	
	public:
		std::string name;
		
		SmartPtrSingleton(SmartPtrSingleton const&) = delete;
		void operator=(SmartPtrSingleton const&) = delete;
		
		static std::shared_ptr<Class> instance() {
			static std::shared_ptr<Class> instance = std::shared_ptr<Class>(new Class);
			return instance;
		}
		
		static std::shared_ptr<Class> instance(std::string key) {
			if (key.empty()) {
				return instance();
			}
			static std::map< std::string, std::shared_ptr<Class> > instanceMap;
#if __cplusplus < 202002L
			if (!instanceMap.count(key) > 0) {
#else
			if (!instanceMap.contains(key)) {
#endif
				instanceMap[key] = std::shared_ptr<Class>(new Class(key));
			}
			return instanceMap[key];
		}
};


template<typename Class, typename... Bases>
class Singleton: public Bases... {
	protected:
		Singleton(std::string name = ""): name(name) {};
	
	public:
		std::string name;
		
		Singleton(Singleton const&) = delete;
		void operator=(Singleton const&) = delete;
		
		static Class* instance() {
			static Class* instance = new Class;
			return instance;
		}
		
		static Class* instance(std::string key) {
			if (key.empty()) {
				return instance();
			}
			static std::map<std::string, Class*> instanceMap;
#if __cplusplus < 202002L
			if (!instanceMap.count(key) > 0) {
#else
			if (!instanceMap.contains(key)) {
#endif
				instanceMap[key] = new Class(key);
			}
			return instanceMap[key];
		}
};

#endif

