#pragma once
#include <list>

using namespace std;

template <class T>
class QueueList {
	list<T> data;

public:
	void EnQueue(T x) {
		data.push_back(x);
	}

	T DeQueue() {
	
		T value = data.front();  
		data.pop_front();  
		return value;
	}

	bool IsEmpty() {
		return data.empty();
	}
};
