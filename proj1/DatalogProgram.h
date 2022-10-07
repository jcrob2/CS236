#ifndef PROJ1_DATALOGPROGRAM_H
#define PROJ1_DATALOGPROGRAM_H
#include "Predicate.h"
#include "Rule.h"
#include <iostream>
#include <sstream>
#include <set>


class DatalogProgram {
private:
    std::vector<Predicate*> schemes;
    std::vector<Predicate*> facts;
    std::vector<Predicate*> queries;
    std::vector<Rule*> rules;
    std::set<std::string> domain;
public:
    DatalogProgram(DatalogProgram* dp){
        this->schemes = dp->schemes;
        this->facts = dp->facts;
        this->queries = dp->queries;
        this->rules = dp->rules;
        this->domain = dp->domain;
    }

    DatalogProgram(){}

    std::vector<Predicate*> getSchemes(){ return schemes;}
    std::vector<Predicate*> getFacts(){ return facts;}
    std::vector<Predicate*> getQueries(){return queries;}
    std::vector<Rule*> getRules(){return rules;}
    std::set<std::string> getDomain(){return domain;}

    void setSchemes(Predicate* s){schemes.push_back(s);}
    void setFacts(Predicate* f){facts.push_back(f);}
    void setQueries(Predicate* q){queries.push_back(q);}
    void setRules(Rule* r){rules.push_back(r);}
    void setDomain(){
        for (auto p : facts){
            for (auto q : p->getParameters()){
                this->domain.insert(q->getParameter());
            }
        }
    }

    std::string toString() const {
        std::ostringstream output;
        output << "Schemes(" << this->schemes.size() << "):" << std::endl;
        for (auto p : schemes){
            output << "  " << *p << std::endl;
        }
        output << "Facts(" << this->facts.size() << "):" << std::endl;
        for (auto p : facts){
            output << "  " << *p << "." << std::endl;
        }
        output << "Rules(" << this->rules.size() << "):" << std::endl;
        for (auto p : rules){
            output << "  " << *p << "." << std::endl;
        }
        output << "Queries(" << this->queries.size() << "):" << std::endl;
        for (auto p : queries){
            output << "  " << *p << "?" << std::endl;
        }
        output << "Domain(" << this->domain.size() << "):" << std::endl;
        for (auto p : domain){
            output << "  " << p << std::endl;
        }

        return output.str();
    }

    friend std::ostream& operator<< (std::ostream& os, const DatalogProgram& dp){
        os << dp.toString();
        return os;
    }
};


#endif //PROJ1_DATALOGPROGRAM_H
