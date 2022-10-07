#ifndef PROJ1_DATALOGPROGRAM_H
#define PROJ1_DATALOGPROGRAM_H
#include "Predicate.h"
#include "Rule.h"


class DatalogProgram {
private:
    std::vector<Predicate*> schemes;
    std::vector<Predicate*> facts;
    std::vector<Predicate*> queries;
    std::vector<Rule*> rules;
public:
    std::string toString() const {}

    std::vector<Predicate*> getSchemes(){ return schemes;}
    std::vector<Predicate*> getFacts(){ return facts;}
    std::vector<Predicate*> getQueries(){return queries;}
    std::vector<Rule*> getRules(){return rules;}

    void setSchemes(Predicate* s){schemes.push_back(s);}
    void setFacts(Predicate* f){facts.push_back(f);}
    void setQueries(Predicate* q){queries.push_back(q);}
    void setRules(Rule* r){rules.push_back(r);}

    friend std::ostream& operator<< (std::ostream& os, const DatalogProgram& dp){
        os << dp.toString();
        return os;
    }
};


#endif //PROJ1_DATALOGPROGRAM_H
