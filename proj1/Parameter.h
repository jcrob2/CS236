#ifndef PROJ1_PARAMETER_H
#define PROJ1_PARAMETER_H
#include <string>

class Parameter {
private:
    std::string parameter;
public:
    Parameter(){}
    Parameter(std::string input){
        parameter = input;
    }

    std::string getParameter(){return parameter;}
    void setParameter(std::string input){parameter = input;}


    std::string toString() const {}

    friend std::ostream& operator<< (std::ostream& os, const Parameter& par){
        os << par.toString();
        return os;
    }
};


#endif //PROJ1_PARAMETER_H
