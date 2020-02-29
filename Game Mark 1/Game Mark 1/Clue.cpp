#include "Clue.h"

Clue::Clue()
{
	name = "";
	description = "";
	descriptionSolution = "";
	type = "";
	pickedUp = false;
	solution = false;
	clueSprite = new sf::Sprite();
	collisionSprite = new sf::Sprite();
	texture = new sf::Texture();
	SpriteSetup();
}
/*
Clue::~Clue()
{
	//delete[] clueSprite;
}*/

Clue::Clue(string n, string d, string t, string path, string ds)
{
	name = n;
	description = d;
	descriptionSolution = ds;
	type = t;
	pickedUp = false;
	solution = false;
	SpriteSetup(path);
}

void Clue::SpriteSetup()
{
	texture->loadFromFile("Textures/gem2.png");
	collisionSprite->setTexture(*texture);
	collisionSprite->setOrigin(290.5, 293);
	collisionSprite->scale(0.1, 0.1);

}

void Clue::SpriteSetup(string path)
{
	texture = new sf::Texture();
	texture->loadFromFile(path);
	clueSprite = new sf::Sprite();
	clueSprite->setTexture(*texture);
	clueSprite->setOrigin(290.5, 293);
}
