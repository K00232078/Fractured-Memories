#include <SFML/Graphics.hpp>
#include "ClueManager.h"


#ifndef INVENTORY_VIEWER
#define INVENTORY_VIEWER

class InventoryViewer
{
public:
	InventoryViewer();
	InventoryViewer(ClueManager* clueManager);
	void Draw(sf::RenderWindow* window);
	void InitialisePositions();
	void CheckCheckedClues();
private:
	float spriteSize;
	ClueManager* clueManager;
	sf::RectangleShape backing;
};

#endif // !INVENTORY_VIEWER
