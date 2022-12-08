//
// Created by jared on 11/1/2022.
//

#ifndef PROJ1_TUPLE_H
#define PROJ1_TUPLE_H
#include <sstream>
#include <string>
#include <vector>


class Tuple {
public:
    Tuple() = default;
    Tuple(const Tuple& t){this->rowValues = t.rowValues;}
    std::vector<std::string> GetRowVals() {return rowValues;}
    void AddValue(std::string s){rowValues.push_back(s);}
    Tuple(std::vector<std::string> s){this->rowValues=s;}
    bool operator< (const Tuple &rhs) const{
        return rowValues < rhs.rowValues;
    }

    std::string toString(){
        std::ostringstream output;
//        std::string padding = "";
//        for (unsigned int i = 0; i < this->rowValues.size(); i++){
//            if (i == 0){
//                output << std::endl << " ";
//            }
//            output << padding << " " << this->columnName.GetColNames()[i] << "=" << t.GetRowVals()[i];
//            padding = ",";
//        }
        return output.str();
    }

    friend std::ostream& operator<<(std::ostream& os, Tuple& tuple){
        os << tuple.toString();
        return os;
    }
private:
    std::vector<std::string> rowValues;
};


#endif //PROJ1_TUPLE_H
