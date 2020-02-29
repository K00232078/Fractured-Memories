#include "Cooldown.h"

Cooldown::Cooldown(int time)
{
	max = time;
	current = time;
}

Cooldown::Cooldown()
{
	
}

void Cooldown::Tick()
{
	if (active)
	{
		current--;
		if (current <= 0)
		{
			Reset();
		}
	}
}

void Cooldown::Reset()
{
	active = false;
	current = max;
}