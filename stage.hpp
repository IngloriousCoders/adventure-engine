/*Eine Stage ist eine Spielszene, also ein Schauplatz im Spiel, mit mehreren Layern und Spielfiguren* 
 * TODO:
 * 
 * 
 * */
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
				Stage(char* id,int width,int height); // Stageid um später per "Links" zwischen Schauplätzen wechseln zu können
													  // width, height Breite und Höhe des Feldes
				~Stage();
								
				SDL_Surface* getSurface();  		  // Intern, gibt SDL_Surface zurück, dass das Bild repräsentiert
				
				SDL_Rect* getSDLSize();				  // Relevant um das Stage-SDL_Surface auf das Window-SDL_Surface richtig zu blitten/zeichnen
				
				int getWidth();
				int getHeight();
				
				void setCameraPosition(int cameraPosition);	// Setzt die Kameraposition auf der X-Achse, kommt Position eines Dollys gleich. In Pixeln
				int getCameraPosition();				     
				
				int getMaxDepth();							// Da Z-Index nur eine relative Position angibt, ist der Z-Index am weitesten hinten im Bild
															// die maxDepth. 
				
				void setDepth( double depth );
				int getDepth( );							// Weis gerade nicht warum es Depth und maxDepth gibt
				
				void addLayer( Layer* layer );				// Fügt eine Ebene hinzu. 
				
				void redraw();								// Zeichnet die Stage neu. Hier findet die Verschiebungs-Magie statt... NICHT

				
							
			private:
				char* id;
				
				std::vector<Layer*> mLayers;

				bool sorted;
				void sortLayers(); 							// Sortiert die Layers mit Bubblesort
				
				Layer* mBackgroundLayer;
				
				SDL_Surface* mSurface;
				
				static const double mCameraAngle = 46.8;			// Camera-Angle falls die Berechnung mal implementiert ist
				int mCameraPosition;
				int mDepth;
				int mMaxDepth;
				
				int mWidth;
				int mHeight;
				
				SDL_PixelFormat _format;					// Pixel-Format. Wichtig, um alle Bilder mit den korrekten Farben darzustellen

	};

}

#endif // _ADVENTURE_STAGE_H_
