//
// Created by jared on 11/1/2022.
//

#ifndef PROJ1_TUPLE_H
#define PROJ1_TUPLE_H
#include <string>
#include <vector>


class Tuple {
public:
    Tuple() = default;
    Tuple(std::vector<std::string> s){this->rowValues=s;}
    bool operator< (const Tuple &rhs) const{
        return rowValues < rhs.rowValues;
    }
private:
    std::vector<std::string> rowValues;
};


#endif //PROJ1_TUPLE_H
