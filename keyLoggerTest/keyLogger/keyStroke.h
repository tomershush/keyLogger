#pragma once
#include "keyProcessor.h"


class keyStroke
{
public:
	keyStroke();
	keyStroke(const bool printable, const bool shifted, const char asciiChar);
	~keyStroke();

	bool isPrintable() const;
	bool isShifted() const;
	char getKeyCharacter() const;

	keyStroke operator = (keyStroke const& other);

private:
	bool _printable;
	bool _shifted;
	char _asciiChar;

};

