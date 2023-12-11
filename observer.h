#pragma once
#include <vector>
#include <algorithm>
class Observer {
public:
	virtual void update() = 0;
};

class Subject {
public:
	std::vector<Observer*> overseers;
	void addObserver(Observer* o) {
		this->overseers.push_back(o);
	}
	void removeObserver(Observer* o) {
		this->overseers.erase(find(this->overseers.begin(), this->overseers.end(), o));
	}
	void notify() {
		for (Observer* o : overseers)
			o->update();
	}
};
