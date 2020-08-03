#include "Flower.h"

SDL_Surface* Flower::flowerImages[2] = { nullptr };

int Flower::typeOfImage = 2;

Flower::Flower() {}

Flower::Flower(Position* position)
{
	size = new Size(32, 32);
	this->position = position;
	growCounter = 96;
}

void Flower::changeFlowerImage()
{
	Flower::typeOfImage = (Flower::typeOfImage == 1 ? 2 : 1);
}

void Flower::loadFlowerImages(SDL_Surface* screen)
{
	flowerImages[0] = loadPNG("./img/flower1.png", screen);
	flowerImages[1] = loadPNG("./img/flower2.png", screen);
}

void Flower::draw(SDL_Surface* screen, int beginningOfCamera)
{
	SDL_Surface* flowerImg = nullptr;
	flowerImg = flowerImages[typeOfImage - 1];
	drawSurface(screen, flowerImg, position->getX() - beginningOfCamera, position->getY());
}

void Flower::move(Direction direction, int distance, World& world, Screen* mainScreen)
{
	if (growCounter) {
		grow();
	}
}
