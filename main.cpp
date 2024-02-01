#include <iostream>
#include <unordered_map>

int romanToInt(const std::string& s) {
    std::unordered_map<char, int> romanValues = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };

    int result = romanValues[s.back()];
    int prev_value = result;

    for (int i = s.length() - 2; i >= 0; i--) {
        int curr_value = romanValues[s[i]];
        result += (prev_value > curr_value) ? -curr_value : curr_value;
        prev_value = curr_value;
    }

    return result;
}

int main() {
    std::string rom_num; 
    std::cout << "Enter Roman Numeral: ";
    std::cin >> rom_num;
    int decimalValue = romanToInt(rom_num);

    
    std::cout << "Decimal Value: " << decimalValue << std::endl;

    return 0;
}
