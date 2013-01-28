/*Beginn des Abenteuers... Adventure... -.-
 * TODO:
 * -schön butterweiches hin- und herscrollen 
 */

#include <rapidxml.hpp>
#include <SDL/SDL.h>

#include <iostream>

#include <math.h>

#include "stage.hpp"

bool quit = false;

Adventure::Stage* mainStage;
SDL_Surface *window;

int pos = 0;

bool left_pressed = false;
bool right_pressed = false;


void drawStage()
{
	if (left_pressed)
	{
		mainStage->setCameraPosition(mainStage->getCameraPosition()+1);
	}
	else if (right_pressed)
	{
		mainStage->setCameraPosition(mainStage->getCameraPosition()-1);
	}
	
		
	mainStage->redraw();
	
	SDL_BlitSurface(mainStage->getSurface(),0,window,0);
	
	SDL_UpdateRect(window, 0, 0, 1024, 768);
}
void handleKeyDown( SDL_Event* event )
{
	switch (event->key.keysym.sym)
	{
		case SDLK_LEFT:
		{
			left_pressed = true;
			break;
		}
		case SDLK_RIGHT:
		{
			right_pressed = true;
			break;
		}
		default:
		{
			break;
		}
	}
}
void handleKeyUp( SDL_Event* event )
{
	switch (event->key.keysym.sym)
	{
		case SDLK_LEFT:
		{
			left_pressed = false;
			break;
		}
		case SDLK_RIGHT:
		{
			right_pressed = false;
			break;
		}
		case SDLK_ESCAPE:
		{
			quit = true;
			break;
		}
		default:
		{
			break;
		}
	}
}
void pollEvents()
{
	SDL_Event event;
	
	while ( SDL_PollEvent( &event ) )
	{
		switch ( event.type )
		{
			case SDL_QUIT:
			{
				quit = true;
				break;
			}
			case SDL_KEYDOWN:
			{
				handleKeyDown(&event);
				break;
			}
			case SDL_KEYUP:
			{
				handleKeyUp(&event);
				break;
			}
			default:
				break;
		}	
	}
}


int main (int argc, char** argv)
{
	
	
	
	window = 0;
	
	if ( SDL_Init ( SDL_INIT_EVERYTHING )  < 0 )
	{
		std::cout << "Fehler beim initialisieren der SDL-Bibliothek: " << SDL_GetError() << std::endl;
		exit(1);
	}	
	
	
	
	
	window = SDL_SetVideoMode(1024, 768, 24, SDL_SWSURFACE);
	
	SDL_EnableUNICODE( 1 );
	
	
	//Setup Stage
	using namespace Adventure;
	
	
	// Erstellen einer Stage mit id="start" und Höhe und Breite
	mainStage = new Adventure::Stage("start",1024,768);
	
	// Setzen der Kameraposition auf Anfang
	mainStage->setCameraPosition(0);
	
	
	// Initialisieren der Assets. Alle auf autoload=true;
	Asset* image_horizont = new Asset("game.ap/assets/horizont.png",true);
	Asset* image_kerze = new Asset("game.ap/assets/kerze.png",true);
	Asset* image_kiste = new Asset("game.ap/assets/kiste.png",true);
	Asset* image_buehne = new Asset("game.ap/assets/buehne.png",true);
	
	// Initialisieren der Layer	
	Layer* horizont = new Layer(image_horizont,-1);
	Layer* kerze = new Layer(image_kerze,8);
	Layer* buehne = new Layer(image_buehne,1);
	Layer* kiste = new Layer(image_kiste,1);
	
	
	mainStage->addLayer(horizont);
	mainStage->addLayer(kerze);
	mainStage->addLayer(buehne);
	mainStage->addLayer(kiste);
	
	
	if ( window == 0 )
	{
		std::cout << "Fehler beim Öffnen des SDL-Fensters: " <<  SDL_GetError() << std::endl;
		exit(1);
	}
		
	if (mainStage->getSurface() == 0 )
	{
		std::cout << "Fehler beim Darstellen der Hauptbuehne" << std::endl;
		exit(1);
	}
		
	while ( !quit )
	{
		pollEvents();
		drawStage();
		
		SDL_Flip(window);
		SDL_Delay(1000/120);
	}
	
	
	SDL_FreeSurface(window);
	
	SDL_Quit();
	

	
	return 0;
}

