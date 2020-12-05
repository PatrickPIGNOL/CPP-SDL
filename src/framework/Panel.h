/*
 * Panel.h
 *
 *  Created on: 2 sept. 2019
 *      Author: patrick
 */

#ifndef PANEL_H_
#define PANEL_H_

#include <SDL2/SDL.h>
#include <vector>
#include "IGraphicComponent.h"
#include "GraphicComponent.h"

using namespace std;

namespace NFramework
{
	class Panel : GraphicComponent
	{
		private:
			SDL_Surface* aSurface;
			bool aVisible;
			bool aMouseOver;
			//vector<IGraphicComponent*>* aComponents;
			void mInit(SDL_Surface* pSurface, int pX, int pY,int pWidth, int pHeight);
		public:
			Panel(SDL_Surface* pSurface, int pX, int pY);
			Panel(int pX, int pY, int pWidth, int pHeight);
			virtual ~Panel();
			//void mAddComponent(IGraphicComponent* pGraphicComponent);
			//void mRemoveComponent(IGraphicComponent* pGraphicComponent);
			virtual void mEventHandler(SDL_Event* e);
			virtual void mDraw(SDL_Renderer* pRenderer);
			virtual void mHide();
			virtual bool mIsVisible();
			virtual void mShow();
			virtual void mUpdate(double pDeltaTime);
	};
} /* namespace NFramework */

#endif /* PANEL_H_ */
