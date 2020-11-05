#include "SingletonManager.h"

void SingletonManager::AddSingleton(Singleton *singleton) {
	list_singleton.push_back(singleton); 
}

void SingletonManager::clearSingletonList() {
	for (auto s : list_singleton) {
		delete s; 
	}
	list_singleton.clear(); 
}




