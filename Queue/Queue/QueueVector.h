#pragma once
#include <vector>
using namespace std;

template <class T>
class QueueVector {
	vector<T> data;

public:
	void EnQueue(T x) {
		data.push_back(x);
	}

	T DeQueue() {
		T value = data.front();  
		data.erase(data.begin()); 
		return value;
	}

	bool IsEmpty() {
		return data.empty();
	}
};
