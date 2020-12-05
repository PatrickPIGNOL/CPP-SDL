/*
 * main.cpp
 *
 *  Created on: 30 août 2019
 *      Author: patrick
 */
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <stdlib.h>
#include "String.h"


int main(int argc, char** argv)
{
	/* Initialisation simple */
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		/* Création de la fenêtre */
		SDL_Window* pWindow = NULL;
		pWindow = SDL_CreateWindow
		(
			"Test",
			SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED,
			640,
			480,
			SDL_WINDOW_SHOWN
		);
		if( pWindow )
		{
			SDL_Renderer* vSDLRenderer = SDL_CreateRenderer(pWindow, -1, 0);
			if(vSDLRenderer)
			{
				int vRed = 0;
				int vGreen = 0;
				int vBlue = 0;
				bool vRedTop = false;
				bool vGreenTop = false;
				bool vBlueTop = false;
				int vRedAdd = 0;
				int vGreenAdd = 0;
				int vBlueAdd = 0;
				bool vContinue = true;
				NFramework::String vTexte;
				vTexte = "(nothing happened)";
				SDL_Point vMouse = {0,0};

				while(vContinue)
				{
					SDL_Event e;
					if(SDL_PollEvent(&e))
					{
						switch(e.type)
						{
							case SDL_QUIT :
							{
								vContinue = false;
							}break;

							case SDL_MOUSEMOTION:
							{

								int vX = e.motion.x;
								int vY = e.motion.y;
								vMouse.x = e.motion.x;
								vMouse.y = e.motion.y;
								vTexte = "Window ";
								vTexte += NFramework::String::mToString(vX);
								vTexte += "-";
								vTexte += NFramework::String::mToString(vY);
								SDL_Log("%s", vTexte.mToCString());
							}break;

							case SDL_WINDOWEVENT:
							{
								switch (e.window.event)
								{
									case SDL_WINDOWEVENT_SHOWN:
									{
										vTexte = "Window ";
										vTexte += NFramework::String::mToString(e.window.windowID);
										vTexte += " shown";
										SDL_Log("%s", vTexte.mToCString());
									}break;
									case SDL_WINDOWEVENT_HIDDEN:
									{
										vTexte = "Window ";
										vTexte += NFramework::String::mToString(e.window.windowID);
										vTexte += " hidden";
										SDL_Log("%s", vTexte.mToCString());
									}break;
									case SDL_WINDOWEVENT_EXPOSED:
									{
										vTexte = "Window ";
										vTexte += NFramework::String::mToString(e.window.windowID);
										vTexte += " exposed";
										SDL_Log("%s", vTexte.mToCString());
									}break;
									case SDL_WINDOWEVENT_MOVED:
									{
										vTexte = "Window ";
										vTexte += NFramework::String::mToString(e.window.windowID);
										vTexte += " exposed";
										SDL_Log("%s", vTexte.mToCString());
									}break;
									case SDL_WINDOWEVENT_RESIZED:
									{
										vTexte = "Window ";
										vTexte += NFramework::String::mToString(e.window.windowID);
										vTexte += " resized to ";
										vTexte += NFramework::String::mToString(e.window.data1);
										vTexte += ",";
										vTexte += NFramework::String::mToString(e.window.data2);
										SDL_Log("%s", vTexte.mToCString());
									}
									break;
									case SDL_WINDOWEVENT_SIZE_CHANGED:
									{
										vTexte = "Window ";
										vTexte += NFramework::String::mToString(e.window.windowID);
										vTexte += " size changed to ";
										vTexte += NFramework::String::mToString(e.window.data1);
										vTexte += "x";
										vTexte += NFramework::String::mToString(e.window.data2);
										SDL_Log("%s", vTexte.mToCString());
									}break;
									case SDL_WINDOWEVENT_MINIMIZED:
									{
										vTexte = NFramework::String("Window ");
										vTexte += NFramework::String::mToString(e.window.windowID);
										vTexte += " minimized";
										SDL_Log("%s", vTexte.mToCString());
									}break;
									case SDL_WINDOWEVENT_MAXIMIZED:
									{
										vTexte = NFramework::String("Window ");
										vTexte += NFramework::String::mToString(e.window.windowID);
										vTexte += " maximized";
										SDL_Log("%s", vTexte.mToCString());
									}break;
									case SDL_WINDOWEVENT_RESTORED:
									{
										vTexte = NFramework::String("Window ");
										vTexte += NFramework::String::mToString(e.window.windowID);
										vTexte += " restored";
										SDL_Log("%s", vTexte.mToCString());
									}break;
									case SDL_WINDOWEVENT_ENTER:
									{
										vTexte = NFramework::String("Window entered window ");
										vTexte += NFramework::String::mToString(e.window.windowID);
										SDL_Log("%s", vTexte.mToCString());
									}break;
									case SDL_WINDOWEVENT_LEAVE:
									{
										vTexte = NFramework::String("Window");
										vTexte += NFramework::String::mToString(e.window.windowID);
										vTexte += "left window ";
										SDL_Log("%s", vTexte.mToCString());
									}break;
									case SDL_WINDOWEVENT_FOCUS_GAINED:
									{
										vTexte = NFramework::String("Window ");
										vTexte += NFramework::String::mToString(e.window.windowID);
										vTexte += " gained keyboard focus";
										SDL_Log("%s", vTexte.mToCString());
									}break;
									case SDL_WINDOWEVENT_FOCUS_LOST:
									{
										vTexte = NFramework::String("Window ");
										vTexte += NFramework::String::mToString(e.window.windowID);
										vTexte += " lost keyboard focus";
										SDL_Log("%s", vTexte.mToCString());
									}break;
									case SDL_WINDOWEVENT_CLOSE:
									{
										vTexte = NFramework::String("Window ");
										vTexte += NFramework::String::mToString(e.window.windowID);
										vTexte += " closed";
										SDL_Log("%s", vTexte.mToCString());
									}break;

									#if SDL_VERSION_ATLEAST(2, 0, 5)

									case SDL_WINDOWEVENT_TAKE_FOCUS:
									{
										vTexte = NFramework::String("Window ");
										vTexte += NFramework::String::mToString(e.window.windowID);
										vTexte += " is offered a focus";
										SDL_Log("%s", vTexte.mToCString());
									}break;
									case SDL_WINDOWEVENT_HIT_TEST:
									{
										vTexte = NFramework::String("Window ");
										vTexte += NFramework::String::mToString(e.window.windowID);
										vTexte += " has a special hit test";
										SDL_Log("%s", vTexte.mToCString());
									}break;

									#endif

									default:
									{
										vTexte = NFramework::String("Window ");
										vTexte += NFramework::String::mToString(e.window.windowID);
										vTexte += " got unknown event (type = ";
										vTexte += NFramework::String::mToString(e.type) + ")";
										SDL_Log("%s", vTexte.mToCString());
									}break;
								}
							}
						}
					}

					//SDL_Delay(10);
					SDL_SetRenderDrawColor(vSDLRenderer, vRed, vGreen, vBlue, 255);

					vRed += vRedAdd;
					vGreen += vGreenAdd;
					vBlue += vBlueAdd;

					if(!vRedTop && !vGreenTop && !vBlueTop && (vRed == 0) && (vGreen == 0) && (vBlue == 0))
					{
						vRedAdd = 1;
					}
					if(!vRedTop && !vGreenTop && !vBlueTop && (vRed >= 255) && (vGreen == 0) && (vBlue == 0))
					{
						vRed = 255;
						vRedAdd = 0;
						vRedTop = true;
						vGreenAdd = 1;
					}
					if(vRedTop && !vGreenTop && !vBlueTop && (vRed == 255) && (vGreen >= 255) && (vBlue == 0))
					{
						vGreen = 255;
						vGreenAdd = 0;
						vGreenTop = true;
						vRedAdd = -1;
					}
					if(vRedTop && vGreenTop && !vBlueTop && (vRed <= 0) && (vGreen == 255) && (vBlue == 0))
					{
						vRed = 0;
						vRedAdd = 0;
						vRedTop = false;
						vBlueAdd = 1;
					}
					if(!vRedTop && vGreenTop && !vBlueTop && (vRed == 0) && (vGreen == 255) && (vBlue >= 255))
					{
						vBlue = 255;
						vBlueAdd = 0;
						vBlueTop = true;
						vGreenAdd = -1;
					}
					if(!vRedTop && vGreenTop && vBlueTop && (vRed == 0) && (vGreen <= 0) && (vBlue == 255))
					{
						vGreen = 0;
						vGreenAdd = 0;
						vGreenTop = false;
						vRedAdd = 1;
					}
					if(!vRedTop && !vGreenTop && vBlueTop && (vRed >= 255) && (vGreen == 0) && (vBlue == 255))
					{
						vRed = 255;
						vRedAdd = 0;
						vRedTop = true;
						vGreenAdd = 1;
					}
					if(vRedTop && !vGreenTop && vBlueTop && (vRed == 255) && (vGreen >= 255) && (vBlue == 255))
					{
						vGreen = 255;
						vGreenAdd = 0;
						vGreenTop = true;
						vRedAdd = -1;
						vGreenAdd = -1;
						vBlueAdd = -1;
					}
					if(vRedTop && vGreenTop && vBlueTop && (vRed <= 0) && (vGreen <= 0) && (vBlue <= 0))
					{
						vRed = 0;
						vGreen = 0;
						vBlue = 0;
						vRedAdd = 0;
						vGreenAdd = 0;
						vBlueAdd = 0;
						vRedTop = false;
						vGreenTop = false;
						vBlueTop = false;
					}
					SDL_RenderClear(vSDLRenderer);
					if(TTF_Init() == 0)
					{
						TTF_Font* vFont = TTF_OpenFont("Fonts/ka1.ttf", 16);
						if(vFont)
						{
							SDL_Color vColor = {0, 0, 0};
							SDL_Surface* vText = TTF_RenderText_Blended(vFont, vTexte.mToCString(), vColor);
							SDL_Texture* vTexture = SDL_CreateTextureFromSurface(vSDLRenderer, vText);
							SDL_Rect vRect;
							vRect.x = 0;
							vRect.y = 0;
							vRect.h = vText->h;
							vRect.w = vText->w;
							SDL_RenderCopy(vSDLRenderer, vTexture, NULL, &vRect);

							if(!(IMG_Init(IMG_INIT_PNG + IMG_INIT_JPG) & (IMG_INIT_PNG + IMG_INIT_JPG)))
							{
								printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
								return 0;
							}
							else
							{
								SDL_Surface* vImage = IMG_Load("Images/image.png");
								if(!vImage)
								{
									printf("Erreur de chargement de l'image : %s",SDL_GetError());
									return -1;
								}
								SDL_Texture* vImageTexture = SDL_CreateTextureFromSurface(vSDLRenderer, vImage);

								SDL_Rect vImageRect;
								vImageRect.x = vMouse.x;
								vImageRect.y = vMouse.y;
								vImageRect.h = vImage->h;
								vImageRect.w = vImage->w;
								SDL_RenderCopy(vSDLRenderer, vImageTexture, NULL, &vImageRect);

								SDL_DestroyTexture(vImageTexture);
								SDL_FreeSurface(vImage);
							}

							SDL_DestroyTexture(vTexture);
							SDL_FreeSurface(vText);
							TTF_CloseFont(vFont);
						}
						else
						{
							fprintf(stderr,"Erreur de création de la police: %s\n", TTF_GetError());
						}
					}
					TTF_Quit();
					SDL_RenderPresent(vSDLRenderer);
				}
			}
			else
			{
				fprintf(stderr,"Erreur de création du renderer: %s\n",SDL_GetError());
			}
			SDL_DestroyWindow(pWindow);
			SDL_DestroyRenderer(vSDLRenderer);
		}
		else
		{
			fprintf(stderr,"Erreur de création de la fenêtre: %s\n",SDL_GetError());
		}
		SDL_Quit();
	}
	else
	{
		fprintf(stdout,"Échec de l'initialisation de la SDL (%s)\n",SDL_GetError());
		return -1;
	}
	return 0;
}
