#include "stage.hpp"

namespace Adventure
{
		Stage::Stage(char* _id,int _width, int _height)
		{
			int len = strlen(_id);
			this->id = new char[len+1];
			strncpy(this->id,_id,len);
			this->id[len] = '\0';
			
			this->mDepth = 1000;
			
			this->mWidth = _width;
			this->mHeight = _height;
			
			
			
			SDL_Rect mFill;
			
			mFill.w = this->mWidth;
			mFill.h = this->mHeight;
			mFill.x = 0;
			mFill.y = 0;
			
			
		}			
		
		Stage::~Stage()
		{
			SDL_FreeSurface(this->mSurface);
		}
				
		SDL_Surface* Stage::getSurface()
		{
			return this->mSurface;
		}
		
	
		SDL_Rect* Stage::getSDLSize()
		{
			SDL_Rect* size = new SDL_Rect;
			
			size->x = 0;
			size->y = 0;
			size->w = this->mWidth;
			size->h = this->mHeight;
			return size;
		}
				
		void Stage::addLayer( Layer* layer )
		{
			this->mLayers.push_back(layer);
			if (layer->getZIndex() == -1)
			{
				this->mBackgroundLayer = layer;
				
				this->mBackgroundSurfaceClean = *layer->getSurface();
			}
		}
		
		void Stage::setCameraPosition( int _val)
		{
			this->mCameraPosition = _val;
		}
			
		int Stage::getCameraPosition()
		{
			return this->mCameraPosition;
		}
		int Stage::getMaxDepth()
		{
			return this->mMaxDepth;
		}
				
		void Stage::setDepth( double depth )
		{
			this->mDepth = depth;
		}
		int Stage::getDepth( )
		{
			return this->mDepth;
		}
		void Stage::redraw()
		{
			SDL_Surface* window = SDL_GetVideoSurface();
			
			SDL_PixelFormat* _format = window->format;
			
			SDL_PixelFormat *format = this->mBackgroundLayer->getSurface()->format;
			
			this->mSurface = SDL_CreateRGBSurface(SDL_SWSURFACE,1024,768,24,0,0,0,0);
			
			
			SDL_BlitSurface(this->mBackgroundLayer->getSurface(),0,this->mSurface,0);
			
			SDL_Flip(this->mSurface);
			
			
			int maxIndex = 20;
					
			for ( int i=0; i<maxIndex; i++ )
			{
				for ( std::vector<Layer*>::iterator it = this->mLayers.begin() ; it != this->mLayers.end(); ++it )
				{
					Layer* currentLayer = (*it);
					
					if ( i == currentLayer->getZIndex() )
					{
						int neg_position_x = 0.8*currentLayer->getZIndex()*(512-this->mCameraPosition);
							
						SDL_Rect calculated_position;
						calculated_position.x = neg_position_x;
						calculated_position.y = 0;
						
						calculated_position.w = currentLayer->getSurface()->w;
						calculated_position.h = currentLayer->getSurface()->h;
						
						SDL_BlitSurface(currentLayer->getSurface(),0,this->mSurface,&calculated_position);
					
					}
				}
			}
			SDL_UpdateRect(this->mSurface, 0, 0, 1024, 768);
			SDL_Flip(this->mSurface);
		}
}
