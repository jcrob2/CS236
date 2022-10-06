#ifndef PROJ1_DATALOGPROGRAM_H
#define PROJ1_DATALOGPROGRAM_H
#include "Predicate.h"


class DatalogProgram {
private:
    std::vector<Predicate*> schemes;
    std::vector<Predicate*> facts;
    std::vector<Predicate*> queries;
    std::vector<Predicate*> rules;
public:
    std::string toString() const {}

    std::vector<Predicate*> getSchemes(){ return schemes;}
    std::vector<Predicate*> getFacts(){ return facts;}
    std::vector<Predicate*> getQueries(){return queries;}
    std::vector<Predicate*> getRules(){return rules;}

    friend std::ostream& operator<< (std::ostream& os, const DatalogProgram& dp){
        os << dp.toString();
        return os;
    }
};


#endif //PROJ1_DATALOGPROGRAM_H
