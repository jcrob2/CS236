#include "Interpreter.h"
#include "Graph.h"
#include <algorithm>

void Interpreter::RunInterpreter() {
    InterpretSchemes();
    InterpretFacts();
    InterpretRules();

    std::cout << std::endl << "Schemes populated after " << passes << " passes through the Rules.";
    std::cout << std::endl << std::endl << "Query Evaluation" << std::endl;
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


//TODO FINISH THIS
void Interpreter::InterpretRules() {
    /*
    this->database.SetAdded(false);
    if (passes == 0){
        std::cout << "Rule Evaluation" << std:: endl;
    }
    incPasses();
    //Relation* temp = evalRules();
    for(auto const &r:program.getRules()){
        std::cout << *r << ".";
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

        if (database.GetRelation(r->headPredicate->getId())->Union(temp)){
            this->database.SetAdded(true);
        }
        else {
            if (this->database.GetAdded() == true){
                this->database.SetAdded(true);
            }
            else {
                this->database.SetAdded(false);
            }
        }
    }

//    if (!added){
//        std::cout << "Rule Evaluation" << std::endl;
//        for(auto const &r:program.getRules()) {
//            std::cout << *r << std::endl;
//            for (unsigned int i; i < this->newTups.size(); i++){
//                if (newTups[i]->GetName() == r->headPredicate->getId()){
//                    std::cout << newTups[i];
//                }
//            }
//            //std::cout <<
//        }
//    }
    if (this->database.GetAdded()){
        InterpretRules();
    }

*/
    Graph* forward = new Graph(program.getRules().size());
    Graph* reverse = new Graph(program.getRules().size());
    createAdjLists(forward, reverse);

    std::vector<Node*> postOrder = DFSF(forward);
    std::vector<std::set<Node*>> sccs = RDFSF(reverse, postOrder);

    std::cout << "Dependency Graph" << std:: endl;
    for(auto const &n:forward->GetNodes()){
        std::cout << "R" << n.first << ":";
        std::string buffer = "";
        for(auto const & n2 : n.second->adjacentTo){
            std::cout << buffer << "R" << n2->index;
            buffer = ",";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl << "Rule Evaluation" << std::endl;

    for (auto const & n : sccs){
        RunFixedPoint(n);
    }
}

void Interpreter::RunFixedPoint(std::set<Node*> scc) {
    this->database.SetAdded(false);
//    if (passes == 0){
//        std::cout << "Rule Evaluation" << std:: endl;
//    }
    incPasses();
    //Relation* temp = evalRules();

    if (scc.size() > 1){
        //for ()
    }





    for(auto const &r:program.getRules()){
        std::cout << *r << ".";
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

        if (database.GetRelation(r->headPredicate->getId())->Union(temp)){
            this->database.SetAdded(true);
        }
        else {
            if (this->database.GetAdded() == true){
                this->database.SetAdded(true);
            }
            else {
                this->database.SetAdded(false);
            }
        }
    }
    if (this->database.GetAdded()){
        RunFixedPoint(scc);
    }


}

//TODO Fix weird bug in test case 2,6 where the Dependency graph is out of order
void Interpreter::createAdjLists(Graph *F, Graph* R) {
    for (unsigned int i = 0; i < program.getRules().size(); i++){
        for (auto const &p : program.getRules()[i]->bodyPredicates){
            for (unsigned int j = 0; j < program.getRules().size(); j++){
                if (p->getId() == program.getRules()[j]->headPredicate->getId()){
                    Node* D = F->GetNodes().at(i);
                    Node* C = F->GetNodes().at(j);
                    D->adjacentTo.insert(C);
                    //F->GetNodes().at(i)->adjacentTo.insert(F->GetNodes().at(j));
                    R->GetNodes().at(j)->adjacentTo.insert(R->GetNodes().at(i));
                }
            }
        }
    }
}

std::vector<std::set<Node*>> Interpreter::RDFSF(Graph *G, std::vector<Node*> &postOrder) {
    std::vector<std::set<Node*>> sccs;
    std::vector<Node*> empty;

    G->markNodesUnvisited();
    std::reverse(postOrder.begin(), postOrder.end());
    for (auto n : postOrder){
        n->visited = false;
    }

    for (auto n : postOrder){
        sccs.push_back(DFS(n, empty));
    }
    return sccs;
}

std::vector<Node*> Interpreter::DFSF(Graph *G) {
    std::vector<Node*> postOrder;
    G->markNodesUnvisited();

    for (auto n: G->GetNodes()){
        DFS(n.second, postOrder);
    }

    return postOrder;
}

std::set<Node*> Interpreter::DFS(Node *N1, std::vector<Node *> &postOrder) {
    std::set<Node*> output;
    N1->visited = true;

    for(auto n : N1->adjacentTo){
        std::set<Node*> temp;
        if (n->visited == false){
            std::set<Node*> result = DFS(n, postOrder);
            std::merge(output.begin(), output.end(), result.begin(), result.end(), std::inserter(temp, temp.begin()));
            output = temp;
        }
    }

    postOrder.push_back(N1);
    output.insert(N1);
    return output;
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
}