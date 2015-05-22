#ifndef UPGRADEDATA_H
#define UPGRADEDATA_H
class UpgradeData
{

public:
	int moveSpeed, clockSpeed, jumpHeight, CollectionArea;
	int moveSpeedCost = 5;
	int clockSpeedCost = 7;
	int jumpHeightCost = 5;
	int CollectionAreaCost = 10;
	int coins = 0;
	bool doubleJump;
	float clock = 30.0;
};

#endif