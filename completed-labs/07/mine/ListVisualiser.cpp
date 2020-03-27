#include "SLList.hpp"
#include "ListVisualiser.hpp"
#include <iostream>
#include <string>
#include <vector>

ListVisualiser::ListVisualiser(SLList *a) { 
    std::string line1, line2, line3;   // defining line vars 
    
    int len = a -> length();    // get length of SLList

    // iterate through SLList
    for (int i = 0; i <= len - 1; i++) {
        // check if at last element
        // lines 1 & 2
        if (i == len - 1) {
            line1 += "[*|/]";   // box with null val
            line2 += " | ";      // arrow
        }
        else {
            line1 += "[*|*] ----> ";   // continuing box
            line2 += " |          ";   // arrow
        }

        // line 3
        int spaces = 11;    // defining spacing
        std::string val = std::to_string(a -> nth(i)); // converting value in array to string
     
        int totspace = spaces - (val.length());  // calculating the spaces
        
        line3 += " " + val; // adding the value to the line

        for (int j = 0; j < totspace; j++) {
            line3 += " ";   // padding out spaces between values
        }

    }

    // printing out all the lines
    std::cout << line1 << std::endl;
    std::cout << line2 << std::endl;
    std::cout << line3 << std::endl;

}

void ListVisualiser::visualise() {  
}
