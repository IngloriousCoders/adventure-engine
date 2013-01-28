#ifndef _LAYER_H_
#define _LAYER_H_

#include <rapidxml.hpp>
#include <SDL/SDL.h>

#include "asset.hpp"

namespace Adventure
{
	class Layer
	{
		public:
			Layer(Asset* background,int zindex);
			
			SDL_Surface* getSurface();
			
			void setZIndex(int zindex);
			int  getZIndex();
			
			Asset *mBackground;
						
		private:
			int mZIndex;
			
			
		
	};
}


#endif // _LAYER_H_
