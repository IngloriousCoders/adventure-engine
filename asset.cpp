#include "asset.hpp"

namespace Adventure
{
		Asset::Asset(char* path,bool _autoload)
		{
			
			//Path nach intern kopieren
			this->setPath(path);
			
			//autoload nach intern kopieren
			
			this->autoload = _autoload;
			
			if (autoload)
			{
				load();
			}
		}
		Asset::~Asset()
		{
			SDL_FreeSurface(this->mSurface);
		}
		void Asset::load()
		{
			this->mSurface = IMG_Load((const char*)this->mPath);
			if ( this->mSurface )
			{
				this->loaded = true;
			}
		}
				
		char* Asset::getPath()
		{
			return this->mPath;
		}
		char* Asset::setPath(char* path)
		{
			//Path nach intern kopieren
			int len = strlen(path);
			this->mPath = new char[len+1];
			strncpy(this->mPath,path,len);
			this->mPath[len] = '\0';
		}
		bool Asset::isLoaded()
		{
			return this->loaded;
		}
		SDL_Surface* Asset::getSurface()
		{
			return this->mSurface;
		}
}
