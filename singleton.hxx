#ifndef SINGLETON_HXX
#define SINGLETON_HXX

#include <map>
#include <string>
#include <memory>

template<typename Class, typename... Bases, typename SmartPtrType = std::shared_ptr>
class SmartPtrSingleton: public Bases... {
	protected:
		SmartPtrSingleton(std::string name = ""): name(name) {};
	
	public:
		std::string name;
		
		SmartPtr(SmartPtrSingleton const&) = delete;
		void operator=(SmartPtrSingleton const&) = delete;
		
		static SmartPtrType<Class> instance() {
			static SmartPtrType<Class> instance = SmartPtrType<Class>(new Class);
			return instance;
		}
		
		static SmartPtrType<Class> instance(std::string key) {
			if (key.empty()) {
				return instance();
			}
			static std::map< std::string, SmartPtrType<Class> > instanceMap;
#if __cplusplus < 202002L
			if (!instanceMap.count(key) > 0) {
#else
			if (!instanceMap.contains(key)) {
#endif
				instanceMap[key] = SmartPtrType<Class>(new Class(key));
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

