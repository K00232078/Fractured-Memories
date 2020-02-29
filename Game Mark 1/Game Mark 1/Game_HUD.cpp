/*
** Last Author: Elijah
** Date Modified: 29/11/19
** Version: 0.001
** Change Log:
*** -------- <29/11/19>
***	<Elijah> Added Signiature Head
***	<Elijah> Pulled Update into a Seperate file.
*** --------- End of Changes
*/

#include "Game.h"

sf::View Game::GameHUD(sf::View HUD, Player* p) {
	//Creating a view for the HUD
	HUD = View(sf::FloatRect(0, 0, resolution.x, resolution.y));
	window->setView(HUD);

	if (readingText)
	{
		//cout << "pop up active" << endl;
		textPopUp.Tick();
		textManager->Render(window, frameCount, pickedUp->description);
		//window->draw(*textManager);
	}

	//Players health
	Sprite* heart1 = spriteManager->GetSprite("Textures/heart.png");

	//powerups
	Sprite* powerup;

	//scaling the image
	heart1->setScale(.2,.2);

	float x = 10.f;
	float y = 5.f;
	int heartAmount = p->m_health;

	//Player heart postions
	for (int i = 0; i <= heartAmount; i++)
	{
		heart1->setPosition(x, y);
		window->draw(*heart1);
		x += 35.f;

		if (i% 9==0 && i!=0)
		{
			y += 35;
			x = 10;
		}
	}
	if (p->GetHit() == false)
	{
		heartAmount--;
	}

	Clock c;
	RectangleShape timeBar;
	float timebarstartingwidth = 60;
	float timebarheight = 35;
	timeBar.setSize(Vector2f(timebarstartingwidth, timebarheight));
	timeBar.setFillColor(Color::Blue);
	timeBar.setPosition(430, 10.f);
	Time gameTImetotal;
	float timeRemaining = 6.0f;
	float timeBarWidthPerSecond = timebarstartingwidth / timeRemaining;

	Time dt = c.restart();

	timeRemaining -= dt.asSeconds();

	/*if (pwup->m_Spawned == false)
	{
		powerup = spriteManager->GetSprite("Textures/heart_empty_16x16.png");
		powerup->setScale(2.f, 2.f);
		powerup->setPosition(395.f, 10.f);
		timeBar.setSize(Vector2f(timeBarWidthPerSecond * timeRemaining, timebarheight));
		
		if (timebarstartingwidth == 0)
		{
			powerup->setScale(0, 0);
		}
	}*/
	if (viewingInventory)
	{
		inventoryViewer->Draw(window);
	}

	//boss health
	float hp = p->m_health;
	sf::RectangleShape hpBar;
	hpBar.setFillColor(Color::Red);
	hpBar.setSize(Vector2f(hp * 5.f, 20.f));
	hpBar.setPosition(resolution.x / 2.5, 1060.f);
	window->draw(hpBar);

	return HUD;
}
