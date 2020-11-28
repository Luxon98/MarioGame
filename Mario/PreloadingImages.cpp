#include "PreloadingImages.h"

#include "Player.h"
#include "Coin.h"
#include "Flower.h"
#include "Mushroom.h"
#include "Star.h"
#include "FireBall.h"
#include "Turtle.h"
#include "RedTurtle.h"
#include "Creature.h"
#include "Plant.h"
#include "Shell.h"
#include "FireRocket.h"
#include "Boss.h"
#include "Flag.h"
#include "Button.h"
#include "AnimatedText.h"
#include "AnimatedCoin.h"
#include "Shards.h"
#include "Explosion.h"
#include "CrushedCreature.h"
#include "DestroyedCreature.h"
#include "DestroyedTurtle.h"
#include "DestroyedBoss.h"
#include "Bush.h"
#include "Cloud.h"
#include "Rock.h"
#include "Lava.h"
#include "Castle.h"
#include "Princess.h"
#include "CustomWinterDecoration.h"
#include "Block.h"
#include "Platform.h"
#include "FireSerpent.h"
#include "MenuManager.h"


void preloadBonusObjectsImages(SDL_Surface* display)
{
	Flower::loadFlowerImages(display);
	Mushroom::loadMushroomImages(display);
	Star::loadStarImages(display);
}

void preloadInanimateObjectImages(SDL_Surface* display)
{
	Coin::loadCoinImages(display);
	Bush::loadBushImages(display);
	Cloud::loadCloudImages(display);
	Rock::loadRockImage(display);
	Lava::loadLavaImage(display);
	Flag::loadFlagImages(display);
	Button::loadButtonImages(display);
	Castle::loadCastleImages(display);
	Princess::loadPrincessImages(display);
	CustomWinterDecoration::loadDecorationImages(display);
}

void preloadLivingObjectImages(SDL_Surface* display)
{
	Creature::loadCreatureImages(display);
	Turtle::loadTurtleImages(display);
	RedTurtle::loadTurtleImages(display);
	Plant::loadPlantImages(display);
	FireRocket::loadFireRocketImages(display);
	Boss::loadBossImages(display);
	Shell::loadShellImage(display);
	FireBall::loadFireBallImages(display);
	Player::loadPlayerImages(display);
}

void preloadTemporaryObjectImages(SDL_Surface* display)
{
	CrushedCreature::loadCrushedCreatureImages(display);
	DestroyedCreature::loadDestroyedCreatureImages(display);
	DestroyedTurtle::loadDestroyedTurtleImages(display);
	DestroyedBoss::loadDestroyedBossImages(display);
	Explosion::loadExplosionImages(display);
	Shards::loadShardsImages(display);
	AnimatedCoin::loadAnimatedCoinImages(display);
	AnimatedText::loadAnimatedTextImages(display);
}

void preloadOtherImages(SDL_Surface* display)
{
	Block::loadBlockImages(display);
	Platform::loadPlatformImage(display);
	FireSerpent::loadFireSerpentImages(display);
	MenuManager::loadMenuImages(display);
}

void preloadImages(SDL_Surface* display)
{
	preloadBonusObjectsImages(display);
	preloadInanimateObjectImages(display);
	preloadLivingObjectImages(display);
	preloadTemporaryObjectImages(display);
	preloadOtherImages(display);
}