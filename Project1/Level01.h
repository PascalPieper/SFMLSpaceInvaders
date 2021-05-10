#pragma once
#include "Scene.h"
#include "ScreenFade.h"
class Level01 : public Scene 
{
public:
	Level01(GameManager* pGameManager);

public:
	void StartScene(PlayerCharacter& playerCharacter) override;
	void Step01();
};