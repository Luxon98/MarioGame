#include "Turtle.h"

SDL_Surface* Turtle::turtleImages[4] = { nullptr };

void Turtle::chooseModel()
{
	changeModelCounter++;
	if (changeModelCounter % 30 == 0) {
		model += (model & 1 ? 1 : -1);
	}
}

Turtle::Turtle() {}

Turtle::Turtle(Position* position)
{
	size = new Size(26, 38);
	movement = new Movement(1, None);
	this->position = position;
	model = 1;
	stepsCounter = 0;
	changeModelCounter = 0;
}

void Turtle::setMoveDirection(Direction direction)
{
	movement->setDirection(direction);
}

void Turtle::loadTurtleImages(SDL_Surface* display)
{
	turtleImages[0] = loadPNG("./img/turtle_left1.png", display);
	turtleImages[1] = loadPNG("./img/turtle_left2.png", display);
	turtleImages[2] = loadPNG("./img/turtle_rigth1.png", display);
	turtleImages[3] = loadPNG("./img/turtle_right2.png", display);
}

void Turtle::draw(SDL_Surface* display, int beginningOfCamera)
{
	SDL_Surface* turtleImg = nullptr;
	turtleImg = turtleImages[model - 1];
	drawSurface(display, turtleImg, position->getX() - beginningOfCamera, position->getY());
}

void Turtle::move(World& world)
{
	if (movement->getDirection() != None && stepsCounter % 3 == 0) {
		if (isCharacterStandingOnTheBlock(this, world)) {
			int alignment = getAlignmentIfCollisionOccursDuringMovement(movement->getDirection(), movement->getSpeed(), this, world);
			int distance = movement->getDirection() == Right ? (movement->getSpeed() - alignment) : (-1) * (movement->getSpeed() - alignment);
			position->setX(position->getX() + distance);

			if (alignment > 0) {
				movement->setDirection(movement->getDirection() == Right ? Left : Right);
				model = (movement->getDirection() == Left ? 1 : 3);
			}
		}
		else {
			int verticalDistance = (2 * movement->getSpeed()) - getAlignmentIfCollisionOccursDuringVerticalMovement(Down, 2 * movement->getSpeed(), this, world);
			position->setY(position->getY() + verticalDistance);

			int distance = (movement->getDirection() == Right ? 1 : -1) * (1 - getAlignmentIfCollisionOccursDuringMovement(movement->getDirection(), movement->getSpeed(), this, world));
			position->setX(position->getX() + distance);
		}

		chooseModel();
	}

	stepsCounter++;
}

