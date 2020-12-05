/*
 * GraphicComponent.h
 *
 *  Created on: 3 sept. 2019
 *      Author: patrick
 */

#ifndef GRAPHICCOMPONENT_H_
#define GRAPHICCOMPONENT_H_
#include <SDL2/SDL.h>
#include "IGraphicComponent.h"

namespace NFramework {

class GraphicComponent : IGraphicComponent
{
	private:
		SDL_Rect aRect;
		bool aVisible;
		bool aMouseOver;
		void mInit(int pX, int pY,int pWidth, int pHeight);
	public:
		GraphicComponent(int pX, int pY,int pWidth, int pHeight);
		virtual ~GraphicComponent();
		virtual void mEventHandler(SDL_Event* e);
		virtual void mDraw(SDL_Renderer* pRenderer);
		virtual void mHide();
		virtual bool mIsVisible();
		virtual void mShow();
		virtual void mUpdate(double pDeltaTime);
};

} /* namespace NFramework */

#endif /* GRAPHICCOMPONENT_H_ */
