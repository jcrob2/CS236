#ifndef PROJ1_DATALOGPROGRAM_H
#define PROJ1_DATALOGPROGRAM_H


class DatalogProgram {
    std::string toString() const {}

    friend std::ostream& operator<< (std::ostream& os, const DatalogProgram& dp){
        os << dp.toString();
        return os;
    }
};


#endif //PROJ1_DATALOGPROGRAM_H
