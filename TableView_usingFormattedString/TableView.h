//
// Created by Hayden Rothman on 7/22/2021.
//

#ifndef FORMATTEDSTRING_FORSALESSYSTEMUI_TABLEVIEW_H
#define FORMATTEDSTRING_FORSALESSYSTEMUI_TABLEVIEW_H

#include <vector>
#include <iostream>
#include "stringF.h"

class tableView {
public:
    tableView(size_t P_DISP_CHAR_CAP, std::vector<std::vector<std::string>> p_brdVct) {
        DISPLAY_CHAR_CAP = P_DISP_CHAR_CAP;
        rowCount = p_brdVct.at(0).size();
        columnCount = p_brdVct.size();
        for (auto & i : p_brdVct) {
            std::vector<stringF> newColumnVector;
            for (auto & j : i) {
                stringF newStringF(j, DISPLAY_CHAR_CAP);
                newColumnVector.push_back(newStringF);
            }
            fVector.push_back(newColumnVector);
        }
    }

    const std::vector<std::vector<stringF>> &getFVector() const {
        return fVector;
    }
    stringF& getItem(size_t index_I, size_t index_J)  {
        if (index_I < fVector.size() && index_J < fVector.at(index_J).size()) {
            return fVector.at(index_I).at(index_J);
        }
        std::string tempStr = "empty";
        stringF fStr(tempStr, DISPLAY_CHAR_CAP);
        return fStr;
    }

    void setFVector(const std::vector<std::vector<stringF>> &fVector) {
        tableView::fVector = fVector;
    }
    size_t getRowCount() const {
        return rowCount;
    }
    void setRowCount(size_t rowCount) {
        tableView::rowCount = rowCount;
    }
    size_t getColumnCount() const {
        return columnCount;
    }
    void setColumnCount(size_t columnCount) {
        tableView::columnCount = columnCount;
    }



    size_t getDisplayCharCap() const {
        return DISPLAY_CHAR_CAP;
    }
    void setDisplayCharCap(size_t displayCharCap) {
        DISPLAY_CHAR_CAP = displayCharCap;
    }

    void display() {
        bool title = false;
        displayLine(DISPLAY_CHAR_CAP);
        for (size_t i = 0; i < fVector.size(); ++i) {
            for (size_t j = 0; j < fVector.at(i).size(); ++j) {
                if (i == 1 && !title) {
                    displayLine(DISPLAY_CHAR_CAP);
                    title = true;
                }
                std::cout << " | " << fVector.at(i).at(j).getFString();
            }
            std::cout << " | \n";
        }
        displayLine(DISPLAY_CHAR_CAP);
    }
    void displayLine(size_t p_DIS_CHAR_CAP) {
        for (size_t i = 0; i < fVector.at(0).size(); ++i) {
            for (size_t j = 0; j < p_DIS_CHAR_CAP + 4; ++j) {
                std::cout << "-";
            }
            std::cout << "----";
        }
        std::cout << "\n";
    }


private:
    std::vector<std::vector<stringF>> fVector;
    size_t rowCount;
    size_t columnCount;
    size_t DISPLAY_CHAR_CAP;
};


#endif //FORMATTEDSTRING_FORSALESSYSTEMUI_TABLEVIEW_H
