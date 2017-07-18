#include <iostream>
#include <string>
using namespace std;

string ConvertBase(const string& num_as_string, int b1, int b2);
string ConstructFromBase(int num_as_int, int base);

string ConvertBase(const string& num_as_string, int b1, int b2) {
    bool is_negative = num_as_string.front() == '-'; 
    int num_as_int = 0;
    
    for (unsigned int i = (is_negative? 1 : 0 ); i < num_as_string.size(); ++i) {
        num_as_int *= b1;
        num_as_int += isdigit(num_as_string[i]) ? num_as_string[i] - '0' : num_as_string[i] - 'A' + 10;
    }
    return (is_negative ? "-" : "") + (num_as_int == 0 ? "0": ConstructFromBase(num_as_int, b2));
}    
    
string ConstructFromBase(int num_as_int, int base) { // int to string
    return num_as_int == 0 ? "": ConstructFromBase(num_as_int / base, base) + 
                                (char)(num_as_int % base >= 10 ? num_as_int % base + 'A' - 10 : num_as_int % base + '0' );
}

int main()
{
    cout << ConvertBase("2", 10, 2) << endl;
}
