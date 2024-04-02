#pragma once
#include <iostream>
#include <string>


class String
{
public:
	String();
	String(const char* str);
	String(const char* str, size_t n);
	String(const String& other);
	String(String&& other) noexcept;
	~String();
	size_t length() const;
	void clear() noexcept;
	bool empty() const noexcept;
	String& operator= (const String& other);
	String operator+ (const String& other);
private:
	char* str;
	friend std::ostream& operator<< (std::ostream& os, const String& other);
	friend std::istream& operator>> (std::istream& is, String& other);
};
