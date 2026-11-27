#pragma once

class DesignPattern {
private:
	std::string name_;
public:

	DesignPattern(const std::string& name) : name_(name){}
	virtual ~DesignPattern() {}

	virtual void runPattern() = 0;
	std::string getName() const { return name_; }
};