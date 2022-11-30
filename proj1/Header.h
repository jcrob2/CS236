//
// Created by jared on 11/1/2022.
//

#ifndef PROJ1_HEADER_H
#define PROJ1_HEADER_H
#include <vector>
#include <string>

class Header {
public:
    Header() = default;
    Header(std::vector<std::string> v){this->columnNames=v;}
    void AddName(std::string val){columnNames.push_back(val);}
    std::vector<std::string> GetColNames(){return columnNames;}
    bool checkVal(std::string v){
        for (auto i : columnNames){
            if (i == v){
                return true;
            }
        }
        return false;
    }
private:
    std::vector<std::string> columnNames;
};


#endif //PROJ1_HEADER_H
