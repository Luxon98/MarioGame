#ifndef CheckPoint_H
#define CheckPoint_H

#include "Position.h"

class Player;


class CheckPoint
{
private:
	Position position;
	bool automatic;
	int range;
	unsigned int mark;

public:
	CheckPoint(Position position, bool automatic, int range, int mark);
	bool isAutomatic() const;
	unsigned int getMark() const;
	bool isPlayerInRangeOfCheckPoint(const Player &player) const;
};

#endif //CheckPoint_H