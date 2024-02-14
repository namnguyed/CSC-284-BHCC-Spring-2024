#include <iostream>
using namespace std;
typedef unsigned char byte;

/**
 * @brief print an 8bit (byte) character (e.g. 01001100)
 * @param a the byte to print
 * @param os the output stream (cout or file ostream)
*/
void printByte(byte a, ostream& os) {
	for (int i = 7; i >= 0; i--) {
		os << ((a >> i) & 1);
	}
}
/**
 * @brief get 8 bits from the user
 * @param os output (cout or a file ostream)
 * @param is input (cin or a file istream)
 * @return character holding the 8 bits
*/
byte getByte(ostream& os, istream& is) {
	char digit;
	short intVal;
	char byteVal = NULL;
	os << "Enter an 8-bit number:";
	for (auto i = 0; i < 8; i++) {
		is >> digit;
		intVal = digit - '0'; // convert to char to number
		while (intVal < 0 || intVal > 1) {
			os << "invalid value. try again (0 or 1): ";
			is >> digit;
			intVal = digit - '0';
		}
		byteVal += (intVal << (7 - i));
	}
	return byteVal;
}
/**
 * @brief function to create mask with only iflag bit set
 * @param iflag  which bit (from right) to set
 * @return 8-bit (1byte) character with that bit set
*/
char createMask(short iflag) {
	return (1 << iflag);
}

/**
 * @brief function to determine if a bit is set
 * @param iflag which bit (from right, count from 0) to test
 * @return true if set
*/
bool isSet(short iflag, byte byteString) {
	return (byteString & (1 << iflag)) != 0;
}
/**
 * @brief convert byteString to short value
 * @param byteString byte (char) to convert to value
 * @return value
*/
short getValue(byte byteString) {
	short value = 0;
	for (int i = 0; i < 8; i++) {
		if (isSet(i, byteString)) {
			value += (1 << i);
		}
	}
	return value;
}
/**
 * @brief convert value to a byteString
 * @param value value to convert (0-255)
 * @return character byteString
*/
byte convertByte(short value) {
	byte byteString = 0;
	for (int i = 0; i < 8; i++) {
		if (value & (1 << i)) {
			byteString |= (1 << i);
		}
	}
	return byteString;
}
int main() {
	byte byteString;
	short bitToCheck;
	short value;
	byteString = getByte(cout, cin);
	printByte(byteString, cout);
	cout << "\n\nEnter a bit (from right) to check: ";
	cin >> bitToCheck;
	while (bitToCheck < 0 || bitToCheck > 7) {
		cout << "\nThat is not a valid number (0-7 are valid).";
		cout << "\nEnter a bit (from right) to check: ";
		cin >> bitToCheck;
	}
	cout << boolalpha;
	cout << "Is the " << bitToCheck << " bit from the right set? ";
	cout << isSet(bitToCheck, byteString) << endl;
	cout << "The value of this number is : " << getValue(byteString) << endl;
	cout << "Enter a number to convert to binary (0-255): ";
	cin >> value;
	while (value < 0 || value > 255) {
		cout << value << " is not valid.  Please enter a number to convert to binary (0-255): ";
		cin >> value;
	}
	byteString = convertByte(value);
	printByte(byteString, cout);
	return 0;
}
