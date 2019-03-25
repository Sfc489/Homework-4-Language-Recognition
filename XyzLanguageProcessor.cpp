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

    //variable for excluding first and last letters
    std::string middle = word.substr(0, word.length() - 1);

    //base case, any string less than 2 letters returns false
    if (word.length() <= 1) {
        return false;
    }

    //loop for recursion
    for (int i = 0; i < word.length(); i++) {
        //checks only first letter
        if (word.at(0) != 'X') {
            return false;
        }
        //check letters not first and last are X or Z and loop through letters
        if (middle[i] == 'X' || middle[i] == 'Z') {
            if (word.length() - 1 == 'Y' && word.length() - 1 == 'X' && word.length() - 1 == 'Z') {
                return true;
            } //makes sure last letter is Y
            else return isValid(word);
        }
    }
}
