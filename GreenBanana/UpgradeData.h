#ifndef UPGRADEDATA_H
#define UPGRADEDATA_H
class UpgradeData
{

public:
	int moveSpeed, clockSpeed, jumpHeight, CollectionArea;
	int moveSpeedCost = 5;
	int clockSpeedCost = 5;
	int jumpHeightCost = 5;
	int CollectionAreaCost =5;
	int coins = 10;
	bool doubleJump;
	float clock = 30.0;
};

#endif