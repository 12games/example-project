#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <glad/glad.h>

#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>

#include <bullet/BulletDynamics/btBulletDynamicsCommon.h>

int main(int argc, char* argv[])
{
    btVector3 v;
    SDL_Window* window; // Declare a pointer
    SDL_GLContext context;

    SDL_Init(SDL_INIT_VIDEO); // Initialize SDL2

    // Create an application window with the following settings:
    window = SDL_CreateWindow(
        "An SDL2 window", // window title
        SDL_WINDOWPOS_UNDEFINED, // initial x position
        SDL_WINDOWPOS_UNDEFINED, // initial y position
        640, // width, in pixels
        480, // height, in pixels
        SDL_WINDOW_OPENGL // flags - see below
    );

    // Check that the window was successfully created
    if (window == NULL) {
        // In the case that the window could not be made...
        printf("Could not create window: %s\n", SDL_GetError());
        return 1;
    }

    context = SDL_GL_CreateContext(window);
    if (context == 0)
    {
        printf("Unable to create GL context");
        return 2;
    }

    if (!gladLoadGL()) {
        printf("Something went wrong!\n");
        return 3;
    }

    /* This makes our buffer swap syncronized with the monitor's vertical refresh */
    SDL_GL_SetSwapInterval(1);

    /* Clear our buffer with a red background */
    glClearColor ( 1.0, 0.0, 0.0, 1.0 );
    glClear ( GL_COLOR_BUFFER_BIT );

    /* Swap our back buffer to the front */
    SDL_GL_SwapWindow(window);

    SDL_Delay(3000); // Pause execution for 3000 milliseconds, for example

    // Close and destroy the window
    SDL_DestroyWindow(window);

    // Clean up
    SDL_Quit();
    return 0;
}
