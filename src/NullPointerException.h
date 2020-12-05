/*
 * NullPointerException.h
 *
 *  Created on: 6 sept. 2019
 *      Author: patrick
 */

#ifndef NULLPOINTEREXCEPTION_H_
#define NULLPOINTEREXCEPTION_H_

#include "Exception.h"

namespace NFramework
{
	class NullPointerException : Exception
	{
		public:
			NullPointerException(const String& pMessage = String(""), const Exception* pPrevious = NULL);
			virtual ~NullPointerException();
	};
} /* namespace NFramework */

#endif /* NULLPOINTEREXCEPTION_H_ */
