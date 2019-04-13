/**
 * CSC232 Data Structures
 * Missouri State University
 *
 * @file    XyzLanguageProcessor.cpp
 * @authors Jim Daehn <jdaehn@missouristate.edu>
 *          Shannon Campbell <sfc489@live.missouristate.edu>
 * @brief   XyzLanguageProcessor implementation.
 */

#include "XyzLanguageProcessor.h"

bool csc232::XyzLanguageProcessor::isValid(const std::string &word) const {

    std::string middle = word.substr(0, word.length() - 1);

    //base case, any string less than 2 letters returns false
    if (word.length() <= 1) {
        return false;
    }
    //checks only first letter
    if (word.at(0) != 'X') {
        return false;
    }
    //loop for recursion
    for (int i = 0; i < word.length() - 1; i++) {

        //check letters after first are X or Z and loop through letters
        if (word.at(i) == 'X' || word.at(i) == 'Z') {
            continue;
        }
        //If y exists, it must be at end
        if (word.at(i) == 'Y' && word.length() - 1 == 'Y') {
            continue;
        }
        else {
            std::string substring = word.substr(1, word.length() - 2);
            return isValid(substring);
        }
    }
}

