#ifndef CloudBombardier_H
#define CloudBombardier_H

#include <array>
#include "IndependentLivingObject.h"

class World;
class Position;
struct SDL_Surface;


class CloudBombardier : public IndependentLivingObject
{
private:
	static std::array<SDL_Surface*, 3> bombardierImages;
	bool active;
	int computeImageIndex() const override;

public:
	CloudBombardier(Position position);
	static void loadBombardierImages(SDL_Surface* display);
	bool isGoingLeft() const;
	bool isReadyToDropBomb() const;
	void setActiveState();
	void draw(SDL_Surface* display, int beginningOfCamera, int endOfCamera) const override;
	void move(World &world) override;
};

#endif //CloudBombardier_H