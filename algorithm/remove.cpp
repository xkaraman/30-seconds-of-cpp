/*
    Author : Xenofon Karamanos
    Date : 24/05/2019
    Time : 12:17
    Description : Showcase std::algorithm::remove to delete a specific value from container.

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

int main() {
    // std::cout << std::string(80, '#' ) << '\n';
    // std::cout << "# std::remove does NOT change the physical size of the container               #" << '\n';
    // std::cout << "# It shifts the values that aren't removed in the beginning of container       #\n"
    //              "# returning a new end iterator                                                 #" << '\n';
    // std::cout << "# Values beyond the new end iterator and the physical end have unspecified     #"
    //              "# values but are still dereferenceable                                         #" << '\n';
    // std::cout << std::string( 80, '#' ) << '\n';

    std::cout <<  '\n' << "#### Vector ####";
    std::vector<int> vector1 = {1,2,3,4,5,6,7,8,9,1,2,3,4,5,6,7,8,9};
    std::cout << '\n' << "Original vector" << '\n';
    print(vector1);

    std::cout << '\n' << "Removing elements with value: 3" << '\n';
    std::vector<int>::iterator it;
    it = std::remove(vector1.begin(),vector1.end(), 3);
    print(vector1);
    std::cout << std::setw( 2 * (it - vector1.begin()) + 3) << "^" << '\n';
    std::cout << "New End Iterator index: " << it - vector1.begin() <<'\n';

    // Use erase-remove idiom to change the actaul physical size of the container
    std::cout << "\nErase leftovers of std::remove and get the actual container with only the values that are not removed" << '\n';
    vector1.erase(it, vector1.end());
    print(vector1);

    std::cout <<  '\n' << "#### String ####";
    std::string string1 = "Text with some   spaces";
    std::cout << '\n' << "Original string:" << '\n' << string1 << '\n';
    std::cout << '\n' << "Removing elements with value: e" << '\n';
    std::string::iterator itstring = std::remove(string1.begin(), string1.end(), 'e');
    std::cout << "New string:\n" << string1 << '\n';
    std::cout << std::setw(itstring - string1.begin()) << "^" << '\n';
    std::cout << "New End Iterator index: " << it - vector1.begin() <<'\n';

    return 0;
}
