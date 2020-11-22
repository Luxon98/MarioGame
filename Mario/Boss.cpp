#include "Boss.h"

#include "Movement.h"
#include "Size.h"
#include "Position.h"
#include "SDL_Utility.h"
#include "World.h"


std::array<SDL_Surface*, 2> Boss::bossImages;

int Boss::computeImageIndex() const
{
	return model - 1;
}

void Boss::changeModel()
{
	++changeModelCounter;
	if (changeModelCounter % 45 == 0) {
		model = (model == 1 ? 2 : 1);

		changeModelCounter = 0;
	}
}

void Boss::moveAndJump()
{
	++auxiliaryCounter;
	if (auxiliaryCounter < 11) {
		position.setX(position.getX() - 1);
		position.setY(position.getY() - 2);
	}
	else if (auxiliaryCounter >= 11 && auxiliaryCounter < 18) {
		position.setX(position.getX() - 1);
		position.setY(position.getY() - 1);
	}
	else if (auxiliaryCounter >= 18 && auxiliaryCounter < 22) {
		position.setX(position.getX() - 1);
	}
	else if (auxiliaryCounter >= 22 && auxiliaryCounter < 28) {
		position.setX(position.getX() - 1);
		position.setY(position.getY() + 2);
	}
	else if (auxiliaryCounter >= 28 && auxiliaryCounter < 37) {
		position.setY(position.getY() + 1);
	}
	else if (auxiliaryCounter >= 37 && auxiliaryCounter < 40) {
		position.setX(position.getX() + 1);
	}
	else if (auxiliaryCounter >= 40 && auxiliaryCounter < 45) {
		position.setX(position.getX() - 1);
		position.setY(position.getY() + 2);
	}
	else if (auxiliaryCounter == 120) {
		position.setY(position.getY() - 4);
		auxiliaryCounter = 0;
	}
}

Boss::Boss(Position position)
{
	size = Size(58, 64);
	movement = Movement(1, 1, Direction::None);
	this->position = position;
	model = 1;
	healthPoints = 5;
	auxiliaryCounter = 0;
	stepsCounter = 0;
	changeModelCounter = 0;
}

void Boss::loadBossImages(SDL_Surface* display)
{
	bossImages[0] = loadPNG("./img/boss1.png", display);
	bossImages[1] = loadPNG("./img/boss2.png", display);
}

int Boss::getHealthPoints() const
{
	return healthPoints;
}

void Boss::setMoveDirection(Direction direction)
{
	movement.setDirection(direction);
}

void Boss::draw(SDL_Surface* display, int beginningOfCamera, int endOfCamera) const
{
	if (position.getX() > beginningOfCamera - 90 && position.getX() < endOfCamera + 90) {
		SDL_Surface* bossImg = bossImages[computeImageIndex()];
		drawSurface(display, bossImg, position.getX() - beginningOfCamera, position.getY());
	}
}

void Boss::move(World &world)
{
	++stepsCounter;
	if (movement.getDirection() != Direction::None && stepsCounter & 1) {
		moveAndJump();
		changeModel();
	}
}

void Boss::decrementHealthPoints()
{
	--healthPoints;
}