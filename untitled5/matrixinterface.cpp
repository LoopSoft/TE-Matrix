#include "matrixinterface.h"

MatrixInterface::MatrixInterface()
{

}

MatrixInterface::~MatrixInterface()
{


}

bool MatrixInterface::hasBeenDeclared(std::string Nome)
{
    bool ret = 0;
    for(unsigned i = 0; i < this->NomeMat.size(); ++i)
    {
        if(Nome == this->NomeMat[i])
            return 1;
    }
    return ret;
}

void MatrixInterface::append(LinAlg::Matrix<double> Matrix, std::string Nome)
{
    if(!hasBeenDeclared(Nome))
    {
        this->MemoriaMat.push_back(Matrix);
        this->NomeMat.push_back(Nome);
    }
    else
    {
        changeValue(Matrix, Nome);
    }
}

void MatrixInterface::changeValue(LinAlg::Matrix<double> NewMat, std::string Nome)
{
    if(hasBeenDeclared(Nome))
    {
        for(unsigned i = 0; i < this->NomeMat.size(); ++i)
        {
            if(Nome == this->NomeMat[i])
            {
                this->MemoriaMat[i] = NewMat;
                break;
            }
        }
    }
}

LinAlg::Matrix<double> MatrixInterface::find(std::string Nome)
{
    LinAlg::Matrix<double> mat;
    for(unsigned i = 0; i < this->NomeMat.size(); ++i)
    {
        if(Nome == this->NomeMat[i])
            mat = this->MemoriaMat[i];
    }
    return mat;
}

bool MatrixInterface::identifyEquality(std::string str)
{
    if(str.find("==") != std::string::npos) return 0;
    if(str.find("!=") != std::string::npos) return 0;
    if(str.find("+=") != std::string::npos) return 0;
    if(str.find("-=") != std::string::npos) return 0;
    if(str.find("^=") != std::string::npos) return 0;
    if(str.find("/=") != std::string::npos) return 0;
    if(str.find("*=") != std::string::npos) return 0;
    if(str.find("=")  != std::string::npos) return 1;

    return 0;
}

std::string MatrixInterface::AtributeEquality(std::string str_)
{
    std::string str;
    for(unsigned i = 0; i < str_.length(); ++i){
        if(str_[i] != ' ')
            str += str_[i];
    }

    std::size_t pos = str.find('=');

    if(this->hasBeenDeclared(str.substr(pos+1))){
        LinAlg::Matrix<double> A = this->find(str.substr(pos+1));
        this->append(A,str.substr(0,pos));
        return str.substr(0,pos);
    }

    this->append( str.substr(pos+1) , str.substr(0,pos));
    return str.substr(0,pos);
}

