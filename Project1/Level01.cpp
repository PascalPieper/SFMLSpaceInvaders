#include "Level01.h"
Level01::Level01(GameManager* pGameManager) : Scene(pGameManager)
{

}

void Level01::Step01()
{
}

void Level01::StartScene(PlayerCharacter& playerCharacter)
{
	ScreenFade* screenfade = new ScreenFade(sf::Vector2f{ 0,0 }, sf::Color{}, 5.f, sf::Vector2f{ 0,0 });
	screenfade->onFade();
}

