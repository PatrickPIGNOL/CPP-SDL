/*
 * String.cpp
 *
 *  Created on: 5 sept. 2019
 *      Author: patrick
 */

#include <string>
#include "NullPointerException.h"
#include "String.h"

namespace NFramework
{
	void String::mInit(const char pChar)
	{
		if(this->aString != NULL)
		{
			delete[](this->aString);
		}
		this->aLength = 1;
		this->aString = new char[this->aLength + 1];
		this->aString[0] = pChar;
		this->aString[this->aLength] = 0;
	}

	void String::mInit(const char* pChar)
	{
		if(this->aString != NULL)
		{
			delete[](this->aString);
		}
		this->aLength = String::mCStringLength(pChar);
		this->aString = new char[this->aLength + 1];
		unsigned long long int vIndex = 0;
		while(vIndex < this->aLength)
		{
			this->aString[vIndex] = pChar[vIndex];
			vIndex++;
		}
		this->aString[this->aLength] = 0;
	}

	void String::mInit(const String& pString)
	{
		this->aLength = pString.mLength();
		this->aString = new char[this->aLength + 1];
		unsigned long long int vIndex = 0;
		while(vIndex < this->aLength)
		{
			this->aString[vIndex] = pString[vIndex];
			vIndex++;
		}
		this->aString[this->aLength] = 0;
	}

	String::String()
	{
		this->aString = NULL;
		this->mInit("");
	}

	String::String(char pChar)
	{
		this->aString = NULL;
		this->mInit(pChar);
	}

	String::String(const char* pChar)
	{
		this->aString = NULL;
		this->mInit(pChar);
	}
	String::String(const std::string& pString)
	{
		this->aString = NULL;
		this->mInit(pString.c_str());
	}

	String::String(const String& pString)
	{
		this->aString = NULL;
		this->mInit(pString);
	}

	String::~String()
	{
		if(this->aString != NULL)
		{
			delete[](this->aString);
		}
	}

	unsigned long long int String::mLength() const
	{
		return this->aLength;
	}

	bool String::mIsEmpty()
	{
		return (this->aLength == 0);
	}

	char String::operator[](unsigned long long int pIndex) const
	{
		if(pIndex > this->aLength)
		{
			throw new Exception(String("Index (pIndex = ") + String::mToString(pIndex) + String(") out of range (MaxRange = ") + String::mToString(this->aLength) + ")");
		}
		return this->aString[pIndex];
	}

	String& String::operator=(const char pChar)
	{
		this->mInit(pChar);
		return *this;
	}

	String& String::operator=(const char* pChar)
	{
		this->mInit(pChar);
		return *this;
	}

	String& String::operator=(const std::string& pString)
	{
		this->mInit(pString.c_str());
		return *this;
	}

	String& String::operator=(const String& pString)
	{
		this->mInit(pString);
		return *this;
	}

	String String::operator+(const char pChar)
	{
		unsigned long long int vMaxLength = this->aLength + 1;
		char* vChar = new char[vMaxLength + 1];
		unsigned long long int vIndex = 0;
		while(vIndex < this->aLength)
		{
			vChar[vIndex] = this->aString[vIndex];
			vIndex++;
		}
		vChar[vIndex] = pChar;
		vChar[vMaxLength] = 0;
		String vString = String(vChar);
		delete[](vChar);
		return vString;
	}

	String String::operator+(const char* pChar)
	{
		unsigned long long int vLength = String::mCStringLength(pChar);
		unsigned long long int vMaxLength = this->aLength + vLength;
		char* vChar = new char[vMaxLength + 1];
		unsigned long long int vIndex = 0;
		while(vIndex < this->aLength)
		{
			vChar[vIndex] = this->aString[vIndex];
			vIndex++;
		}
		while(vIndex < vMaxLength)
		{
			vChar[vIndex] = pChar[vIndex - this->aLength];
			vIndex++;
		}
		vChar[vMaxLength] = 0;
		String vString = String(vChar);
		delete[](vChar);
		return vString;
	}

	String String::operator+(const std::string pString)
	{
		return *this + pString.c_str();
	}

	String String::operator+(const String pString)
	{
		unsigned long long int vLength = pString.mLength();
		unsigned long long int vMaxLength = this->aLength + vLength;
		char* vChar = new char[vMaxLength + 1];
		unsigned long long int vIndex = 0;
		while(vIndex < this->aLength)
		{
			vChar[vIndex] = this->aString[vIndex];
			vIndex++;
		}
		while(vIndex < vMaxLength)
		{
			vChar[vIndex] = pString[vIndex - this->aLength];
			vIndex++;
		}
		vChar[vMaxLength] = 0;
		String vString = String(vChar);
		delete[](vChar);

		return *this;// vString;
	}

	String& String::operator+=(const char pChar)
	{
		unsigned long long int vMaxLength = this->aLength + 1;
		char* vChar = new char[vMaxLength + 1];
		unsigned long long int vIndex = 0;
		while(vIndex < this->aLength)
		{
			vChar[vIndex] = this->aString[vIndex];
			vIndex++;
		}
		this->aLength = vMaxLength;
		vChar[vIndex] = pChar;
		vChar[this->aLength] = 0;
		if(this->aString != NULL)
		{
			delete[](this->aString);
		}
		this->aString = vChar;
		return *this;
	}

	String& String::operator+=(const char* pString)
	{
		unsigned long long int vLength = String::mCStringLength(pString);
		unsigned long long int vMaxLength = this->aLength + vLength;
		char* vString = new char[vMaxLength + 1];
		unsigned long long int vIndex = 0;
		while(vIndex < this->aLength)
		{
			vString[vIndex] = this->aString[vIndex];
			vIndex++;
		}
		while(vIndex < vMaxLength)
		{
			vString[vIndex] = pString[vIndex - this->aLength];
			vIndex++;
		}
		this->aLength = vMaxLength;
		vString[this->aLength] = 0;
		if(this->aString != NULL)
		{
			delete[](this->aString);
		}
		this->aString = vString;
		return *this;
	}

	String& String::operator+=(const std::string& pString)
	{
		return *this += pString.c_str();
	}

	String& String::operator+=(const String& pString)
	{

		unsigned long long int vLength = pString.mLength();
		unsigned long long int vMaxLength = this->aLength + vLength;
		char* vString = new char[vMaxLength + 1];
		unsigned long long int vIndex = 0;
		while(vIndex < this->aLength)
		{
			vString[vIndex] = this->aString[vIndex];
			vIndex++;
		}
		while(vIndex < vMaxLength)
		{
			vString[vIndex] = pString[vIndex - this->aLength];
			vIndex++;
		}
		this->aLength = vMaxLength;
		vString[this->aLength] = 0;
		if(this->aString != NULL)
		{
			delete[](this->aString);
		}
		this->aString = vString;
		return *this;
	}

	const char* String::mToCString() const
	{
		return this->aString;
	}

	unsigned long long String::mCStringLength(const char* pChar)
	{
		if(pChar == NULL)
		{
			throw NullPointerException(String("Null pointer passed as a C String (char*)"));
		}
		unsigned long long vLength = 0;
		while(pChar[vLength] != 0)
		{
			vLength++;
		}
		return vLength;
	}
} /* namespace NFramework */
