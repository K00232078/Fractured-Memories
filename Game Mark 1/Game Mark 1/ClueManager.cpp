#include "ClueManager.h"
#include <iostream>

ClueManager::ClueManager()
{
	spriteManager = SpriteManager();
	pickedUpSprite = spriteManager.GetSprite("Textures/PickedUp.png");
	SetUpWeapons();
	SetUpMotives();
	SetUpSuspects();
	SetUpSprites();
}

Clue* ClueManager::RandomClue(string type)
{
	Clue* pickedClue = nullptr;

	char option = toupper(type[0]);
	int random = 0;
	bool incomplete = true;
	switch (option)
	{
	case 'W':
		while (incomplete)
		{
			random = RandomNumber(weapons.size());
			if (!weapons[random]->solution)
			{
				pickedClue = weapons[random];
				incomplete = false;
			}
		}
		break;
	case 'S':
		while (incomplete)
		{
			random = RandomNumber(suspects.size());
			if (!suspects[random]->solution)
			{
				pickedClue = suspects[random];
				incomplete = false;
			}
		}
		break;
	case 'M':
		while (incomplete)
		{
			random = RandomNumber(motives.size());
			if (!motives[random]->solution)
			{
				pickedClue = motives[random];
				incomplete = false;
			}
		}
		break;
	}
	return pickedClue;
}

Clue* ClueManager::RandomClue()
{
	cout << "Returning Random Clue" << endl;
	Clue* pickedClue = nullptr;
	int option = RandomNumber(3);
	int random = 0;
	bool incomplete = true;
	while (incomplete)
	{
		option = RandomNumber(3);
		switch (option)
		{
		case 0:
			random = RandomNumber(weapons.size());
			if (!weapons[random]->solution && !weapons[random]->pickedUp)
			{
				pickedClue = weapons[random];
				incomplete = false;
			}
			break;
		case 1:
			random = RandomNumber(suspects.size());
			if (!suspects[random]->solution && !suspects[random]->pickedUp)
			{
				pickedClue = suspects[random];
				incomplete = false;
			}
			break;
		case 2:
			random = RandomNumber(motives.size());
			if (!motives[random]->solution && !motives[random]->pickedUp)
			{
				pickedClue = motives[random];
				incomplete = false;
			}
			break;
		}
	}
	
	pickedClue->pickedUp = true;
	return pickedClue;
}

vector<Clue*> ClueManager::ReturnSolution()
{
	vector<Clue*> solution;

	for (size_t i = 0; i < suspects.size(); i++)
	{
		if (suspects[i]->solution)
		{
			solution.push_back(suspects[i]);
		}
	}

	for (size_t i = 0; i < weapons.size(); i++)
	{
		if (weapons[i]->solution)
		{
			solution.push_back(weapons[i]);
		}
	}

	for (size_t i = 0; i < motives.size(); i++)
	{
		if (motives[i]->solution)
		{
			solution.push_back(motives[i]);
		}
	}
	return solution;
}

void ClueManager::SetUpWeapons()
{
	weapons.push_back(new Clue("Candlestick","The WEAPON couldn't have been a Candlestick, they were all in their right place!","weapon","Textures/Candlestick2.png",""));
	weapons.push_back(new Clue("Poison","The WEAPON couldn't have been poison, I remember he WASN'T foaming at the mouth!","weapon","Textures/Poison2.png", ""));
	weapons.push_back(new Clue("Sword","The WEAPON couldn't have been a sword, there was no stab wounds!","weapon","Textures/Sword2.png", ""));
	weapons.push_back(new Clue("Club","The WEAPON couldn't have been a Club, I remember it wasn't that type of wound!","weapon","Textures/Club2.png", ""));
	
	weapons[RandomNumber(weapons.size())]->solution = true;
}

void ClueManager::SetUpMotives()
{
	motives.push_back(new Clue("Greed", "He couldn't have been killed because of his GREED, he wasn't like that, always giving to charity!", "motive", "Textures/greed.png", "my husband was always taking things and wanted everything!"));
	motives.push_back(new Clue("Envy", "He couldn't have been killed because of his ENVY, he didn't really care for material things!","motive", "Textures/envy.png", "my husband was always wanting of other people's possessions!"));
	motives.push_back(new Clue("Lust", "He couldn't have been killed because of his LUST, he was a gentleman who only had eyes for me!", "motive", "Textures/lust.png", "my husband was a ladys man, and he hit on everyone!"));
	motives.push_back(new Clue("Sloth", "He couldn't have been killed because of his SLOTH, he was a dilligent man, who had a good work ethic!", "motive", "Textures/sloth.png", "my husband was very lazy and didn't complete his work on time!"));
	motives.push_back(new Clue("Wrath", "He couldn't have been killed because of his WRATH, he was a very understanding and calm man!", "motive", "Textures/wrath.png", "my husband was a very angry man, quick to violence!"));
	motives.push_back(new Clue("Gluttony", "He couldn't have been killed because of his GLUTTONY, he always showed some self restraint!", "motive", "Textures/gluttony.png", "my husband didn't show any self restraint, when it came to food, he stole cookies!"));
	motives.push_back(new Clue("Pride", "He couldn't have been killed because of his PRIDE, he wasn't afraid to show humility", "motive", "Textures/pride.png", "my husband was an arrogant man and his hubris was his downfall!"));


	motives[RandomNumber(motives.size())]->solution = true;
}

void ClueManager::SetUpSuspects()
{
	suspects.push_back(new Clue("Bob", "The MURDERER couldn't have been Bob, he has no hands!", "suspect", "Textures/Bob.png", ""));
	suspects.push_back(new Clue("Sam", "The MURDERER couldn't have been Sam, she is a pacifist!", "suspect", "Textures/Sam.png", ""));
	suspects.push_back(new Clue("Jim", "The MURDERER couldn't have been Jim, I remember the priest kept talking to him!", "suspect", "Textures/Jim.png", ""));
	suspects.push_back(new Clue("Skylar", "The MURDERER couldn't have been Skylar, he wasn't mentally strong enough for that!", "suspect", "Textures/Skylar.png", ""));

	suspects[RandomNumber(suspects.size())]->solution = true;
}

void ClueManager::SetUpSprites()
{
	for (size_t i = 0; i < motives.size(); i++)
	{
		motives[i]->clueSprite->setOrigin(300, 300); //Objects are 600x600
	}
	for (size_t i = 0; i < weapons.size(); i++)
	{
		weapons[i]->clueSprite->setOrigin(300, 300); //Objects are 600x600
	}
	for (size_t i = 0; i < suspects.size(); i++)
	{
		suspects[i]->clueSprite->setOrigin(300, 300); //Objects are 600x600
	}
	pickedUpSprite->setOrigin(300, 300);
}

int ClueManager::RandomNumber(int size)
{
	int r = rand() % size;
	return r;
}
