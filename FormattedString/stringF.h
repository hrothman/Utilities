//
// Created by Hayden Rothman on 7/22/2021.
//

#ifndef FORMATTEDSTRING_FORSALESSYSTEMUI_STRINGF_H
#define FORMATTEDSTRING_FORSALESSYSTEMUI_STRINGF_H

#include <string>

class stringF {
public:

    stringF(std::string& p_rawString, size_t P_DISPLAY_CHAR_CAP) {
        rawString = p_rawString;
        DISPLAY_CHAR_CAP = P_DISPLAY_CHAR_CAP;
        CHARACTER_CAP = 50;
        fString = format(rawString, DISPLAY_CHAR_CAP);
    }
    stringF(const stringF& p_StringF) {
        rawString = p_StringF.rawString;
        DISPLAY_CHAR_CAP = p_StringF.DISPLAY_CHAR_CAP;
        CHARACTER_CAP = p_StringF.CHARACTER_CAP;
        fString = p_StringF.fString;
    }

    std::string& format(std::string& p_rawString, size_t P_DISPLAY_CHAR_CAP) {
        fString = "  ";
        for (size_t i = 0; i < P_DISPLAY_CHAR_CAP; ++i) {
            if (p_rawString.size() > i) {
                fString += p_rawString.at(i);
            }
            else {
                fString += " ";
            }
        }
        if (p_rawString.size() > P_DISPLAY_CHAR_CAP)
            fString += "..";
        else
            fString += "  ";
        return fString;
    }

    const std::string &getRawString() const { return rawString; }
    void setRawString(const std::string &rawString) { stringF::rawString = rawString; }
    const std::string &getFString() const { return fString; }
    void setFString(const std::string &formattedString) { stringF::fString = formattedString; }
    size_t getDisplayCharCap() const { return DISPLAY_CHAR_CAP; }
    void setDisplayCharCap(size_t displayCharCap) { DISPLAY_CHAR_CAP = displayCharCap; }

    bool operator ==(const stringF& passed) {
        if (rawString != passed.rawString || fString != passed.fString || CHARACTER_CAP != passed.CHARACTER_CAP || DISPLAY_CHAR_CAP != passed.DISPLAY_CHAR_CAP) {
            return false;
        }
        return true;
    }
    bool operator !=(const stringF& passed) {
        if (rawString != passed.rawString || fString != passed.fString || CHARACTER_CAP != passed.CHARACTER_CAP || DISPLAY_CHAR_CAP != passed.DISPLAY_CHAR_CAP) {
            return true;
        }
        return false;
    }
    stringF& operator =(const stringF& passed) {
        if (&passed == this)
            return *this;
        this->rawString = passed.rawString;
        this->fString = passed.fString;
        this->CHARACTER_CAP = passed.CHARACTER_CAP;
        this->DISPLAY_CHAR_CAP = passed.DISPLAY_CHAR_CAP;
        return *this;
    }


private:
    std::string rawString;
    std::string fString;
    size_t CHARACTER_CAP;
    size_t DISPLAY_CHAR_CAP;
};


#endif //FORMATTEDSTRING_FORSALESSYSTEMUI_STRINGF_H
