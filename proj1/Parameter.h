#ifndef PROJ1_PARAMETER_H
#define PROJ1_PARAMETER_H
#include <string>
#include <sstream>

class Parameter {
private:
    std::string parameter;
    bool isConstant;
public:
    Parameter(){}
    Parameter(std::string input){
        this->parameter = input;
    }
    Parameter(std::string input, bool constant){
        this->parameter = input;
        this->isConstant = constant;
    }

    std::string getParameter(){return parameter;}
    void setParameter(std::string input){parameter = input;}


    bool IsConstant(){return isConstant;}

    std::string toString() const {
        std::ostringstream output;
        output << this->parameter;

        return output.str();
    }

    friend std::ostream& operator<< (std::ostream& os, const Parameter& par){
        os << par.toString();
        return os;
    }
};


#endif //PROJ1_PARAMETER_H
