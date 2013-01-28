#include "layer.hpp"


namespace Adventure
{
		Layer::Layer(Asset* background,int zindex)
		{
			this->mBackground = background;
			this->mZIndex = zindex;
		}
			
		SDL_Surface* Layer::getSurface()
		{
			return this->mBackground->getSurface();
		}
			
		void Layer::setZIndex(int zindex)
		{
			this->mZIndex = zindex;
		}
		int  Layer::getZIndex()
		{
			return this->mZIndex;
		}
	
}
