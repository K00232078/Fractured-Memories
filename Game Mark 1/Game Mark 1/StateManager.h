#ifndef STATE_MANAGER
#define STATE_MANAGER

class StateManager
{
public:
	int CURRENT_STATE = MENU;
	int STORY_STATE = 4; // No given substate at beginning.
	enum STATE 
	{
		MENU = 0,
		PLAY = 1,
		PUZZLE = 2,
		PAUSE = 3,
		HOW_TO_PLAY = 4,
		NEXT_LEVEL = 5,
		GUESS_KILLER = 6,
		STATENUll = 7,
        DEATH = 8

	};
	enum SUBSTATE
	{
		OPENING_SCENE = 0,
		PICKUP_CLUE = 1,
		OPENING_PUZZLE = 2,
		MENU_EXIT = 3,
		NUll = 4
	};
};

#endif // !STATE_MANAGER

