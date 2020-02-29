#include "Guess.h"
Guess::Guess(ClueManager* clue, sf::RenderWindow* windows,int framecount)
{
	spriteManager = new SpriteManager();
	tm = new TextManager();
	playerTexture = sf::Texture();
	playerSprite = sf::Sprite();
	clues = clue;
	window = windows;
	frameCount = framecount;
}
void Guess :: init()
{
	spriteSetup();
	popluateSelectedItemList();
}


void Guess :: spriteSetup()
{
	//Create textures and sprites
	playerTexture.loadFromFile("Textures/Luna back.png");
	playerSprite.setTexture(playerTexture);

	enemyTexture.loadFromFile("Textures/Reaper.png");
	enemySprite.setTexture(enemyTexture);

	//Set sprite orign
	playerSprite.setOrigin(640,360);
	enemySprite.setOrigin(17, 16.5);

	playerSprite.setPosition(window->getSize().x / 2 , window->getSize().y / 1.6);
	enemySprite.setPosition(window->getSize().x / 2, window->getSize().y / 9);

	playerSprite.setScale(.30, .30);
	enemySprite.setScale(3,3);

}

void Guess:: setupGuessWindow()
{
	sf::CircleShape weaponsquare(80,4);
	sf::CircleShape suspectsquare(80,4);
	sf::CircleShape movtivesquare(80,4);

	//Location that will display players guessed weapon
	weaponsquare.setScale(.75, .75);
	weaponsquare.setOrigin(80, 2);
	weaponsquare.setPosition(700,200);
	weaponsquare.setFillColor(sf::Color::Black);

	//Location that will display players guessed suspect
	suspectsquare.setScale(.75, .75);
	suspectsquare.setOrigin(80, 2);
	suspectsquare.setPosition(900, 200);
	suspectsquare.setFillColor(sf::Color::Black);

	//Location that will display players guessed motive.
	movtivesquare.setScale(.75, .75);
	movtivesquare.setOrigin(80, 2);
	movtivesquare.setPosition(1100, 200);
	movtivesquare.setFillColor(sf::Color::Black);

	//Draw stuff
	window->draw(weaponsquare);
	window->draw(suspectsquare);
	window->draw(movtivesquare);
	window->draw(playerSprite);
 	window->draw(enemySprite);

}

/*
	Checks what clue type the player is currently guessing. 
	Set maxNoOptions based on the number of clues of that type
	weapon = 4,suspect = 4, motive = 7
*/
void Guess::checkState()
{
	
	if (guessSelctionState == 0)
	{
		maxNoOptions = 4;
		displayWeapons();
	}

	if (guessSelctionState == 1)
	{
		maxNoOptions = 4;
		displaySuspects();
	}

	if (guessSelctionState == 2)
	{
		maxNoOptions = 7;
		displayMotives();
	}
}

void Guess::displayWeapons()
{
	
	sf::Vector2f poiston = sf::Vector2f();
	poiston.x = 500;

	for (int i = 0; i < clues->weapons.size(); i++)
	{
		poiston.x += 200;
		clues->weapons[i]->clueSprite->setPosition(poiston.x , 500);
		clues->weapons[i]->clueSprite->setOrigin(500,500);
		window->draw(*clues->weapons[i]->clueSprite);

		if (clues->weapons[i]->solution)
		{
		 	cout << "Answer: " << clues->weapons[i]->description << endl;
		}
	}

	highlight();
}

void Guess::displaySuspects()
{

	sf::Vector2f poiston = sf::Vector2f();
	poiston.x = 500;
	poiston.y = 800;

	for (int i = 0; i < clues->suspects.size(); i++)
	{
		poiston.x += 200;
		clues->suspects[i]->clueSprite->setPosition(poiston.x, 500);
		clues->suspects[i]->clueSprite->setOrigin(500, 500);
		window->draw(*clues->suspects[i]->clueSprite);
		if (clues->suspects[i]->solution)
		{
			cout << "Answer: " << clues->suspects[i]->description << endl;
		}
	}

	highlight();
}
void Guess::displayMotives()
{
	sf::Vector2f poiston = sf::Vector2f();
	poiston.x = 200;
	poiston.y = 800;

	for (int i = 0; i < clues->motives.size(); i++)
	{
		poiston.x += 200;
		clues->motives[i]->clueSprite->setPosition(poiston.x, 500);
		clues->motives[i]->clueSprite->setOrigin(500, 500);
		window->draw(*clues->motives[i]->clueSprite);
		if (clues->motives[i]->solution)
		{
			cout << "Answer: " << clues->motives[i]->description << endl;
		}
	}

	highlight();
}

void Guess:: highlight()
{
	if (guessSelctionState == 0)
	{
		for (int i = 0; i < maxNoOptions; i++)
		{
			clues->weapons[i]->clueSprite->setScale(.15, .15);
		}
		clues->weapons[itemSelected]->clueSprite->setScale(.30, .30);
	}
	if (guessSelctionState == 1)
	{
		for (int i = 0; i < maxNoOptions; i++)
		{
			clues->suspects[i]->clueSprite->setScale(.25, .25);
		}
		clues->suspects[itemSelected]->clueSprite->setScale(.50, .50);
	}
	if (guessSelctionState == 2)
	{
		for (int i = 0; i < maxNoOptions; i++)
		{
			clues->motives[i]->clueSprite->setScale(.25, .25);
		}
		clues->motives[itemSelected]->clueSprite->setScale(.50,.50);
	}

}

