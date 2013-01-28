#ifndef _ANIMATION_ASSET_H_
#define _ANIMATION_ASSET_H_

#include <rapidxml.hpp>
#include <SDL/SDL.h>

#include <asset.hpp>

namspace Adventure
{
	class AnimationAsset : public Asset
	{
		public:
			AnimationAsset();
		
			SDL_Surface* getSurface();
		private:
			
	}	
	
}



#endif // _ANIMATION_ASSET_H_
