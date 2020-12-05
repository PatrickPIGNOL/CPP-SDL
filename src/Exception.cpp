/*
 * Exception.cpp
 *
 *  Created on: 6 sept. 2019
 *      Author: patrick
 */

#include "Exception.h"
#include <exception>

namespace NFramework
{
	Exception::Exception(const std::exception& pException): exception(pException)
	{
		this->aMessage = String(pException.what());
		this->aPrevious = NULL;
	}

	Exception::Exception(const String& pMessage, const Exception* pPrevious): exception()
	{
		this->aMessage = String(pMessage);
		this->aPrevious = pPrevious;
	}

	Exception::~Exception()
	{
		if(this->aPrevious != NULL)
		{
			delete(this->aPrevious);
		}
	}

	const String& Exception::mMessage()
	{
		return this->aMessage;
	}

	const Exception* Exception::mPrevious()
	{
		return this->aPrevious;
	}
} /* namespace NFramework */
