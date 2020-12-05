/*
 * GraphicComponent.cpp
 *
 *  Created on: 3 sept. 2019
 *      Author: patrick
 */

#include "GraphicComponent.h"

namespace NFramework
{
	GraphicComponent::GraphicComponent(int pX, int pY,int pWidth, int pHeight) : IGraphicComponent()
	{
		this->aVisible = false;
		this->aMouseOver = false;
		this->aRect.x = pX;
		this->aRect.y = pY;
		this->aRect.w = pWidth;
		this->aRect.h = pHeight;
	}

	GraphicComponent::~GraphicComponent()
	{

	}


	void GraphicComponent::mEventHandler(SDL_Event* e)
	{
		switch(e->type)
		{
			case SDL_MOUSEMOTION :
			{
				int vX = e->motion.x;
				int vY = e->motion.y;
				bool vMouseOver = vX > this->aRect.x && vX < (this->aRect.x + this->aRect.w) && vY > this->aRect.y && vY< this->aRect.y + this->aRect.h;
				if(vMouseOver)
				{
					if(!this->aMouseOver)
					{
						//OnMouseEnter();
						this->aMouseOver = true;
					}
					//OnMouseMove();
				}
				else
				{
					if(this->aMouseOver)
					{
						//OnMouseExit();
						this->aMouseOver = false;
					}
				}
			}break;
			case SDL_MOUSEBUTTONDOWN:
			case SDL_MOUSEBUTTONUP:
			{
				int vX = e->motion.x;
				int vY = e->motion.y;
				bool vMouseOver = vX > this->aRect.x && vX < (this->aRect.x + this->aRect.w) && vY > this->aRect.y && vY< this->aRect.y + this->aRect.h;
				if(vMouseOver)
				{
					switch(e->button.clicks)
					{
						case 1:
						{
							//OnClick();
						}break;
						case 2:
						{
							//OnDoubleClick();
						}break;
					}
				}
			}break;
		}
	}

	void GraphicComponent::mUpdate(double pDeltaTime)
	{
		if(this->aMouseOver)
		{
			// drawIn
		}
		else
		{
			// drawOut
		}
	}

	void GraphicComponent::mDraw(SDL_Renderer* pRenderer)
	{

		if(this->aVisible)
		{
			/*
			if(this->aSurface != NULL)
			{
				SDL_Texture* vTexture = SDL_CreateTextureFromSurface(pRenderer, this->aSurface);
				SDL_RenderCopy(pRenderer, vTexture, NULL, &this->aRect);
				SDL_DestroyTexture(vTexture);
			}
			*/
		}
	}

	void GraphicComponent::mHide()
	{
		this->aVisible = false;
	}

	void GraphicComponent::mShow()
	{
		this->aVisible = true;
	}

	bool GraphicComponent::mIsVisible()
	{
		return this->aVisible;
	}
} /* namespace NFramework */
