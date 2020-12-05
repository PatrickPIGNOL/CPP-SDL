/*
 * IGraphicComponent.h
 *
 *  Created on: 3 sept. 2019
 *      Author: patrick
 */

#ifndef IGRAPHICCOMPONENT_H_
#define IGRAPHICCOMPONENT_H_

#include <SDL2/SDL.h>

namespace NFramework {

class IGraphicComponent
{
	public:
		IGraphicComponent();
		virtual ~IGraphicComponent();
		virtual void mX() = 0;
		virtual void mY() = 0;
		virtual void mWidth() = 0;
		virtual void mHeight() = 0;
		virtual void mEventHandler(SDL_Event* e) = 0;
		virtual void mDraw(SDL_Renderer* pRenderer) = 0;
		virtual void mHide() = 0;
		virtual bool mIsVisible() = 0;
		virtual void mShow() = 0;
		virtual void mUpdate(double pDeltaTime) = 0;
};

} /* namespace NFramework */

#endif /* IGRAPHICCOMPONENT_H_ */
