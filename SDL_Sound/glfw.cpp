// Include standard headers
#include <stdio.h>
#include <stdlib.h>
#include <GL/glew.h>
#include <GL/glfw3.h>
#include <SDL_mixer.h>
#include <glm/glm.hpp>
using namespace glm;

#include "Audio.h"



//The music that will be played
Audio *back_Soound;

Audio *effect1;
Audio *effect2;
Audio *effect3;
Audio *effect4;


void load_media()
{

	back_Soound->Load_Audio("Forest.mp3",back_Soound->MUSIC);

	effect1->Load_Audio("scratch.wav",effect1->EFFECT);
	effect2->Load_Audio("high.wav",effect2->EFFECT);
	effect3->Load_Audio("medium.wav",effect3->EFFECT);
	effect4->Load_Audio("low.wav",effect4->EFFECT);

}

void init()
{
	back_Soound = new Audio();

	effect1 = new Audio();
	effect2 = new Audio();
	effect3 = new Audio();
	effect4 = new Audio();

	load_media();
}
int volume = 1;
int main()
{

	printf("BackGround Sound is 3D Sound...!! \n");
	printf("press 1 to 4  for playing effects ...!!! \n");


	// Initialise GLFW
	if( !glfwInit() )
	{
		fprintf( stderr, "Failed to initialize GLFW\n" );
		return -1;
	}

	glfwWindowHint(GLFW_SAMPLES, 4); // 4x antialiasing
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // We want OpenGL 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); //We don't want the old OpenGL 

	// Open a window and create its OpenGL context 
	GLFWwindow* window; // (In the accompanying source code, this variable is global) 
	window = glfwCreateWindow( 500, 500, "Tutorial 01", NULL, NULL); 
	if( window == NULL ){
		fprintf( stderr, "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n" );
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window); // Initialize GLEW 
	glewExperimental=true; // Needed in core profile 
	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Failed to initialize GLEW\n");
		return -1;
	}

	// Ensure we can capture the escape key being pressed below
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);


	init();
	//main loop..
	bool once = true;
	do
	{
		// Draw nothing, see you in tutorial 2 !


		if(glfwGetKey(window, GLFW_KEY_1 ))
		{
			effect1->Play_Audio();
		}

		if(glfwGetKey(window, GLFW_KEY_2 ))
		{
			effect2->Play_Audio();
		}

		if(glfwGetKey(window, GLFW_KEY_3 ))
		{
			effect3->Play_Audio();
		}

		if(glfwGetKey(window, GLFW_KEY_4 ))
		{
			effect4->Play_Audio();
		}

		if(once == true )
		{
			//Play the music
			back_Soound->Play_Audio();
			once = false;
		}

		if(glfwGetKey(window, GLFW_KEY_SPACE ))
		{
			back_Soound->Pause_Music();
		}
		if(glfwGetKey(window, GLFW_KEY_S ))
		{
			back_Soound->Resume_Music();
		}




		// Swap buffers
		glfwSwapBuffers(window);
		glfwPollEvents();
	} // Check if the ESC key was pressed or the window was closed
	while( glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS && glfwWindowShouldClose(window) == 0 );

}