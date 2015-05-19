#include "UpgradeData.h"

class GameManager
{

public:
	static GameManager &shared_instance() { static GameManager game; return game; }
	UpgradeData upgradeData;

private:
	GameManager()
	{
	
	}
};