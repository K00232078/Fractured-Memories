#include <SFML/Graphics.hpp>
#ifndef EVENT_HANDLER
#define EVENT_HANDLER

class EventHandler
{
public:
	EventHandler();
	void HandleEvent(sf::Event event);
};

#endif // !EVENT_HANDLER

