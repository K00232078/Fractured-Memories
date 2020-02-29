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

#ifndef SOUNDMANAGER_H
#define SOUNDMANAGER_H
#include <SFML/Audio.hpp>


using namespace std;
class SoundManager {
public:
	vector<sf::SoundBuffer*> audios;
	vector<string> lookup;
	SoundManager();
	~SoundManager();
	sf::SoundBuffer* SetAudio(string path);

	sf::SoundBuffer* GetAudio(int id);
	sf::SoundBuffer* GetAudio(string path);
	int AudioExist(string path);
};

#endif // !SPRITEMANAGER_H
