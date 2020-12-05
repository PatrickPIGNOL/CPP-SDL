/*
 * String.h
 *
 *  Created on: 5 sept. 2019
 *      Author: patrick
 */

#ifndef STRING_H_
#define STRING_H_
#include <string>
#include <vector>
#include <sstream>

namespace NFramework
{
	class String
	{
		private:
			char* aString;
			unsigned long long int aLength;
			void mInit(const char pChar);
			void mInit(const char* pString);
			void mInit(const String& pString);
			template<typename T> static String mToString(const T& pValue, const String& pFormat)
			{
				char vBuffer[50];
				sprintf(vBuffer, pFormat.mToCString(), pValue);
				return String(vBuffer);
			}
		public:
			String();
			String(const char pChar);
			String(const char* pString);
			String(const std::string& pString);
			String(const String& pString);
			virtual ~String();
			virtual unsigned long long int mLength() const;
			virtual bool mIsEmpty();
			virtual char operator[](unsigned long long int pIndex) const;
			virtual String& operator=(const char pChar);
			virtual String& operator=(const char* pString);
			virtual String& operator=(const std::string& pString);
			virtual String& operator=(const String& pString);
			virtual String operator+(const char pChar);
			virtual String operator+(const char* pString);
			virtual String operator+(const std::string pString);
			virtual String operator+(const String pString);
			virtual String& operator+=(const char pChar);
			virtual String& operator+=(const char* pString);
			virtual String& operator+=(const std::string& pString);
			virtual String& operator+=(const String& pString);
			virtual const char* mToCString() const;
			static unsigned long long int mCStringLength(const char* pChar);
			static String mToString(char pValue)
			{
				return String::mToString<char>(pValue, String("%c"));
			};
			static String mToString(unsigned char pValue)
			{
				return String::mToString<unsigned char>(pValue, String("%c"));
			};
			static String mToString(short pValue)
			{
				return String::mToString<short>(pValue, String("%d"));
			};
			static String mToString(unsigned short pValue)
			{
				return String::mToString<unsigned short>(pValue, String("%u"));
			};
			static String mToString(int pValue)
			{
				return String::mToString<int>(pValue, String("%d"));
			};
			static String mToString(unsigned int pValue)
			{
				return String::mToString<unsigned int>(pValue, String("%u"));
			};
			static String mToString(long int pValue)
			{
				return String::mToString<long int>(pValue, String("%d"));
			};
			static String mToString(unsigned long int pValue)
			{
				return String::mToString<unsigned long int>(pValue, String("%u"));
			};
			static String mToString(long long int pValue)
			{
				return String::mToString<long long int>(pValue, String("%d"));
			};
			static String mToString(unsigned long long int pValue)
			{
				return String::mToString<unsigned long long int>(pValue, String("%u"));
			};
			static String mToString(float pValue)
			{
				return String::mToString<float>(pValue, String("%G"));
			};
			static String mToString(double pValue)
			{
				return String::mToString<double>(pValue, String("%G"));
			};
			static String mToString(long double pValue)
			{
				return String::mToString<long double>(pValue, String("%G"));
			};
	};
} /* namespace NFramework */

#endif /* STRING_H_ */
