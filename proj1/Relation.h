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
    Relation(std::string name, std::set<Tuple> tuples, Header columnName){
        this->name = name;
        this->tuples = tuples;
        this->columnName = columnName;
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
    int GetTupleSize(){return this->tuples.size();}

    Relation* select1(int columnIndex, std::string value);   // (relation column and value to select)
    Relation* select2(int columnIndex1, int columnIndex2);   // (relation columns to select on same values)
    Relation* project(std::vector<int> colsToProject);       // (the columns to keep)
    Relation* rename(std::vector<std::string> newColNames);  // (defines the new header)
    Relation* join(Relation other);
    bool Union(Relation r);


    std::vector<std::string> matchIndex(Header h1, Header h2){
        std::vector<std::string> matched;
        for (unsigned int i = 0; i < h1.GetColNames().size(); i++){
            for (unsigned int j = 0; j < h2.GetColNames().size(); j++){
                if (h1.GetColNames()[i] == h2.GetColNames()[j]){
                    matched.push_back(h1.GetColNames()[i]);
                }
            }
        }
        return matched;
    }
    Header combineHeaders(Header h1, Header h2);
    bool isJoinable(Tuple t1, Tuple t2, Header h1, Header h2);
    Tuple combineTuples(Tuple t1, Tuple t2, Header h2, std::vector<std::string> val);

    std::string toString();

    friend std::ostream& operator<<(std::ostream& os, Relation& relation){
        os << relation.toString();
        return os;
    }

private:
    std::set<Tuple> tuples;
    std::string name;
    Header columnName;
};


#endif //PROJ1_RELATION_H
