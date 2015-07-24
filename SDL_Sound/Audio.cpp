#include "Audio.h"


Audio::Audio(void)
{
	Initialize_AudioSystem();
}


Audio::~Audio(void)
{
	Mix_FreeChunk(Effect);
	Mix_FreeMusic(Music);
	Mix_CloseAudio();
}

bool Audio::Initialize_AudioSystem()
{ 
	Music = NULL;
	Effect = NULL;

	/*freq,format,channels,chuncksize*/
	//Initialize SDL_mixer  /* freq = 44100*/  channels = 2 = Stereo.
	if( Mix_OpenAudio(MIX_DEFAULT_FREQUENCY * 2, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
	{
		printf( "Audio System Couldn't Initialize,, SDL_mixer Error: %s\n", Mix_GetError() );
		return false;
	}
	return true;
}

void Audio::Pause_Music()
{
	Mix_PauseMusic();
}

void Audio::Resume_Music()
{
	Mix_ResumeMusic();
}

void Audio::Load_Audio(char* file_name , Type type)
{
	_typ = type;


	if(type == Type::EFFECT)
	{
		/*
		load effects only wav format..
		*/
		Effect = Mix_LoadWAV(file_name);     //<<-----sound effect to load ...
		if( Effect == NULL )
		{
			printf( "Failed to load sound effect! Error: %s\n", Mix_GetError() );
		}

	}


	/*
	load music load any file format but play this sound with infinite loop..
	*/
	if(type == Type::MUSIC)
	{
		//Load music
		Music = Mix_LoadMUS(file_name);    //<<-----music to load ...
		if( Music == NULL )
		{
			printf( "Failed to load music! Error: %s\n", Mix_GetError() );
		}
	}

}

void Audio::Play_Audio()
{
	if(_typ == Type::EFFECT)
	{
		Mix_PlayChannel( -1, Effect, 0);
	}

	if(_typ == Type::MUSIC)
	{
		Mix_PlayMusic(Music , -1);
	}

}

/*volume range from 0 to 128*/
void Audio::Set_Audio_Volume(int Vol)
{
	if(_typ == Type::EFFECT)
	{
		Mix_VolumeChunk(Effect,Vol);
	}

	if(_typ == Type::MUSIC)
	{
		Mix_VolumeMusic(Vol);
	}
}





