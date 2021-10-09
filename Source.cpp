/*===============================================
Game Loop
By Jack Partridge-1702918
=================================================*/

//Header files used
#include <iostream>
#include <ctime>
#include <Windows.h>
#include "glut.h"
#include "include\sdl2\SDL.h"

using namespace std;

//Global var
const double MS_TimeStep = 16;
int initTime = time(NULL);
int finalTime;
int frameCount = 0;

class GameObject
{
public:
	int object[5];

	void update()
	{
		for (int i = 0; i < 5; i++)
		{
			object[i] = 1 + i;
			cout << "This is Game object " <<
				object[i] << endl;
		}
	}
private:

};

//This is the game's state such as: velocities and positions
struct game_state {


};

//Handle the input devices
bool handle_input() {



	return false; //Set this to true if the user wants to quit
}

//Update the game's logic
void Update(game_state *) {
	//GameObject go;
	//go.update();

}

//Grapghics rendering is handled here
void Render(game_state const &) {

	//Draw inside here

}

// interpolate between previous and current
game_state interpolate(game_state const & current, game_state const & previous) {
	game_state interpolated_state;


	return interpolated_state;
}


//Main loop
int main(int argc, char** argv) {

	float lag = 0.0;
	double previousTime = GetTickCount();
	bool running = true;

	game_state current_state;
	game_state previous_state;

	//Game loop
	while (running)
	{
		double currentTime = GetCurrentTime();
		double elapsedTime = currentTime - previousTime;
		previousTime = currentTime;
		lag += elapsedTime;

		running = handle_input;

		//Update game logic as lag permits
		while (lag >= MS_TimeStep)
		{
			//Update at a fixed rate each time
			Update(&current_state);

			lag -= MS_TimeStep;
			previous_state = current_state;

			//Frame rate counter
			frameCount++;

			finalTime = time(NULL);

			if (finalTime - initTime >= 1) {
				cout << "Frames Per Seconds: " << frameCount
					/ (finalTime - initTime) << endl;
				//reset the frame count to reset the FPS.
				frameCount = 0;
				initTime = finalTime;
			}

		}

		auto interpolated_state = interpolate(current_state, previous_state);
		Render(interpolated_state);
	}
	return 0;
}
