#ifndef DestroyedCreature_H
#define DestroyedCreature_H

#include <array>
#include "TemporaryObject.h"
#include "Direction.h"

class Position;
struct SDL_Surface;


class DestroyedCreature : public TemporaryObject
{
private:
	static std::array<SDL_Surface*, 6> destroyedCreatureImages;
	Direction slideDirection;
	int computeBaseIndex() const;
	int computeImageIndex() const override;

public:
	DestroyedCreature(Position position, Direction slideDirection);
	static void loadDestroyedCreatureImages(SDL_Surface* display);
	void draw(SDL_Surface* display, int beginningOfCamera, int endOfCamera) const override;
	bool shouldBeRemoved() const override;
	void slide() override;
};

#endif //DestroyedCreature_H