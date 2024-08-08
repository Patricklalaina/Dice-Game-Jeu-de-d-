#ifndef LUDO_H
# define LUDO_H

# include <SDL2/SDL.h>
# include <SDL2/SDL_image.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

# define SCREEN_WIDTH 800
# define SCREEN_HEIGHT 800

typedef struct s_objet
{
	SDL_Surface	*src[6];
	SDL_Texture	*de[6];
	SDL_Rect	pos;
}	t_objet;

typedef struct s_data
{
	SDL_Window		*window;
	SDL_Renderer	*render;
	t_objet			de;
	SDL_Event		event;
}	t_data;

#endif