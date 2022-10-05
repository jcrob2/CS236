#ifndef PROJ1_PREDICATE_H
#define PROJ1_PREDICATE_H


class Predicate {
    std::string toString() const {}

    friend std::ostream& operator<< (std::ostream& os, const Predicate& pred){
        os << pred.toString();
        return os;
    }
};


#endif //PROJ1_PREDICATE_H
