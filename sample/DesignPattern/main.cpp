#include <iostream>
#include "DesignPattern.h"
#include "CommandPattern.h"
#include <vector>

namespace {
	std::vector<DesignPattern*> designPatternList_ = std::vector<DesignPattern*>();
}

void init() {
	designPatternList_.clear();
	designPatternList_.push_back(new CommandPattern());
}

int main() {
	init();

	std::cout << "実行するデザインパターン番号を入力してください" << std::endl;
	for (int i = 0; i < designPatternList_.size(); i++) {
		auto& designPattern = designPatternList_[i];
		std::cout << i << "(" << designPattern->getName() << ")" << std::endl;
	}

	int index = 0;
	std::cin >> index;
	if (index >= 0 && index < designPatternList_.size()) {
		designPatternList_[index]->runPattern();
		return 0;
	}

	std::cout << "そのデザインパターンは見つかりませんでした。" << std::endl;

	return -1;
}