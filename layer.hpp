/* Ein Layer ist eine Ebene. Der Hintergrund ist das Objekt. 
 * Er besitzt einen Z-Index, der die Anordunung im Raum angibt.
 * Jedes Objekt im Raum ist ein Layer/Ebene 
 * 
 * TODO:
 * - Sowohl X als auch Y-Offset, also sozusagen Positionsangaben
 * 
 * */
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
			Layer(Asset* background,int zindex); // Asset: Hintergrundbild/animation, zindex: ja also, is klar
			
			SDL_Surface* getSurface(); // Intern: gibt SDL_Surface zurück, die den gesamten Layer darstellt.
			
			void setZIndex(int zindex); 
			int  getZIndex();
			
			Asset *mBackground; 
						
		private:
			int mZIndex;
			
			
		
	};
}


#endif // _LAYER_H_
