#include <PaintClass.h>

PaintClass::PaintClass(RenderWindow* windowScreen) {
	this->windowScreen = windowScreen;
	
	addVector(123, 456); 

	cout << "LOL";
	cout << paintArr[0][0] << ": x" << paintArr[0][1] << ": y" << endl;
}

void PaintClass::painting() {

}

void PaintClass::addVector(int x, int y) {
	paintArr.push_back(vector<int>());
	paintArr[paintArr.size() - 1].push_back(x);
	paintArr[paintArr.size()].push_back(y);
}