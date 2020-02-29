/*
** Last Author: Thomas
** Date Modified: 15/11/19
** Version: 0.001
** Change Log:
*** -------- <15/11/19>
***	<Thomas> Created File
***	<Thomas> Added Signiature Head
*** --------- End of Changes
*/

#ifndef SPRITEMANAGER_H
#define SPRITEMANAGER_H
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

using namespace std;
class SpriteManager {
public:
	vector<sf::Sprite*> sprites;
	vector<sf::Texture*> textures;
	vector<string> lookup;
	SpriteManager();
	~SpriteManager();
	sf::Sprite* SetSprite(string path);
	
	sf::Sprite* GetSprite(int id);
	sf::Sprite* GetSprite(string path);
	int SpriteExist(string path);
};

#endif // !SPRITEMANAGER_H
