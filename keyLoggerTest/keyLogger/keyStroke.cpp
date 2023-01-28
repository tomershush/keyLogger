#include "keyStroke.h"

keyStroke::keyStroke()
{
	_printable = false;
	_shifted = false;
	_asciiChar = 0;
	_keyCode = 0;
}

keyStroke::keyStroke(const bool printable, const bool shifted, const char asciiChar, const int keyCode)
{
	_printable = printable;
	_shifted = shifted;
	_asciiChar = asciiChar;
	_keyCode = keyCode;
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

char keyStroke::getPrintableCharacter() const
{
	char keyChar = _asciiChar;

	if (_printable)
	{
		if (_shifted)
			keyChar = keyProcessor::formatShiftedKeys(keyChar);
	}
	else
		keyChar = 0;




	return keyChar;
}

keyStroke keyStroke::operator=(keyStroke const& other)
{
	_printable = other.isPrintable();
	_shifted = other.isShifted();
	_asciiChar = other.getKeyCharacter();
	return *this;
}

int keyStroke::getKeyCode() const
{
	return _keyCode;
}