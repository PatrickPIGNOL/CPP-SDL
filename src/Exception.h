/*
 * Exception.h
 *
 *  Created on: 6 sept. 2019
 *      Author: patrick
 */

#ifndef EXCEPTION_H_
#define EXCEPTION_H_

#include <exception>
#include "String.h"

namespace NFramework
{
	class Exception : std::exception
	{
		private:
			String aMessage;
			const Exception* aPrevious;
		public:
			Exception(const std::exception& pException);
			Exception(const String& pMessage = String(""), const Exception* pPrevious = NULL);
			virtual ~Exception();
			virtual const String& mMessage();
			virtual const Exception* mPrevious();
	};

} /* namespace NFramework */

#endif /* EXCEPTION_H_ */
