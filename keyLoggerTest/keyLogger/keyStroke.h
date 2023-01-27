#pragma once
class keyStroke
{
public:
	keyStroke();
	keyStroke(const bool printable, const bool shifted, const char asciiChar);
	~keyStroke();

	bool isPrintable() const;
	bool isShifted() const;
	char getKeyCharacter() const;

private:
	bool _printable;
	bool _shifted;
	char _asciiChar;

};

