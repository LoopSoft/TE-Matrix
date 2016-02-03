#ifndef MATRIXINTERFACE_H
#define MATRIXINTERFACE_H

#include <vector>
#include "SistemasdeControle/headers/primitiveLibs/LinAlg/matrix.h"
#include "QString"

struct opSeparatedString{
    std::string left, right;
};

class MatrixInterface
{

    std::vector< LinAlg::Matrix<double> > MemoriaMat;
    std::vector<std::string> NomeMat;

    bool hasBeenDeclared(std::string Nome);

public:
    MatrixInterface();
    ~MatrixInterface();

    void append(LinAlg::Matrix<double> Matrix, std::string Nome);
    void changeValue(LinAlg::Matrix<double> NewMat, std::string Nome);

    LinAlg::Matrix<double> find(std::string Nome);
    bool identifyEquality(std::string str);
    std::string AtributeEquality(std::string str_);
    LinAlg::Matrix<double> Operation(std::string str_);

};

//#include "matrixinterface.hpp"
#endif // MATRIXINTERFACE_H
