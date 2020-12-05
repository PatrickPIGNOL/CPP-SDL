/*
 * NullPointerException.cpp
 *
 *  Created on: 6 sept. 2019
 *      Author: patrick
 */

#include "Exception.h"
#include "NullPointerException.h"

namespace NFramework
{
	NullPointerException::NullPointerException(const String& pMessage, const Exception* pPrevious) : Exception(pMessage, pPrevious)
	{

	}

	NullPointerException::~NullPointerException()
	{
	}
} /* namespace NFramework */
