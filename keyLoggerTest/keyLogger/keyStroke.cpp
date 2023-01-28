#include "keyStroke.h"

keyStroke::keyStroke()
{
	_printable = false;
	_shifted = false;
	_asciiChar = 0;
}

keyStroke::keyStroke(const bool printable, const bool shifted, const char asciiChar)
{
	_printable = printable;
	_shifted = shifted;
	_asciiChar = asciiChar;
}

keyStroke::~keyStroke()
{
}

bool keyStroke::isPrintable() const
{
	return _printable;
}

bool keyStroke::isShifted() const
{
	return _shifted;
}

char keyStroke::getKeyCharacter() const
{
	char keyChar = _asciiChar;

	if (_shifted)
		keyChar = keyProcessor::formatShiftedKeys(keyChar);


	return keyChar;
}

keyStroke keyStroke::operator=(keyStroke const& other)
{
	_printable = other.isPrintable();
	_shifted = other.isShifted();
	_asciiChar = other.getKeyCharacter();
	return *this;
}
