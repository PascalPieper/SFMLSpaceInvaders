#pragma once

namespace Tag
{
	enum EntityTag { PLAYER = 0, ENEMY = 1, NPC = 2, BULLET = 3, PLATFORM = 4, BACKGROUND = 5, HITBOX = 6 };
}

namespace Layer
{
	enum DrawLayertest { BACKGROUND_01 = 0, BACKGROUND_02 = 1, BACKGROUND_03 = 2, PLATFORM = 3, PLAYER = 4, NPC = 5, PARTICLE = 6, HITBOX = 7 };
}
namespace Alignment
{
	enum Alignment {
		CENTER = 0,
		CENTER_LEFT = 1,
		CENTER_RIGHT = 2,
		CENTER_TOP = 3,
		CENTER_BOTTOM = 4,
		TOP_RIGHT = 5,
		TOP_LEFT = 6,
		BOTTOM_RIGHT = 7,
		BOTTOM_LEFT = 8
	};
}
namespace Character
{
	enum Character { ARMON = 0, LILLIN = 1, RAUDA = 2, KAZEM = 3, ANEK = 4, MATRONA = 5 };
}

