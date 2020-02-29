/*
** Last Author: Thomas
** Date Modified: 15/11/19
** Version: 0.001
** Change Log:
*** -------- <15/11/19>
***	<Thomas> Added Signiature Head
*** --------- End of Changes
*/

#include <vector>
#include <SFML/Graphics.hpp>
#include "SpriteManager.h"
#include <iostream>

using namespace std;
#ifndef MAZE_H
#define MAZE


class Maze
{
public:
	//Declare Constructor(s)
	Maze();
	//Declare Deconstructor(s)
	/* None at the minute */
	/* Only needed when pointers are being declared here */

	//Declare Public Variables
	vector<int> location;
	sf::Sprite* currentMazeSprite;
	SpriteManager spriteManager;
	void Setup(int id);
protected:
	vector<sf::Sprite*> mazeSprites;
	vector<sf::Texture> mazeTextures;


	//Declare Public Functions
	
	void TextureSetup();
};
#endif // !MAZE_H
