/*!*************************************************************************
****
\file matrix.hpp
\author Yugendren S/O Sooriya Moorthi
\par DP email: 2201512@sit.singaporetech.edu.sg
\par Course: RSE 1202
\par Section:
\par Assignment 8
\date 17-03-2023
\brief
This program contains the header file for the matrix 
****************************************************************************
***/
#include <iostream>
#include <vector>
#include <complex>

namespace hlp2{
    template<typename T> class matrix {
        public:
            // Constructors
            matrix();
            matrix(size_t rows, size_t cols);
            matrix(size_t rows, size_t cols, const T& val);

            // Deconstructors
            //~matrix();

            // Copy constructor
            matrix(const matrix<T>& other);

            // Assignment operator
            matrix<T>& operator=(const matrix<T>& other);

            // Comparison operator
            bool operator==(const matrix<T>& other) const;
            bool operator!=(const matrix<T>& other) const;

            // Arithmetic operators
            matrix<T> operator+(const matrix<T>& other) const;
            matrix<T>& operator+=(const matrix<T>& other);
            matrix<T> operator-(const matrix<T>& other) const;
            matrix<T>& operator-=(const matrix<T>& other);
            matrix<T> operator*(const matrix<T>& other) const;
            matrix<T>& operator*=(const matrix<T>& other);
            matrix<T> operator*(const T& scalar) const;
            matrix<T>& operator*=(const T& scalar);

            template<typename U> friend matrix<std::complex<T>> operator*(const std::complex<T>& scalar, matrix<std::complex<T>>& mat);
            template<typename U> friend matrix<T> operator*(const T& scalar, matrix<T>& mat);

            // Element access operator
            std::vector<T>& operator[](size_t index);

            // Output operator
            template<typename U> friend std::ostream& operator<<(std::ostream& os, const matrix<U>& mat);

            size_t Rows() const;
            size_t Cols() const;

            


        private:
            size_t rows_;
            size_t cols_;
            std::vector<std::vector<T>> data_;
    };
     /*!*****************************************************************************
	\brief
	  function will return rows form funtion
	\param nil
	  
	\return size_t
	  reutrn rows
	*******************************************************************************/
    template<typename T> size_t matrix<T>::Rows() const { return rows_; }
    /*!*****************************************************************************
	\brief
	  function will return cols form funtion
	\param nil
	  
	\return size_t
	  reutrn cols
	*******************************************************************************/
    template<typename T> size_t matrix<T>::Cols() const { return cols_; }
    /*!*****************************************************************************
	\brief
	  ctor
	\param nil
	  
	\return nil
	*******************************************************************************/
    template<typename T> matrix<T>::matrix() : rows_(0), cols_(0), data_(nullptr){}
    /*!*****************************************************************************
	\brief
	  2nd ctor
	\param size_t rows, size_t cols
	  
	\return nil
	*******************************************************************************/
    template<typename T> matrix<T>::matrix(size_t rows, size_t cols){
        this->rows_ = rows;
        this->cols_ = cols;
        data_.resize(rows);
        for(size_t i = 0; i < rows; i++)
            data_[i].resize(cols);
    }
    /*!*****************************************************************************
	\brief
	  3rd ctor
	\param size_t rows, size_t cols, const T& val
	  
	\return nil
	*******************************************************************************/
    template<typename T> matrix<T>::matrix(size_t rows, size_t cols, const T& val){
        this->rows_ = rows;
        this->cols_ = cols;
        data_.resize(rows);
        for(size_t i = 0; i < rows; i++)
            data_[i].resize(cols, val);
    }
    /*!*****************************************************************************
	\brief
	  4th ctor
	\param const matrix<T>& other
	  
	\return nil
	*******************************************************************************/
    template<typename T> matrix<T>::matrix(const matrix<T>& other){
        rows_ = other.rows_;
        cols_ = other.cols_;
        data_ = other.data_;
    }
    /*!*****************************************************************************
	\brief
    copy assignment
	\param const matrix<T>& other
	  
	\return refrence to this
	*******************************************************************************/
    template<typename T> matrix<T>& matrix<T>::operator=(const matrix<T>& other){
        if (this != &other) {
            if (rows_ != other.rows_ || cols_ != other.cols_) {
                data_.resize(other.rows_);
                for (size_t i = 0; i < other.rows_; i++)
                    data_[i].resize(other.cols_);
                rows_ = other.rows_;
                cols_ = other.cols_;
            }
            for (size_t i = 0; i < rows_; i++)
                for (size_t j = 0; j < cols_; j++)
                    data_[i][j] = other.data_[i][j];
        }
        return *this;
    }
    /*!*****************************************************************************
	\brief
	  operator overload ==
	\param const matrix<T>& other
	  
	\return bool
	*******************************************************************************/
    template<typename T> bool matrix<T>::operator==(const matrix<T>& other) const {
        if(rows_ != other.rows_ || cols_ != other.cols_)
            return false;
        for(size_t i = 0; i < rows_; i++)
            for(size_t j = 0; j < cols_; j++)
                if(data_[i][j] != other.data_[i][j])
                    return false;
        return true;
    }
    /*!*****************************************************************************
	\brief
	  operator overload !=
	\param const matrix<T>& other
	  
	\return bool
	*******************************************************************************/
    template<typename T> bool matrix<T>::operator!=(const matrix<T>& other) const { return !(*this == other); }
     /*!*****************************************************************************
	\brief
	  operator overload []
	\param size_t index
	  
	\return std::vector<T>& 
	*******************************************************************************/
    template<typename T> std::vector<T>& matrix<T>::operator[](size_t index){ return data_[index]; }
     /*!*****************************************************************************
	\brief
	  operator overload+
	\param const matrix<T>& other
	  
	\return matrix<T> 
	*******************************************************************************/
    template<typename T> matrix<T> matrix<T>::operator+(const matrix<T>& other) const{
        if(rows_ != other.rows_ || cols_ != other.cols_)
            throw std::invalid_argument("Matrices must be the same size for addition.");
        matrix<T> result(rows_, cols_);
        for(size_t i = 0; i < rows_; i++)
            for(size_t j = 0; j < cols_; j++)
                result[i][j] = data_[i][j] + other.data_[i][j];
        return result;
    }
    /*!*****************************************************************************
	\brief
	  operator overload+=
	\param const matrix<T>& other
	  
	\return matrix<T>& 
	*******************************************************************************/
    template<typename T> matrix<T>& matrix<T>::operator+=(const matrix<T>& other){
        if (rows_ != other.rows_ || cols_ != other.cols_)
            throw std::invalid_argument("Matrices must be the same size for addition.");
        for (size_t i = 0; i < rows_; i++) 
            for (size_t j = 0; j < cols_; j++) 
                data_[i][j] += other.data_[i][j];
        return *this;     
    }
    /*!*****************************************************************************
	\brief
	  operator overload-
	\param const matrix<T>& other
	  
	\return matrix<T> 
	*******************************************************************************/
    template<typename T> matrix<T> matrix<T>::operator-(const matrix<T>& other) const{
        if (rows_ != other.rows_ || cols_ != other.cols_)
            throw std::invalid_argument("Matrices must be the same size for subtraction.");
        matrix<T> result(rows_, cols_);
        for (size_t i = 0; i < rows_; i++)
            for (size_t j = 0; j < cols_; j++)
                result[i][j] = data_[i][j] - other.data_[i][j];
        return result;
    }
    /*!*****************************************************************************
	\brief
	  operator overload-=
	\param const matrix<T>& other
	  
	\return  matrix<T>& 
	*******************************************************************************/
    template<typename T> matrix<T>& matrix<T>::operator-=(const matrix<T>& other){
        if (rows_ != other.rows_ || cols_ != other.cols_)
            throw std::invalid_argument("Matrices must be the same size for subtraction.");
        for (size_t i = 0; i < rows_; i++)
            for (size_t j = 0; j < cols_; j++)
                data_[i][j] -= other.data_[i][j];
        return *this; 
    }
    /*!*****************************************************************************
	\brief
	  operator overload*
	\param const matrix<T>& other
	  
	\return  matrix<T>
	*******************************************************************************/
    template<typename T> matrix<T> matrix<T>::operator*(const matrix<T>& other) const{
        if (cols_ != other.rows_) 
            throw std::invalid_argument("Invalid matrix dimensions for multiplication.");
        matrix<T> result(rows_, other.cols_);
        for (size_t i = 0; i < rows_; i++) 
            for (size_t j = 0; j < other.cols_; j++)
                for (size_t k = 0; k < cols_; k++)
                    result[i][j] += data_[i][k] * other.data_[k][j];
        return result;
    }
    /*!*****************************************************************************
	\brief
	  operator overload*=
	\param const matrix<T>& other
	  
	\return  matrix<T>&
	*******************************************************************************/
    template<typename T> matrix<T>& matrix<T>::operator*=(const matrix<T>& other){
        if (cols_ != other.rows_)
        throw std::invalid_argument("Invalid matrix dimensions for multiplication.");
    matrix<T> result(rows_, other.cols_);
    for (size_t i = 0; i < rows_; i++)
        for (size_t j = 0; j < other.cols_; j++)
            for (size_t k = 0; k < cols_; k++)
                result[i][j] += data_[i][k] * other.data_[k][j];
    rows_ = result.rows_;
    cols_ = result.cols_;
    data_ = result.data_;
    return *this;
    }
    /*!*****************************************************************************
	\brief
	  operator overload<<
	\param std::ostream& os, const matrix<U>& mat
	  
	\return std::ostream&
	*******************************************************************************/
    template<typename U> std::ostream& operator<<(std::ostream& os, const matrix<U>& mat){
        for(size_t i = 0; i < mat.rows_; i++){
            for(size_t j = 0; j < mat.cols_; j++)
                if((j+1)!= mat.cols_)
                    os << mat.data_[i][j] << " ";
                else
                    os << mat.data_[i][j]; 

            os << std::endl;
        }
        return os;
    }
    /*!*****************************************************************************
	\brief
	  operator overload*
	\param const T& scalar
	  
	\return  matrix<T>
	*******************************************************************************/
    template<typename T> matrix<T> matrix<T>::operator*(const T& scalar) const {
        matrix<T> result(rows_, cols_);
        for (size_t i = 0; i < rows_; ++i)
            for (size_t j = 0; j < cols_; ++j) 
                result[i][j] = data_[i][j] * scalar;
        return result;
    }
    /*!*****************************************************************************
	\brief
	  operator overload*=
	\param const T& scalar
	  
	\return  matrix<T>&
	*******************************************************************************/
    template<typename T> matrix<T>& matrix<T>::operator*=(const T& scalar) {
        for (size_t i = 0; i < rows_; ++i) 
            for (size_t j = 0; j < cols_; ++j)
                data_[i][j] *= scalar;
        return *this;
    }
    /*!*****************************************************************************
	\brief
	  operator overload*
	\param const std::complex<T>& scalar, matrix<std::complex<T>>& mat
	  
	\return  matrix<std::complex<T>> 
	*******************************************************************************/
     template<typename T> matrix<std::complex<T>> operator*(const std::complex<T>& scalar, matrix<std::complex<T>>& mat){
        matrix<std::complex<T>> result(mat.Rows(), mat.Cols());
        for (size_t i = 0; i < mat.Rows(); i++) 
            for (size_t j = 0; j < mat.Cols(); j++) 
                result[i][j] = scalar * mat[i][j];
        return result;
    }
    /*!*****************************************************************************
	\brief
	  operator overload*
	\param const T& scalar, matrix<T>& mat
	  
	\return  matrix<T> 
	*******************************************************************************/
  template<typename T> matrix<T> operator*(const T& scalar, matrix<T>& mat) {
        matrix<T> result(mat.Rows(), mat.Cols());
        for (size_t i = 0; i < mat.Rows(); i++)
            for (size_t j = 0; j < mat.Cols(); j++)
                result[i][j] = scalar * mat[i][j];
        return result;
    }


}