void Guess::moveLeft()
{
	if (itemSelected < maxNoOptions - 1)
	{
		itemSelected++;	
	}
	highlight();
}

void Guess::moveRight()
{
	if( itemSelected > 0)
	{
		itemSelected--;
	}
	
	highlight();
}

void Guess::popluateSelectedItemList()
{
	for (int i = 0; i < 3; i++)
	{
		selectedItemList.push_back(Clue());
	}
}

void Guess::itemSelcted()
{

	if (guessSelctionState == 0)
	{
		selectedItemList[0] = *clues->weapons[itemSelected];
	}

	if (guessSelctionState == 1)
	{
		selectedItemList[1] = *clues->suspects[itemSelected];
	}

	if (guessSelctionState == 2)
	{
		selectedItemList[2] = *clues->motives[itemSelected];
	}

	
}


//Draw selected items in the back sqaures location
void Guess::DrawSelectedItems()
{
	selectedItemList[0].clueSprite->setPosition(643, 175 );
	selectedItemList[0].clueSprite->setOrigin(80,2);
	selectedItemList[0].clueSprite->setScale(.25, .25);
	
	selectedItemList[1].clueSprite->setPosition(880,225 );
	selectedItemList[1].clueSprite->setOrigin(80,2);
	selectedItemList[1].clueSprite->setScale(.10, .10);

	selectedItemList[2].clueSprite->setPosition(1080, 225);
	selectedItemList[2].clueSprite->setOrigin(80, 2);
	selectedItemList[2].clueSprite->setScale(.10, .10);

	window->draw(*selectedItemList[0].clueSprite);
	window->draw(*selectedItemList[1].clueSprite);
	window->draw(*selectedItemList[2].clueSprite);
}

/*
	Asks the user if they wish to keep their current answer or reset based on N/Y
	Takes in a statemanager and use that to change states.
*/
void Guess::confirmAnswer(StateManager stateManager)
{
		confirmationText = "Are you sure with these answers?(Y/N)";
		tm->Render(window, frameCount, confirmationText);
		

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::N))
		{
			ResetAnswer();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y ))
		{
			guessSelctionState = 3;
			CheckAnswer(stateManager);
		}
}

/*
	Resets the players answer and stats the guess section again
*/
void Guess::ResetAnswer()
{
		answer = false;
		selectedItemList.clear();
		guessSelctionState = 0;	
}

/*
	Prints out text depending on if they user gets the answer right,wrong or partily right
	Next we reset the state for the time we enter guess again.
	Sleep used to ensure system waits for the player to press enter
*/
void Guess::CheckAnswer(StateManager stateManager)
{
	WinningText = "So you've solved the mystery";
	WrongText = "Sorry to say your wrong.Better luck next time";
	PartAnswer = "hmmm close. Your not entirely wrong. But not entirely right either";
	rightWeapon = "You guessed the right weapon";
	rightSuspect = "You guessed the right suspect";
	rightMotive = "You guessed the right motive";
	NoGuessesLeft = "Im afraid your time is up. I guess youll never know what happened to him";
	Sleep(100);

		if (selectedItemList[0].solution && selectedItemList[1].solution && selectedItemList[2].solution)//Right guess
		{
			displayText(WinningText);
			RightGuess = true;

		}
		else if (!selectedItemList[0].solution && !selectedItemList[1].solution && !selectedItemList[2].solution)//
		{
			displayText(WrongText);

			if (level >= 2)
			{
				Sleep(300);
				displayText(NoGuessesLeft);
				death = true;
			}
		}
		else
		{
			displayText(PartAnswer);
			Sleep(300);
			if (selectedItemList[0].solution)
			{
				displayText(rightWeapon);
			}
			Sleep(300);
			if (selectedItemList[1].solution)
			{
				displayText(rightSuspect);
			}
			Sleep(300);
			if (selectedItemList[2].solution)
			{
				displayText(rightMotive);
			}
		
		}
	GuessCompleted = true;
	level++;
	ResetAnswer();
}

/*
	The mysterious figure will say different text depending on the level the player is in
*/
void Guess::LevelSpeech()
{
	if (level == 0)
	{
		levelSpeech = "Aw so you've made it to the first room. Think youve solved it alright. We will see.";
	}
	else if (level == 1)
	{
		levelSpeech = "Hopefully you've learned more since we last meet";
	}
	
	else if (level == 2)
	{
		levelSpeech = "This is your last chance. Fail this time and youll never escape here.";
	}
	
	tm->Render(window, frameCount, levelSpeech);
}

/*
	Takes in a string that will use the textmanager to display text on the screne until the player enters Return
*/
void Guess::displayText(string path)
{
	while (!sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
	{
		tm->Render(window, frameCount, path);
		window->display();
	}
}

/*
	Resets the clue scale so that they fit in the inventory system after the player returns to play state.
*/
void Guess::ResetClueScale()
{
	for (int i = 0; i < clues->weapons.size(); i++)
	{
		clues->weapons[i]->clueSprite->setScale(1,1);
		clues->weapons[i]->clueSprite->setOrigin(300,300);

	}
	for (int i = 0; i < clues->suspects.size(); i++)
	{
		clues->suspects[i]->clueSprite->setScale(1, 1);
		clues->suspects[i]->clueSprite->setOrigin(300, 300);
	}
	for (int i = 0; i < clues->motives.size(); i++)
	{
		clues->motives[i]->clueSprite->setScale(1, 1);
		clues->motives[i]->clueSprite->setOrigin(300, 300);
	}

	speechSaid = false;
}