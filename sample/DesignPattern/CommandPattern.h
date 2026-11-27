#pragma once
#include <iostream>
#include <string>
#include "DesignPattern.h"

/**
* コマンドの抽象クラス
**/
class Command {
private:
public:
	virtual ~Command() {}
	virtual void Execute() const = 0;
};

class SimpleCommand : public Command {
private:
	std::string pay_load_;
public:
	explicit SimpleCommand(std::string pay_load)
		: pay_load_(pay_load) {
	}

	void Execute() const override {
		std::cout << "SimpleCommand: コマンドが実行されました: (" << this->pay_load_ << ")\n";
	}
};

class Invoker {
private:
	Command* on_start_;
public:

	~Invoker() {
		delete on_start_;
	}

	void SetOnStart(Command* command) {
		this->on_start_ = command;
	}

	void DoSomethingImportant() {
		std::cout << "Invoker: コマンドを実行します\n";
		if (this->on_start_ != nullptr) {
			this->on_start_->Execute();
		}
	}
};

class CommandPattern : public DesignPattern {
private:
public:

	CommandPattern()
		: DesignPattern("Command") {

	}

	void runPattern() {
		Invoker* invoker = new Invoker;
		invoker->SetOnStart(new SimpleCommand("Say Hi!"));
		invoker->DoSomethingImportant();

		delete invoker;
	}
};