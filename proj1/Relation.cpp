#include "Relation.h"
#include <sstream>

Relation* Relation::select1(int columnIndex, std::string value) {
    std::set<Tuple> tup;
    for (Tuple t:this->tuples){
        if (t.GetRowVals()[columnIndex] == value){
            tup.insert(t);
        }
    }
    Relation* rel = new Relation(this->name, tup, this->columnName);
    return rel;
}

Relation* Relation::select2(int columnIndex1, int columnIndex2) {
    std::set<Tuple> tup;
    for (Tuple t:this->tuples){
        if(t.GetRowVals()[columnIndex1] == t.GetRowVals()[columnIndex2]){
            tup.insert(t);
        }
    }
    Relation* rel = new Relation(this->name, tup, this->columnName);
    return rel;
}

Relation* Relation::project(std::vector<int> colsToProject) {
    std::set<Tuple> tup;
    Header* h = new Header();

    for (auto x: colsToProject){
        h->AddName(this->columnName.GetColNames()[x]);
    }
    for (Tuple ts: this->tuples) {
        Tuple* t = new Tuple();
        for (auto x: colsToProject){
            t->AddValue(ts.GetRowVals()[x]);//columnName.GetColNames()[x]);
        }
        tup.insert(*t);
    }
    Relation* rel = new Relation(this->name, tup, *h);
    return rel;
}

Relation* Relation::rename(std::vector<std::string> newColNames) {
    Header* h = new Header(newColNames);
    Relation* rel = new Relation(this->name, this->tuples, *h);
    return rel;
}

//TODO FINISH THIS - Maybe done?
Relation* Relation::join(Relation other){
    /* create new relation using the combineHeaders() function*/
    Relation* newRel = new Relation(this->name, combineHeaders(this->columnName, other.columnName));
    if (this->tuples.size() == 0){
        for (auto const & z : other.tuples){
            newRel->tuples.insert(z);
        }
    }
    else {
        /*create a vector of strings that contain the column names that are the same for both*/
        std::vector<std::string> match = matchIndex(this->columnName, other.columnName);

        for (auto const &t: this->tuples) {
            for (auto const &t2: other.tuples) {
                if (isJoinable(t, t2, this->columnName, other.columnName)) {
                    Tuple newT = combineTuples(t, t2, other.columnName, match);
                    newRel->AddTuple(newT);
                }
            }
        }
    }
    return newRel;
}

//TODO Verify Union works - maybe done?
bool Relation::Union(Relation r){
//    Relation* newRel = new Relation(this);
//    for (auto const & t : r.tuples){
//        newRel->tuples.insert(t);
//    }
    bool added = false;
    for (auto const & t : r.tuples){
        if (this->tuples.insert(t).second){
            added = true;
        }
    }
    return added;
}

//TODO Verify combineHeaders works
Header Relation::combineHeaders(Header h1, Header h2) {
    std::vector<std::string> svec = h1.GetColNames();
    Header* newHeader = new Header(svec);
    std::vector<std::string> svec2 = h2.GetColNames();
    for (auto i : svec2){
        if (newHeader->checkVal(i) == false){
            newHeader->AddName(i);
        }
    }
    return *newHeader;
}

//TODO Verify isJoinable works
bool Relation::isJoinable(Tuple t1, Tuple t2, Header h1, Header h2) {
    for (unsigned int i = 0; i < h1.GetColNames().size(); i++){
       for (unsigned int j = 0; j < h2.GetColNames().size(); j++){
           if (h1.GetColNames()[i] == h2.GetColNames()[j]){
               if (t1.GetRowVals()[i] != t2.GetRowVals()[j]){
                   return false;
               }
           }
       }
    }
    return true;
}

//TODO Verify combineTuples() works
Tuple Relation::combineTuples(Tuple t1, Tuple t2, Header h2, std::vector<std::string> val) {
    /*Create a new tuple that contains the values of t1*/
    Tuple* nt = new Tuple(t1);

    /*Iterate through all values of t2*/
    for (unsigned int i = 0; i < t2.GetRowVals().size(); i++){
        /*create a bool that indicates if the current value in t2 can be added to nt*/
        bool canAdd = true;
        /* iterate through the vector of strings that contain the columnNames
         * that are the same and don't need to be added twice and check if
         * it matches the corresponding value in h2 that lines up to t2*/
        for (const auto & v : val){
            if (h2.GetColNames()[i] == v){
                canAdd = false;
            }
        }
        if (canAdd == true){
            nt->AddValue(t2.GetRowVals()[i]);
        }
    }
    return *nt;
}

std::string Relation::toString() {
    std::ostringstream output;
    for (auto t: this->tuples){
        std::string padding = "";
        for (unsigned int i = 0; i < t.GetRowVals().size(); i++){
            if (i == 0){
                output << std::endl;
            }
            output << padding << " " << this->columnName.GetColNames()[i] << "=" << t.GetRowVals()[i];
            padding = ",";
        }
    }
    output << std::endl;
    return output.str();
}