LinAlg::Matrix<double> MatrixInterface::Operation(std::string str_)
{
    std::string str;
    for(unsigned i = 0; i < str_.length(); ++i){
        if(str_[i] != ' ')
            str += str_[i];
    }

    if(str.find("==") != std::string::npos) {
        std::size_t pos = str.find('==');
        LinAlg::Matrix<double> A = this->find(str.substr(0,pos-1));
        LinAlg::Matrix<double> B = this->find(str.substr(pos+1));
        return  A == B;
    }else
    if(str.find("!=") != std::string::npos) {
        std::size_t pos = str.find('!=');
        LinAlg::Matrix<double> A = this->find(str.substr(0,pos-1));
        LinAlg::Matrix<double> B = this->find(str.substr(pos+1));
        return  A != B;
    }else
    if(str.find("+=") != std::string::npos) {
        std::size_t pos = str.find('+=');
        LinAlg::Matrix<double> A = this->find(str.substr(0,pos-1));
        LinAlg::Matrix<double> B = this->find(str.substr(pos+1));
        if(A.getNumberOfColumns() == 1 && A.getNumberOfRows() == 1 &&
           B.getNumberOfColumns() == 1 && B.getNumberOfRows() == 1)
        {
            A = LinAlg::Matrix<double>(A(1,1) + B(1,1));
        }
        else if(A.getNumberOfColumns() == 1 && A.getNumberOfRows() == 1)
        {
            A = (B + A(1,1));
        }
        else if(B.getNumberOfColumns() == 1 && B.getNumberOfRows() == 1)
        {
            A = (A + B(1,1));
        }
        else
        {
            A = A + B;
        }
        this->append(A,str.substr(0,pos-1));
        return  A;
    }else
    if(str.find("-=") != std::string::npos) {
        std::size_t pos = str.find('-=');
        LinAlg::Matrix<double> A = this->find(str.substr(0,pos-1));
        LinAlg::Matrix<double> B = this->find(str.substr(pos+1));
        if(A.getNumberOfColumns() == 1 && A.getNumberOfRows() == 1 &&
           B.getNumberOfColumns() == 1 && B.getNumberOfRows() == 1)
        {
            A = LinAlg::Matrix<double>(A(1,1) - B(1,1));
        }
        else if(A.getNumberOfColumns() == 1 && A.getNumberOfRows() == 1)
        {
            A = A(1,1) - B;
        }
        else if(B.getNumberOfColumns() == 1 && B.getNumberOfRows() == 1)
        {
            A = A - B(1,1);
        }
        else
        {
            A = A - B;
        }
        this->append(A,str.substr(0,pos-1));
        return  A;
    }else
    if(str.find("^=") != std::string::npos) {
        std::size_t pos = str.find('^=');
        //return find(str.substr(pos+1)) ^= find(str.substr(0,pos));
        LinAlg::Matrix<double> A = this->find(str.substr(0,pos-1));
        LinAlg::Matrix<double> B = this->find(str.substr(pos+1));
        if(B.getNumberOfColumns() == 1 && B.getNumberOfRows() == 1)
        {
            A ^= int(B(1,1));
            this->append(A,str.substr(0,pos-1));
            return A;
        }
        else
            return LinAlg::Matrix<double>();
    }else
    if(str.find("/=") != std::string::npos) {
        std::size_t pos = str.find('/=');
        LinAlg::Matrix<double> A = this->find(str.substr(0,pos-1));
        LinAlg::Matrix<double> B = this->find(str.substr(pos+1));
        if(A.getNumberOfColumns() == 1 && A.getNumberOfRows() == 1 &&
           B.getNumberOfColumns() == 1 && B.getNumberOfRows() == 1)
        {
            A = LinAlg::Matrix<double>(A(1,1) / B(1,1));
        }
        else if(A.getNumberOfColumns() == 1 && A.getNumberOfRows() == 1)
        {
            A = A(1,1) * (B^-1);
        }
        else if(B.getNumberOfColumns() == 1 && B.getNumberOfRows() == 1)
        {
            A = A / B(1,1);
        }
        else
        {
            A = A / B;
        }
        this->append(A,str.substr(0,pos-1));
        return  A;
    }else
    if(str.find("*=") != std::string::npos) {
        std::size_t pos = str.find('*=');
        LinAlg::Matrix<double> A = this->find(str.substr(0,pos-1));
        LinAlg::Matrix<double> B = this->find(str.substr(pos+1));
        if(A.getNumberOfColumns() == 1 && A.getNumberOfRows() == 1 &&
           B.getNumberOfColumns() == 1 && B.getNumberOfRows() == 1)
        {
            A = LinAlg::Matrix<double>(A(1,1) * B(1,1));
        }
        else if(A.getNumberOfColumns() == 1 && A.getNumberOfRows() == 1)
        {
            A = A(1,1) * B;
        }
        else if(B.getNumberOfColumns() == 1 && B.getNumberOfRows() == 1)
        {
            A = A * B(1,1);
        }
        else
        {
            A = A * B;
        }
        this->append(A,str.substr(0,pos-1));
        return  A;
    }else
    if(str.find("+") != std::string::npos) {
        std::size_t pos = str.find('+');
        LinAlg::Matrix<double> A = this->find(str.substr(0,pos));
        LinAlg::Matrix<double> B = this->find(str.substr(pos+1));
        if(A.getNumberOfColumns() == 1 && A.getNumberOfRows() == 1 &&
           B.getNumberOfColumns() == 1 && B.getNumberOfRows() == 1)
        {
            return LinAlg::Matrix<double>(A(1,1) + B(1,1));
        }
        else if(A.getNumberOfColumns() == 1 && A.getNumberOfRows() == 1)
        {
            return A(1,1) + B;
        }
        else if(B.getNumberOfColumns() == 1 && B.getNumberOfRows() == 1)
        {
            return B(1,1) + A;
        }
        else
            return  A + B;
    }else
    if(str.find("-") != std::string::npos){
        std::size_t pos = str.find('-');
        LinAlg::Matrix<double> A = this->find(str.substr(0,pos));
        LinAlg::Matrix<double> B = this->find(str.substr(pos+1));
        if(A.getNumberOfColumns() == 1 && A.getNumberOfRows() == 1 &&
           B.getNumberOfColumns() == 1 && B.getNumberOfRows() == 1)
        {
            return LinAlg::Matrix<double>(A(1,1) - B(1,1));
        }
        else if(A.getNumberOfColumns() == 1 && A.getNumberOfRows() == 1)
        {
            return A(1,1) - B;
        }
        else if(B.getNumberOfColumns() == 1 && B.getNumberOfRows() == 1)
        {
            return B(1,1) - A;
        }
        else
            return  A - B;
    }else
    if(str.find("*") != std::string::npos) {
        std::size_t pos = str.find('*');
        LinAlg::Matrix<double> A = this->find(str.substr(0,pos));
        LinAlg::Matrix<double> B = this->find(str.substr(pos+1));
        if(A.getNumberOfColumns() == 1 && A.getNumberOfRows() == 1 &&
           B.getNumberOfColumns() == 1 && B.getNumberOfRows() == 1)
        {
            return LinAlg::Matrix<double>(A(1,1) * B(1,1));
        }
        else if(A.getNumberOfColumns() == 1 && A.getNumberOfRows() == 1)
        {
            return A(1,1) * B;
        }
        else if(B.getNumberOfColumns() == 1 && B.getNumberOfRows() == 1)
        {
            return B(1,1) * A;
        }
        else
            return  A * B;
    }else
    if(str.find("^") != std::string::npos){
        std::size_t pos = str.find('^');
        //return find(str.substr(pos+1)) ^ find(str.substr(0,pos));
        LinAlg::Matrix<double> A = this->find(str.substr(0,pos));
        LinAlg::Matrix<double> B = this->find(str.substr(pos+1));
        if(B.getNumberOfColumns() == 1 && B.getNumberOfRows() == 1)
        {
            return A ^ int(B(1,1));
        }
        else
            return LinAlg::Matrix<double>();
    }else
    if(str.find("/") != std::string::npos) {
        std::size_t pos = str.find('/');
        LinAlg::Matrix<double> A = this->find(str.substr(0,pos));
        LinAlg::Matrix<double> B = this->find(str.substr(pos+1));
        if(A.getNumberOfColumns() == 1 && A.getNumberOfRows() == 1 &&
           B.getNumberOfColumns() == 1 && B.getNumberOfRows() == 1)
        {
            return LinAlg::Matrix<double>(A(1,1) / B(1,1));
        }
        else if(A.getNumberOfColumns() == 1 && A.getNumberOfRows() == 1)
        {
            return A(1,1) * (B^-1);
        }
        else if(B.getNumberOfColumns() == 1 && B.getNumberOfRows() == 1)
        {
            return A / B(1,1);
        }
        else
            return  A / B;
    }else
    {
        if(hasBeenDeclared(str)){
            LinAlg::Matrix<double> A = this->find(str);
            return A;
        }else{
            this->append("0", str);
        }
    }

    return LinAlg::Matrix<double>();
}
