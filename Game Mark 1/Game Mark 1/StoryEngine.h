#include <vector>
#include <string>
#include <iostream>
using namespace std;

#ifndef STORY_ENGINE
#define STORY_ENGINE

class StoryEngine
{
public:
	StoryEngine();
	std::vector<std::string> openingScene;

	int state = 0;


private:
	void populateVectors();
	void populateOpeningScene();
};

#endif // !STORY_ENGINE

