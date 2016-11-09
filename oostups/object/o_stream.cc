/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                            O _ S T R E A M                                */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Die Klasse O_Stream enthaelt die Definition des << Operators fuer die     */
/* wichtigsten der vordefinierten Datentypen und realisiert somit die        */
/* bekannte Ausgabefunktion der C++ IO_Stream Bibliothek. Zur Zeit wird die  */
/* Darstellung von Zeichen, Zeichenketten und ganzen Zahlen unterstuetzt.    */
/* Ein weiterer << Operator erlaubt die Verwendung von Manipulatoren.        */
/*                                                                           */
/* Neben der Klasse O_Stream sind hier auch die Manipulatoren hex, dec, oct  */
/* und bin fuer die Wahl der Basis bei der Zahlendarstellung, sowie endl     */
/* fuer den Zeilenumbruch definiert.                                         */
/*****************************************************************************/

#include "object/o_stream.h"

	char O_Stream::bin_digit_to_char_table[] = 
			{'0', '1'};
	char O_Stream::oct_digit_to_char_table[] = 
			{'0', '1', '2', '3', '4', '5', '6', '7'};
	char O_Stream::dec_digit_to_char_table[] = 
			{'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
	char O_Stream::hex_digit_to_char_table[] = 
			{'0', '1', '2', '3', '4', '5', '6', '7', '8', 
				'9', 'a', 'b', 'c', 'd', 'e', 'f'};
	char O_Stream::prefix_bin[] = {'0', 'b', 0};
	char O_Stream::prefix_oct[] = {'0', 'o', 0};
	char O_Stream::prefix_dec[] = {0};
	char O_Stream::prefix_hex[] = {'0', 'x', 0};
	char O_Stream::negative_sign = '-';
	char O_Stream::newline_char = '\n';
	// This value is used to initialize number_base
	const unsigned char DEFAULT_BASE = O_Stream::DEC;

	O_Stream::O_Stream() : Stringbuffer() {
		O_Stream::number_base = DEFAULT_BASE;
		O_Stream::digit_count = 0;
	}

	O_Stream& O_Stream::operator<< (unsigned char c) {
		O_Stream::put(char(c));
		return *this;
	}

	O_Stream& O_Stream::operator<< (char c) {
		O_Stream::put(c);
		return *this;
	}

	O_Stream& O_Stream::operator<< (char* text) {
		while (*text != 0) {
			put(*text);
			text++;
		}
		return *this;
	}

	O_Stream& O_Stream::operator<< (void* pointer) {
		unsigned char oldBase = getBase();
		setBase(O_Stream::HEX);
		*this << (int) pointer;
		setBase(oldBase);
		return *this;
	}

	O_Stream& O_Stream::operator<< (O_Stream& (*fkt) (O_Stream&)) {
		return fkt(*this);
	}
	/*
	 * The following are helper methods for printing numbers
	 */

	// Returns the char representing the given digit. Honors the current number_base.
	// If the digit is too large or too small a '?' is returned.
	// If the number_base is illegal a '?' is returned.
	char O_Stream::toChar(unsigned char digit) {
		unsigned char base = getBase();
		if (digit < 0 || digit >= base) {
			return '?';
		}
		switch (base) {
		case O_Stream::BIN: return bin_digit_to_char_table[digit];
		case O_Stream::OCT: return oct_digit_to_char_table[digit];
		case O_Stream::DEC: return dec_digit_to_char_table[digit];
		case O_Stream::HEX: return hex_digit_to_char_table[digit];
		default: return '?';
		}
	}
	// Puts the prefix for the current number_base into the buffer.
	// If the number_base is illegal a '?' is put.
	void O_Stream::putBasePrefix() {
		switch (getBase()) {
		case O_Stream::BIN: *this << O_Stream::prefix_bin; break;
		case O_Stream::OCT: *this << O_Stream::prefix_oct; break;
		case O_Stream::DEC: *this << O_Stream::prefix_dec; break;
		case O_Stream::HEX: *this << O_Stream::prefix_hex; break;
		default: *this << '?'; break;
		}
	}
	
	// the value must be either BIN, OCT, DEC or HEX.
	void O_Stream::setBase(unsigned char value) {
		O_Stream::number_base = value;
	}

	unsigned char O_Stream::getBase() {
		return O_Stream::number_base;
	}

	void O_Stream::putDigit(char digitAsChar) {
		if (digit_count < DIGIT_BUFFER_SIZE) {
			digit_buffer[digit_count++] = digitAsChar;
		}
	}

	void O_Stream::flushDigitBuffer() {
		while (digit_count > 0) {
			O_Stream::put(digit_buffer[--digit_count]);
		}
	}

	O_Stream& O_Stream::operator<< (unsigned short number) {
		if (number == 0) {
			O_Stream::put('0');
			return *this;			
		}
		// getBase() is either BIN, OCT, DEC or HEX
		unsigned char base = getBase();
		// prints the prefix 0b, 0o or 0x depending on base.
		putBasePrefix();
		
		while (number > 0) {
			// retrieve the last digit of number
			unsigned char digit = (unsigned char)(number % base);
			// convert the last digit of number to a char
			char digitAsChar = toChar(digit);
			// buffer the char in the digit_buffer
			O_Stream::putDigit(digitAsChar);
			// remove the last digit of number
			number /= base;
		}
		// output the digit buffer in reverse order
		flushDigitBuffer();
		return *this;
	}

	O_Stream& O_Stream::operator<< (short number) {
		if (number == 0) {
			O_Stream::put('0');
			return *this;			
		}
		if (number < 0) {
			O_Stream::put(negative_sign);
			number = -number;
		}
		// getBase() is either BIN, OCT, DEC or HEX
		unsigned char base = getBase();
		// prints the prefix 0b, 0o or 0x depending on base.
		putBasePrefix();
		while (number > 0) {
			// retrieve the last digit of number
			unsigned char digit = (unsigned char)(number % base);
			// convert the last digit of number to a char
			char digitAsChar = toChar(digit);
			// buffer the char in the digit_buffer
			O_Stream::putDigit(digitAsChar);
			// remove the last digit of number
			number /= base;
		}
		// output the digit buffer in reverse order
		flushDigitBuffer();
		return *this;
	}

	O_Stream& O_Stream::operator<< (unsigned int number) {
		if (number == 0) {
			O_Stream::put('0');
			return *this;			
		}
		// getBase() is either BIN, OCT, DEC or HEX
		unsigned char base = getBase();
		// prints the prefix 0b, 0o or 0x depending on base.
		putBasePrefix();
		while (number > 0) {
			// retrieve the last digit of number
			unsigned char digit = (unsigned char)(number % base);
			// convert the last digit of number to a char
			char digitAsChar = toChar(digit);
			// buffer the char in the digit_buffer
			O_Stream::putDigit(digitAsChar);
			// remove the last digit of number
			number /= base;
		}
		// output the digit buffer in reverse order
		flushDigitBuffer();
		return *this;
	}

	O_Stream& O_Stream::operator<< (int number) {
		if (number == 0) {
			O_Stream::put('0');
			return *this;			
		}
		if (number < 0) {
			O_Stream::put(negative_sign);
			number = -number;
		}
		// getBase() is either BIN, OCT, DEC or HEX
		unsigned char base = getBase();
		// prints the prefix 0b, 0o or 0x depending on base.
		putBasePrefix();
		while (number > 0) {
			// retrieve the last digit of number
			unsigned char digit = (unsigned char)(number % base);
			// convert the last digit of number to a char
			char digitAsChar = toChar(digit);
			// buffer the char in the digit_buffer
			O_Stream::putDigit(digitAsChar);
			// remove the last digit of number
			number /= base;
		}
		// output the digit buffer in reverse order
		flushDigitBuffer();
		return *this;
	}

	O_Stream& O_Stream::operator<< (unsigned long number) {
		if (number == 0) {
			O_Stream::put('0');
			return *this;			
		}
		// getBase() is either BIN, OCT, DEC or HEX
		unsigned char base = getBase();
		// prints the prefix 0b, 0o or 0x depending on base.
		putBasePrefix();
		while (number > 0) {
			// retrieve the last digit of number
			unsigned char digit = (unsigned char)(number % base);
			// convert the last digit of number to a char
			char digitAsChar = toChar(digit);
			// buffer the char in the digit_buffer
			O_Stream::put(digitAsChar);
			// remove the last digit of number
			number /= base;
		}
		// output the digit buffer in reverse order
		flushDigitBuffer();
		return *this;
	}

	O_Stream& O_Stream::operator<< (long number) {
		if (number == 0) {
			O_Stream::put('0');
			return *this;			
		}
		if (number < 0) {
			O_Stream::put(negative_sign);
			number = -number;
		}
		// getBase() is either BIN, OCT, DEC or HEX
		unsigned char base = getBase();
		// prints the prefix 0b, 0o or 0x depending on base.
		putBasePrefix();
		while (number > 0) {
			// retrieve the last digit of number
			unsigned char digit = (unsigned char)(number % base);
			// convert the last digit of number to a char
			char digitAsChar = toChar(digit);
			// buffer the char in the digit_buffer
			O_Stream::putDigit(digitAsChar);
			// remove the last digit of number
			number /= base;
		}
		// output the digit buffer in reverse order
		flushDigitBuffer();
		return *this;
	}

	O_Stream& endl (O_Stream& os) {
		os << '\n';
		os.flush();
		return os;
	}

	O_Stream& bin (O_Stream& os) {
		os.setBase(O_Stream::BIN);
		return os;
	}

	O_Stream& oct (O_Stream& os) {
		os.setBase(O_Stream::OCT);
		return os;
	}

	O_Stream& dec (O_Stream& os) {
		os.setBase(O_Stream::DEC);
		return os;
	}

	O_Stream& hex (O_Stream& os) {
		os.setBase(O_Stream::HEX);
		return os;
	}

	O_Stream& el (O_Stream& os) {
		os.flush();
		return os;
	}
