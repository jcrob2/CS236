#include "Interpreter.h"
#include <algorithm>

void Interpreter::RunInterpreter() {
    InterpretSchemes();
    InterpretFacts();
    InterpretRules();
    InterpretQueries();
}

Relation* Interpreter::evaluatePredicate(Predicate* p) {
//    std::vector<std::string> vec;
//    for (Parameter* par:p->getParameters()){
//        vec.push_back(par->getParameter());
//    }
//    Header* header = new Header(vec);
//    Relation* relation = new Relation(p->getId(), *header);
//    relation->SetHeader(*header);
//    return relation;


    Relation* rcp = database.GetRelationCopy(p->getId());
    std::vector<Parameter*> q = p->getParameters();
    std::vector<std::string> variables;
    std::map<std::string, int> values;
    std::vector<int> index;

    //std::cout << *p << "?" << " ";

    for (unsigned int i = 0; i<q.size();i++){
        if(q[i]->IsConstant()){
            rcp = rcp->select1(i, q[i]->getParameter());
            //std::cout << std::endl << "Select1: " << *q[i];
        }
        else if (!q[i]->IsConstant()) {
            variables.push_back(q[i]->getParameter());
            values.insert({q[i]->getParameter(), i});

            if (values.find(q[i]->getParameter()) != values.end()){
                rcp = rcp->select2(i,values.at(q[i]->getParameter()));
            }
            //std::cout << std::endl << "Select2: " << *q[i];
        }
    }
    std::vector<std::string> seen;
    for (std::string v:variables){
        if (find(seen.begin(), seen.end(), v) == seen.end()) {
            index.push_back(values.at(v));
            seen.push_back(v);
        }
    }
    rcp=rcp->project(index);
    rcp=rcp->rename(seen);
    return rcp;
}

void Interpreter::InterpretSchemes() {
    for (Predicate scheme:program.getSchemes()){
        std::vector<std::string> vec;
        for (Parameter* par:scheme.getParameters()){
            vec.push_back(par->getParameter());
        }
        Header* header = new Header(vec);
        Relation* relation = new Relation(scheme.getId(), *header);
        relation->SetHeader(*header);
        database.AddRelation(*relation);
    }
}

void Interpreter::InterpretFacts() {
    for (Predicate fact:program.getFacts()){
        std::vector<std::string> vec;
        std::string key = fact.getId();
        for(Parameter* par:fact.getParameters()){
            vec.push_back(par->getParameter());
        }
        Tuple* tuple = new Tuple(vec);
        Relation* r = database.GetRelation(key);
        r->AddTuple(*tuple);
    }
}

Relation* Interpreter::evalRules(){
    Relation* temp;
    for(auto const &r:program.getRules()) {
        std::vector<Relation *> rels;
        Relation *temp = new Relation();
        for (auto const &p: r->getBodyPredicates()) {
            Relation *rcp = evaluatePredicate(p);
            rels.push_back(rcp);
        }

        for (auto const &rel: rels) {
            temp = temp->join(rel);
        }

        std::vector<int> cols;
        for (auto const &a: r->headPredicate->getParameters()) {
            for (unsigned int i = 0; i < temp->GetHeader().GetColNames().size(); i++) {
                if (temp->GetHeader().GetColNames()[i] == a->getParameter()) {
                    cols.push_back(i);
                }
            }
        }
        temp = temp->project(cols);
        temp = temp->rename(r->getHeaderVals());
        temp->SetName(r->headPredicate->getId());
    }
    return temp;
}

//TODO FINISH THIS
void Interpreter::InterpretRules() {
    bool added = false;
    incPasses();
    //Relation* temp = evalRules();

    for(auto const &r:program.getRules()){
        std::vector<Relation*> rels;
        Relation* temp = new Relation();
        for (auto const &p:r->getBodyPredicates()){
            Relation* rcp = evaluatePredicate(p);
            rels.push_back(rcp);
        }

        for (auto const &rel : rels){
            temp = temp->join(rel);
        }

        std::vector<int> cols;
        for (auto const & a : r->headPredicate->getParameters()){
            for (unsigned int i = 0; i < temp->GetHeader().GetColNames().size();i++){
                if (temp->GetHeader().GetColNames()[i] == a->getParameter()){
                    cols.push_back(i);
                }
            }
        }
        temp = temp->project(cols);
        temp = temp->rename(r->getHeaderVals());
        temp->SetName(r->headPredicate->getId());

        added = database.GetRelation(r->headPredicate->getId())->Union(temp);
    }

    if (!added){
        std::cout << "Rule Evaluation" << std::endl;
        for(auto const &r:program.getRules()) {
            std::cout << *r << std::endl;
            //std::cout <<
        }
    }
    if (added){
        InterpretRules();
    }


}

void Interpreter::InterpretQueries() {
    for(auto const &query:program.getQueries()){
        /*Relation rcp = database.GetRelationCopy(query.getId());
        std::vector<Parameter*> q = query.getParameters();
        std::vector<std::string> variables;
        std::map<std::string, int> values;
        std::vector<int> index;

        std::cout << query << "?" << " ";

        for (unsigned int i = 0; i<q.size();i++){
            if(q[i]->IsConstant()){
                rcp = rcp.select1(i, q[i]->getParameter());
                //std::cout << std::endl << "Select1: " << *q[i];
            }
            else if (!q[i]->IsConstant()) {
                variables.push_back(q[i]->getParameter());
                values.insert({q[i]->getParameter(), i});

                if (values.find(q[i]->getParameter()) != values.end()){
                    rcp = rcp.select2(i,values.at(q[i]->getParameter()));
                }
                //std::cout << std::endl << "Select2: " << *q[i];
            }
        }
        std::vector<std::string> seen;
        for (std::string v:variables){
            if (find(seen.begin(), seen.end(), v) == seen.end()) {
                index.push_back(values.at(v));
                seen.push_back(v);
            }
        }
        rcp=rcp.project(index);
        rcp=rcp.rename(seen);*/

        Relation* rcp = evaluatePredicate(query);
        std::cout << *query << "?" << " ";
        if (rcp->GetTupleSize() != 0){
            std::cout << "Yes(" << rcp->GetTupleSize() << ")";
            std::cout << *rcp;
        }
        else{
            std:: cout << "No" << std::endl;
        }
    }
    int one = 1;
}