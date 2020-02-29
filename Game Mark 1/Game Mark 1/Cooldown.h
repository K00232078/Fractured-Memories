#ifndef COOLDOWN
#define COOLDOWN
class Cooldown
{
public:
	bool active = false;
	int current = 100, max = 100;
	
	Cooldown(int time);
	Cooldown();

	void Tick();
private:
	void Reset();

};
#endif // !COOLDOWN
