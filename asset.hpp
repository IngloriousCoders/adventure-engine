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
				Asset(char* path,bool autoload=false);
				~Asset();
				
				char* getPath();
				char* setPath(char* _path);
				
				virtual SDL_Surface* getSurface();
				
				bool isLoaded();
				
				void load();
				
			private:
				
				char* mPath;
				
				bool autoload;
				bool loaded;
				
				SDL_Surface* mSurface;
				
				
		};
}


#endif // _ASSET_H_
