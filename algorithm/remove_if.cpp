/*
    Author : Xenofon Karamanos
    Date : 24/05/2019
    Time : 15:50
    Description : Showcase std::algorithm::remove_if to delete a specific value from container if a condition is met.

*/
#include <iostream>
#include <algorithm>
#include <iomanip>

void print(const std::vector<int> &vector){
    std::cout << "{ ";

    for (auto num : vector){
        std::cout << num << " ";
    }

    std::cout << "}" << std::endl;
}

bool isEven(int x){
    return (x % 2 == 0);
}
int main() {
    std::cout <<  '\n' << "#### Vector ####";
    std::vector<int> vector1 = {1,2,3,4,5,6,7,8,9,1,2,3,4,5,6,7,8,9};
    std::cout << '\n' << "Original vector" << '\n';
    print(vector1);

    std::cout << '\n' << "Removing elements according to a condition (If it's even, it gets removed)" << '\n';
    std::vector<int>::iterator it = std::remove_if(vector1.begin(),vector1.end(),isEven);
    print(vector1);
    std::cout << std::setw( 2 * (it - vector1.begin()) + 3) << "^" << '\n';
    std::cout << "New End Iterator index: " << it - vector1.begin() <<'\n';

    std::cout <<  '\n' << "#### String ####";
    std::string str1 = "Text\n with\tsome \t  whitespaces\n\n";
    std::cout << '\n' << "2) Removing elements according to a condition (If it's whitespace (tab,space,newline), it gets removed)" << '\n';
    std::cout << '\n' << "Original string:" << '\n' << str1 << '\n';
    std::string::iterator itstring = std::remove_if(str1.begin(),str1.end(),
                                                    [](unsigned char x){return std::isspace(x);});
    std::cout << "New string:\n" << str1;
    std::cout << std::setw(itstring - str1.begin()) << "^" << '\n';
    std::cout << "New End Iterator index: " << itstring - str1.begin() <<'\n';
}
