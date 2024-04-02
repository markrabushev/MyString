#include "String.h"


String::String()
{
	str = new char[1];
	str[0] = '\0';
}

String::String(const char* str)
{
	int len = strlen(str);
	this->str = new char[len+1];

	for (int i = 0; i < len; i++) {
		this->str[i] = str[i];
	}

	this->str[len] = '\0';
}

String::String(const char* str, size_t n)
{
	int len = strlen(str) > n ? n : strlen(str);
	this->str = new char[len + 1];

	for (int i = 0; i < len; i++) {
		this->str[i] = str[i];
	}

	this->str[len] = '\0';
}

String::String(const String& other)
{
	this->str = new char[strlen(other.str) + 1];
	for (int i = 0; i < strlen(other.str); i++) {
		this->str[i] = other.str[i];
	}
	this->str[strlen(other.str)] = '\0';

}

String::String(String&& other) noexcept
{
	str = other.str;
	other.str = nullptr;	
}


String::~String()
{
	delete[] this->str;
}


size_t String::length() const
{
	if (str != nullptr) {
		return strlen(str);
	}
	else return 0;
}

void String::clear() noexcept
{
	delete[] str;
	str = new char[1];
	str[0] = '\0';

}

bool String::empty() const noexcept
{
	return strlen(str) == 0;
}

String& String::operator=(const String& other)
{
	if (this->str != nullptr) {
		delete[] this->str;
	}
	this->str = new char[strlen(other.str) + 1];
	for (int i = 0; i < strlen(other.str); i++) {
		this->str[i] = other.str[i];
	}
	this->str[strlen(other.str)] = '\0';
	return *this;
}

String String::operator+(const String& other)
{
	String newS;
	int len1 = strlen(this->str);
	int len2 = strlen(other.str);
	int len = len1 + len2;
	newS.str = new char[len + 1];
	int i = 0;
	for (; i < len1; i++) {
		newS.str[i] = this->str[i];
	}
	for (int j = 0; j < len2; i++, j++) {
		newS.str[i] = other.str[j];
	}
	newS.str[len] = '\0';
	return newS;
}

std::ostream& operator<<(std::ostream& os, const String& other)
{
	os << other.str;
	return os;
}

std::istream& operator>>(std::istream& is, String& other)
{
	char* buff = new char[1000];
	is >> buff;
	other.str = buff;
	return is;
}
