/*
** Last Author: Elijah
** Date Modified: 09/01/20
** Version: 0.001
** Change Log:
*** -------- <09/01/20>
***	<Elijah> Created File
***	<Elijah> Added Signiature Head
*** --------- End of Changes
*/

#include "SoundManager.h"

SoundManager::SoundManager()
{

}

SoundManager::~SoundManager()
{
	for (int i = 0; i < audios.size(); i++)
	{
		delete[] audios[i];
	}
}

sf::SoundBuffer* SoundManager::SetAudio(string path)
{
	sf::SoundBuffer* audio;
	//create a new one
	audio = new sf::SoundBuffer();
	audio->loadFromFile(path);

	//and add it to the lists
	audios.push_back(audio);
	lookup.push_back(path);
	return audio;
}

sf::SoundBuffer* SoundManager::GetAudio(string path)
{ //DONT PUT IN THE WRONG PATH FFS!
	sf::SoundBuffer* audio;
	audio = nullptr;
	if (AudioExist(path) == -1)
	{//if it doesn't exist
		audio = SetAudio(path);
	}
	else
	{//if it does exist
		audio = audios[AudioExist(path)];
	}
	return audio;
}

int SoundManager::AudioExist(string path)
{
	int returnValue = -1;
	for (int i = 0; i < lookup.size(); i++)
	{
		if (lookup[i].compare(path) == 0)
		{//compare returns 0 if two strings are the same
			returnValue = i; //returning the index of the sprite
		}
	}
	return returnValue;
}
