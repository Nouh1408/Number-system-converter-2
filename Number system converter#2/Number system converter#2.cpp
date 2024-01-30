#include <sstream>
#include <iomanip>
#include <iostream>
#include <bitset>
#include <string>
#include <cmath>

using namespace std;

void decimal_to_binary(int number) {
    cout << "Binary equivalent: " << bitset<8>(number) << endl;
}

void decimal_to_octal(int number) {
    cout << "Octal equivalent: " << oct << number << endl;
}

void decimal_to_hexadecimal(int number) {
    cout << "Hexadecimal equivalent: " << hex << number << endl;
}

void binary_to_decimal(const string& binaryStr) {
    cout << "Decimal Equivalent: " << bitset<8>(binaryStr).to_ulong() << endl;
}

bool is_binary(const string& str) {
    for (char ch : str) {
        if (ch != '0' && ch != '1') {
            return false;
        }
    }
    return true;
}

void determine_number_format(const string& input) {
    istringstream is(input);
    int number;

    if (is >> dec >> number) {
        cout << "Decimal Format" << endl;
    }
    else if (is.clear(), is.seekg(0), is_binary(input)) {
        cout << "Binary Format" << endl;
    }
    else if (is.clear(), is.seekg(0), is >> oct >> number) {
        cout << "Octal Format" << endl;
    }
    else if (is.clear(), is.seekg(0), is >> hex >> number) {
        cout << "Hexadecimal Format" << endl;
    }
    else {
        cout << "Invalid Format" << endl;
    }
}

int main() {
    int option, number;
    string input;

    cout << "Enter a number: ";
    cin >> input;

    determine_number_format(input);

    cout << "Choose the conversion:" << endl;
    cout << "1. Decimal to Binary" << endl;
    cout << "2. Decimal to Octal" << endl;
    cout << "3. Decimal to Hexadecimal" << endl;
    cout << "4. Binary to Decimal" << endl;
    cin >> option;

    istringstream input_stream(input);
    input_stream >> dec >> number;

    switch (option) {
    case 1:
        decimal_to_binary(number);
        break;
    case 2:
        decimal_to_octal(number);
        break;
    case 3:
        decimal_to_hexadecimal(number);
        break;
    case 4:
        if (is_binary(input)) {
            binary_to_decimal(input);
        }
        else {
            cout << "Invalid binary input!" << endl;
        }
        break;
    default:
        cout << "Invalid option!" << endl;
        break;
    }

    return 0;
}
