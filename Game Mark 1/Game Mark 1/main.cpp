/*
** Last Author: Thomas
** Date Modified: 15/11/19
** Version: 0.001
** Change Log:
*** -------- <15/11/19>
***	<Thomas> Created File
*** --------- End of Changes
*/
#include "Game.h"
#include "Enemy.h"

int main() {
	srand(time(NULL));
	Game* game = new Game();
	while (game->init())
	{
		game = new Game();
	}

	return 0;
}