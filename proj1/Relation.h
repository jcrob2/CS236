//
// Created by jared on 11/1/2022.
//

#ifndef PROJ1_RELATION_H
#define PROJ1_RELATION_H
#include <set>
#include "Header.h"
#include "Tuple.h"

class Relation {
public:

    Relation() = default;
    Relation(std::string name, Header columnNames){
        this->name=name;
        this->columnName=columnNames;
    }
    //Copy constructor - I think it works
    Relation(const Relation* r){
        this->name = r->name;
        this->columnName = r->columnName;
        this->tuples = r->tuples;
    }
    void SetName(std::string n){this->name=n;}
    std::string GetName(){return name;}

    void SetHeader(Header h){this->columnName=h;}
    Header GetHeader(){return columnName;}
    void AddTuple(Tuple newTuple){tuples.insert(newTuple);}

    Relation select1(int columnIndex, std::string value);   // (relation column and value to select)
    Relation select2(int columnIndex1, int columnIndex2);   // (relation columns to select on same values)
    Relation project(std::vector<int> colsToProject);       // (the columns to keep)
    Relation rename(std::vector<std::string> newColNames);  // (defines the new header)
    //Relation join(Relation other);

private:
    std::set<Tuple> tuples;
    std::string name;
    Header columnName;
};


#endif //PROJ1_RELATION_H
