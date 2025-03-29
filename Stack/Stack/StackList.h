#include <list>
using namespace std;
template <class T>

class StackList {
	list<T> data;

public:

	void push(T v) {
		data.push_back(v);
	}

	T pop() {
		T v = data.back();
		data.pop_back();
		return v;
	}

	bool IsEmpty() {
		return data.empty();
	}
};