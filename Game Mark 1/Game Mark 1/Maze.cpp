/*
** Last Author: Thomas
** Date Modified: 15/11/19
** Version: 0.0
** Change Log:
*** -------- <15/11/19>
***	<Thomas> Added Constructor Calls
***	<Thomas> Why?: Testing
*** --------- End of Changes
*/

#include "Maze.h"

Maze::Maze()
{
	spriteManager = SpriteManager();
	TextureSetup();
	Setup(0);
}

void Maze::Setup(int id)
{
	currentMazeSprite = mazeSprites[id];
}

void Maze::TextureSetup()
{
	//currentMazeSprite = spriteManager.GetSprite("Textures/maze1.png");
	mazeSprites.push_back(spriteManager.GetSprite("Textures/maze2.png"));
	mazeSprites.push_back(spriteManager.GetSprite("Textures/maze3.png"));
	mazeSprites.push_back(spriteManager.GetSprite("Textures/maze4.png"));
}
