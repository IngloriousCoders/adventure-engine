#ifndef _ADVENTURE_STAGE_H_
#define _ADVENTURE_STAGE_H_

#include <rapidxml.hpp>
#include <SDL/SDL.h>

#include <vector>
#include <iostream>

#include <math.h>

#include "layer.hpp"



namespace Adventure
{

	class Stage
	{
			public:
				Stage(char* id,int width,int height);
				~Stage();
								
				SDL_Surface* getSurface();
				
				SDL_Rect* getSDLSize();
				
				int getWidth();
				int getHeight();
				
				void setCameraPosition(int cameraPosition);
				int getCameraPosition();
				
				int getMaxDepth();
				
				void setDepth( double depth );
				int getDepth( );
				
				void addLayer( Layer* layer );
				
				void redraw();
							
			private:
				char* id;
				
				std::vector<Layer*> mLayers;
				
				Layer* mBackgroundLayer;
				SDL_Surface mBackgroundSurfaceClean;
				
				SDL_Surface* mSurface;
				
				static const int mCameraAngle = 30;
				int mCameraPosition;
				int mDepth;
				int mMaxDepth;
				
				int mWidth;
				int mHeight;
				
				SDL_PixelFormat _format;

	};

}

#endif // _ADVENTURE_STAGE_H_
