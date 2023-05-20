#include "MyString.h"

namespace assignment1
{

	MyString::MyString()
		: mSize(0)
		, mString(0)
	{}
	MyString::MyString(const char* s)
		: mSize(0)
	{
		while (*(s + (mSize * sizeof(char))) != '\0')
		{
			mSize++;
		}
		mString = new char[mSize + 1];

		for (unsigned int i = 0; i < mSize; i++)
		{
			mString[i] = s[i];
		}
		mString[mSize] = '\0';
	}

	MyString::MyString(const MyString& other)
		: mSize(other.mSize)
	{
		char* temp1;
		char* temp2;

		temp1 = mString;
		temp2 = other.mString;

		mString = new char[mSize + 1];

		for (unsigned int i = 0; i < mSize; i++)
		{
			mString[i] = temp2[i];
		}
		mString[mSize] = '\0';

		delete[] temp1;
	}

	MyString::~MyString()
	{
		delete[] mString;
	}

	unsigned int MyString::GetLength() const
	{
		return mSize;
	}

	const char* MyString::GetCString() const
	{
		char* s = new char[mSize + 1];

		for (unsigned int i = 0; i < mSize; i++)
		{
			s[i] = mString[i];
		}
		s[mSize] = '\0';

		return s;
	}

	void MyString::Append(const char* s)
	{
		unsigned int sSize = 0;

		while (*(s + (sSize * sizeof(char))) != '\0')
		{
			sSize++;
		}

		char* temp = mString;
		mString = new char[mSize + sSize + 1];



		for (unsigned int i = 0; i < mSize; i++)
		{
			mString[i] = temp[i];
		}

		for (unsigned int i = mSize; i < mSize + sSize; i++)
		{
			mString[i] = s[i - mSize];
		}
		mString[mSize + sSize] = '\0';

		mSize = mSize + sSize;

		delete[] temp;
	}

	MyString MyString::operator+(const MyString& other) const
	{
		MyString result;

		result.mString = new char[mSize + other.mSize + 1];
		result.mSize = mSize + other.mSize;

		for (unsigned int i = 0; i < mSize; i++)
		{
			result.mString[i] = mString[i];
		}

		for (unsigned int i = mSize; i < mSize + other.mSize; i++)
		{
			result.mString[i] = other.mString[i - mSize];
		}
		result.mString[result.mSize] = '\0';

		return result;
	}

	int MyString::IndexOf(const char* s)
	{
		int sSize = 0;
		bool same = false;
		int index = -1;
		int i = 0;

		while (s[sSize] != '\0')	
		{
			sSize++;
		}

		if (sSize == 0)
		{
			return 0;
		}


		while (i <= mSize - sSize && same == false)
		{
			if (s[0] == mString[i])
			{
				same = true;
				for (int j = i + 1; j < i + sSize && same == true; j++)
				{
					if (s[j - i] != mString[j])
					{
						same = false;
					}

				}
			}
			i++;
		}

		if (same == true)
		{
			index = i - 1;
		}
		return index;
	}

	int MyString::LastIndexOf(const char* s)
	{
		int sSize = 0;
		bool same = false;
		int index = -1;
		int i = 0;

		while (s[sSize] != '\0')
		{
			sSize++;
		}
		if (sSize == 0)
		{
			return mSize;
		}


		for (i = 1; i <= mSize && same == false; i++)
		{
			if (s[sSize - 1] == mString[mSize - i])
			{
				same = true;
				for (int j = 2; j <= sSize && same == true; j++)
				{
					if (s[sSize - j] != mString[mSize - i - j + 1])
					{
						same = false;
					}

				}
			}
		}
		i--;

		if (same == true)
		{
				index = mSize - i - (sSize - 1);
		}
		return index;
	}

	void MyString::Interleave(const char* s)
	{
		unsigned int sSize = 0;
		while (s[sSize] != '\0')
		{
			sSize++;
		}

		char* temp = mString;

		mString = new char[mSize + sSize + 1];

		if (mSize > sSize)
		{
			for (unsigned int i = 0; i < sSize; i++)
			{
				mString[i * 2] = temp[i];
				mString[i * 2 + 1] = s[i];
			}
			for (unsigned int i = sSize * 2; i < sSize + mSize; i++)
			{
				mString[i] = temp[i];
			}
		}
		else
		{
			for (unsigned int i = 0; i < mSize; i++)
			{
				mString[i * 2] = temp[i];
				mString[i * 2 + 1] = s[i];
			}
			for (unsigned int i = mSize; i < sSize; i++)
			{
				mString[i + mSize] = s[i];
			}
		}

		mSize = mSize + sSize;

		mString[mSize] = '\0';

		delete[] temp;

	}

