/*
 * Panel.cpp
 *
 *  Created on: 2 sept. 2019
 *      Author: patrick
 */

#include <vector>
#include "Panel.h"
#include "IGraphicComponent.h"
#include "GraphicComponent.h"

namespace NFramework
{

	Panel::Panel(SDL_Surface* pSurface, int pX, int pY): GraphicComponent(pX, pY, pSurface->w, pSurface->h)
	{
		this->mInit(pSurface, pX, pY, 0, 0);
	}

	Panel::Panel(int pX, int pY, int pWidth, int pHeight):GraphicComponent(pX, pY, pWidth, pHeight)
	{
		this->mInit(NULL, pX, pY, pWidth, pHeight);
	}

	void Panel::mInit(SDL_Surface* pSurface, int pX, int pY,int pWidth, int pHeight)
	{
		//this->aComponents = new vector<IGraphicComponent*>();
		this->aMouseOver = false;
		this->aVisible = false;
	}

	Panel::~Panel()
	{
		if(this->aSurface != NULL)
		{
			SDL_FreeSurface(this->aSurface);
			this->aSurface = NULL;
		}
		/*
		while(!this->aComponents->empty())
		{
			delete(this->aComponents->back());
			this->aComponents->pop_back();
		}
		delete(this->aComponents);
		*/
	}
/*
	void Panel::mAddComponent(IGraphicComponent* pGraphicComponent)
	{
		this->aComponents->push_back(pGraphicComponent);
	}

	void Panel::mRemoveComponent(IGraphicComponent* pGraphicComponent)
	{
		int vSize = this->aComponents->size();
		int vIndex = 0;
		bool vContinue;
		while(vContinue && (vIndex < vSize))
		{
			if(this->aComponents[vIndex] == pGraphicComponent)
			{
				this->aComponents->erase(this->aComponents->begin() + vIndex);
				vContinue = false;
			}
			vIndex++;
		}
	}
*/
	void Panel::mEventHandler(SDL_Event* e)
	{
		switch(e->type)
		{
			case SDL_MOUSEMOTION :
			{
				int vX = e->motion.x;
				int vY = e->motion.y;
				/*
				bool vMouseOver = vX > this->GraphicComponent::IGraphicComponent::mX().x && vX < (this->GraphicComponent::IGraphicComponent::mX() + ((IGraphicComponent)this)->mWidth()) && vY > this->GraphicComponent::IGraphicComponent::mY() && vY< this->GraphicComponent::IGraphicComponent::mY() + this->GraphicComponent::IGraphicComponent::mHeight();
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
				*/
			}break;
			case SDL_MOUSEBUTTONDOWN:
			case SDL_MOUSEBUTTONUP:
			{
				int vX = e->motion.x;
				int vY = e->motion.y;
				/*
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
				*/
			}break;
		}
	}

	void Panel::mUpdate(double pDeltaTime)
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

	void Panel::mDraw(SDL_Renderer* pRenderer)
	{

		if(this->aVisible)
		{
			if(this->aSurface != NULL)
			{
				SDL_Texture* vTexture = SDL_CreateTextureFromSurface(pRenderer, this->aSurface);
				//SDL_RenderCopy(pRenderer, vTexture, NULL, &this->aRect);
				SDL_DestroyTexture(vTexture);
			}
		}
	}

	void Panel::mHide()
	{
		this->aVisible = false;
	}

	void Panel::mShow()
	{
		this->aVisible = true;
	}

	bool Panel::mIsVisible()
	{
		return this->aVisible;
	}

} /* namespace NFramework */
