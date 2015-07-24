#pragma once
#include <stdio.h>
#include <SDL_mixer.h>
class Audio
{
public:
	Audio(void);
	~Audio(void);

	enum Type
	{
		EFFECT,
		MUSIC
	};

	
	void Load_Audio(char* file_name , Type type);

	void Play_Audio();

	void Set_Audio_Volume(int Vol);

	void Pause_Music();

	void Resume_Music();

private:
	bool Initialize_AudioSystem();

	Mix_Music *Music;
	Mix_Chunk *Effect;
	Type _typ;
};

