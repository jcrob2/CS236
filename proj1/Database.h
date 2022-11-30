//
// Created by jared on 11/1/2022.
//

#ifndef PROJ1_DATABASE_H
#define PROJ1_DATABASE_H
#include <map>
#include "Relation.h"

class Database {
public:
    void AddRelation(Relation newRelation){relations.insert({newRelation.GetName(), newRelation});}
    Relation* GetRelation(std::string relationName) {return &relations.at(relationName);}

    //Create copy and return that ... I think it works
    Relation* GetRelationCopy(std::string relationName){
        Relation* r = &relations.at(relationName);
        return new Relation(r);
    }

private:
    std::map<std::string, Relation> relations;
};


#endif //PROJ1_DATABASE_H
