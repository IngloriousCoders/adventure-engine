/* 
 * Ein Asset ist alles auf einer Stage. Jedes Bild, jede Animation. 
 * Später möglicherweise auch jeder Sound. 
 * TODO:
 * 
 * */

#ifndef _ASSET_H_
#define _ASSET_H_

#include <rapidxml.hpp>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

namespace Adventure
{
		class Asset
		{
			public:
				Asset(char* path,bool autoload=false); // Pfad zur Datei, und autoload gibt an ob das Asset sofort in den RAM geladen werden soll.
				~Asset();
				
				char* getPath(); // Gibt den Pfad zurück
				char* setPath(char* _path); // Im Grunde nutzlos, wenn man nach Änderung nicht erneut Asset::load() aufruft
				
				virtual SDL_Surface* getSurface(); // Intern benutzt, gibt das SDL_Surface zurück, dass das Bild abbildet
				
				bool isLoaded(); // Ist dieses Asset bereits im RAM ?
				
				void load(); // Lädt die Datei von Pfad und stellt sie unter private Asset::mSurface bereit
				
			private:
				
				char* mPath;
				
				bool autoload;
				bool loaded;
				
				SDL_Surface* mSurface;
				
				
		};
}


#endif // _ASSET_H_
