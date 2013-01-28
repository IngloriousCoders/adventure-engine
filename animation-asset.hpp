/*
Diese Klasse erbt alle Eigenschaften eines normalen Assets, mit der Ausnahme,
* dass sie Bilder annimmt, auf denen nebeneinander angeordnet die verschiedenen Frames 
* einer Animation gespeichert sind. Bei jedem Frame soll sich dann der Bildausschnitt der unter AnimationAsset::getSurface() zurückgegeben
* ändern, sodass eine Animation ensteht
* 
* TODO:
* -Implementierung
* -setOffset: Setzt Bildbreite, also 'k * offset' = k-tes Frame
* -setFrame: für ggf. Frameskip
*/
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