	bool MyString::RemoveAt(unsigned int i)
	{

		if (i >= mSize || i < 0)
		{
			return false;
		}

		for (unsigned int j = i; j <= mSize; j++)
		{
			mString[j] = mString[j + 1];
		}

		mSize--;

		return true;
	}

	void MyString::PadLeft(unsigned int totalLength)
	{
		if (totalLength > mSize)
		{
			char* temp = mString;
			mString = new char[totalLength + 1];

			for (unsigned int i = 1; i <= mSize; i++)
			{
				mString[totalLength - i] = temp[mSize - i];
			}
			mString[totalLength] = '\0';

			for (unsigned int i = 0; i < totalLength - mSize; i++)
			{
				mString[i] = ' ';
			}
			mSize = totalLength;
			delete[] temp;
		}

	}

	void MyString::PadLeft(unsigned int totalLength, const char c)
	{
		if (totalLength > mSize)
		{
			char* temp = mString;
			mString = new char[totalLength + 1];

			for (unsigned int i = 1; i <= mSize; i++)
			{
				mString[totalLength - i] = temp[mSize - i];
			}
			mString[totalLength] = '\0';
			for (unsigned int i = 0; i < totalLength - mSize; i++)
			{
				mString[i] = c;
			}
			mSize = totalLength;

			delete[] temp;
		}
	}

	void MyString::PadRight(unsigned int totalLength)
	{
		if (totalLength > mSize)
		{
			char* temp = mString;
			mString = new char[totalLength + 1];

			for (unsigned int i = 0; i < mSize; i++)
			{
				mString[i] = temp[i];
			}


			for (unsigned int i = mSize; i < totalLength; i++)
			{
				mString[i] = ' ';
			}
			mSize = totalLength;
			mString[totalLength] = '\0';

			delete[] temp;
		}
	}

	void MyString::PadRight(unsigned int totalLength, const char c)
	{
		if (totalLength > mSize)
		{
			char* temp = mString;
			mString = new char[totalLength + 1];

			for (unsigned int i = 0; i < mSize; i++)
			{
				mString[i] = temp[i];
			}


			for (unsigned int i = mSize; i < totalLength; i++)
			{
				mString[i] = c;
			}
			mSize = totalLength;
			mString[totalLength] = '\0';

			delete[] temp;
		}
	}

	void MyString::Reverse()
	{
		char temp;
		for (unsigned int i = 0; i < mSize / 2; i++)
		{
			temp = mString[i];
			mString[i] = mString[mSize - 1 - i];
			mString[mSize - 1 - i] = temp;
		}
	}

	bool MyString::operator==(const MyString& rhs) const
	{
		if (mSize != rhs.mSize)
		{
			return false;
		}

		for (unsigned int i = 0; i < mSize; i++)
		{
			if (mString[i] != rhs.mString[i])
			{
				return false;
			}
		}
		return true;

	}

	MyString& MyString::operator=(const MyString& rhs)
	{
		char* temp1;
		char* temp2;

		temp1 = mString;
		temp2 = rhs.mString;

		mString = new char[rhs.mSize + 1];

		for (unsigned int i = 0; i < rhs.mSize; i++)
		{
			mString[i] = temp2[i];
		}
		mSize = rhs.mSize;

		delete[] temp1;

		return *this;
	}

	void MyString::ToLower()
	{
		int dif = 'a' - 'A';
		for (unsigned int i = 0; i < mSize; i++)
		{
			if (mString[i] >= 'A' && mString[i] <= 'Z')
			{
				mString[i] += dif;
			}
		}

	}

	void MyString::ToUpper()
	{
		int dif = 'a' - 'A';
		for (unsigned int i = 0; i < mSize; i++)
		{
			if (mString[i] >= 'a' && mString[i] <= 'z')
			{
				mString[i] -= dif;
			}
		}

	}
}