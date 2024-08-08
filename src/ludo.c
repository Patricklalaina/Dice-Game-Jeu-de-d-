#include "../include/ludo.h"

void	init_data(t_data *game)
{
	if (SDL_Init(SDL_INIT_VIDEO))
	{
		printf("failed to initialize SDL\n");
		exit(1);
	}
	IMG_Init(IMG_INIT_PNG);
	game->window = SDL_CreateWindow("Jeu de Dé V0.0",
									SDL_WINDOWPOS_CENTERED,
									SDL_WINDOWPOS_CENTERED,
									SCREEN_WIDTH,
									SCREEN_HEIGHT,
									0);
	if (!game->window)
	{
		printf("failed to create window\n");
		SDL_Quit();
		exit(1);
	}
	game->render = SDL_CreateRenderer(game->window, -1, 0);
	if (!game->render)
	{
		printf("Fail to create render\n");
		SDL_DestroyWindow(game->window);
		IMG_Quit();
		SDL_Quit();
		exit (1);                                                                                                                                                                                                         
	}
}

void 	init_de(t_data *game)
{
	int	i;

	game->de.pos.h = 400;
	game->de.pos.w = 400;
	game->de.pos.x = (SCREEN_WIDTH - 400) / 2;
	game->de.pos.y = (SCREEN_HEIGHT - 400) / 2;
	game->de.src[0] = IMG_Load("./assets/1.png");
	game->de.src[1] = IMG_Load("./assets/2.png");
	game->de.src[2] = IMG_Load("./assets/3.png");
	game->de.src[3] = IMG_Load("./assets/4.png");
	game->de.src[4] = IMG_Load("./assets/5.png");
	game->de.src[5] = IMG_Load("./assets/6.png");
	i = -1;
	while (6 > ++i)
		game->de.de[i] = SDL_CreateTextureFromSurface(game->render, game->de.src[i]);
}

int	main(void)
{
	int		res;
	int		count;
	t_data	game;
	int		run;

	run = 1;
	res = 0;
	count = 0;
	init_data(&game);
	init_de(&game);
	while (run)
	{
		if (36 > count)
		{
			res = random() % 6;
			count++;
		}
		SDL_SetRenderDrawColor(game.render, 37, 27, 37, 255);
		while (SDL_PollEvent(&game.event))
		{
			if (game.event.type == SDL_QUIT)
			{
				run = 0;
				break ;
			}
			else if (game.event.type == SDL_KEYDOWN)
			{
				if (game.event.key.keysym.sym == SDLK_SPACE)
					count = 0;

			}
		}
		SDL_RenderCopy(game.render, game.de.de[res], NULL, &game.de.pos);
		SDL_RenderPresent(game.render);
		SDL_RenderClear(game.render);
		usleep(150000);
	}
	SDL_DestroyRenderer(game.render);
	SDL_DestroyWindow(game.window);
	IMG_Quit();
	SDL_Quit();
	return (0);
}