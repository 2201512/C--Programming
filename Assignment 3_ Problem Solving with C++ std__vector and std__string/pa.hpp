/*!*************************************************************************
****
\file pa.hpp
\author Yugendren S/O Sooriya Moorthi
\par DP email: 2201512@sit.singaporetech.edu.sg
\par Course: HLP2
\par Section: nil
\par Ass 03
\date 19-01-2023
\brief
This program header file for functions used in pa.cpp. The functions include:
- fill_vector_from_istream, max_name_length, sort, write_to_ostream,cmp_name_less,
cmp_name_greater, cmp_pop_less, bool cmp_pop_greater
    takes inputs from command line to get input and output file, to categorise 
    input file and print to output file.
****************************************************************************
***/
#ifndef PA_HPP
#define PA_HPP

#include <vector>
#include <iostream>
using namespace std;

namespace HLP2
{
    struct CountryInfo
    {
        string name;
        long int pop;
    };
    
    using Ptr_Cmp_Func = bool (*)(CountryInfo const&, CountryInfo const&);
    
    /**************************************************************************/
    /*!
      \brief
        takes in a data file and stores then into a vector of struct
      
      \param istream& is
        reference to the input file
      
      \return vector<CountryInfo>
        a vector of the categorised data
    */
    /**************************************************************************/
    vector<CountryInfo> fill_vector_from_istream(istream& is);
    /**************************************************************************/
    /*!
      \brief
        find the name of the country with the largest lenght
      
      \param vector<CountryInfo> const& list
        reference to the vector with the data
      
      \return size_t
        a value of size_t that represents the lenght of the longest name
    */
    /**************************************************************************/
    size_t max_name_length(vector<CountryInfo> const& list);
    /**************************************************************************/
    /*!
      \brief
        sort the data accordingly with the input varaiable
      
      \param vector<CountryInfo>& rv
        reference to the vector with the data

      \param Ptr_Cmp_Func cmp
        reference to the pointer of a fucntion that is used for comparison

      \return void
        nil
    */
    /**************************************************************************/
    void sort(vector<CountryInfo>& rv, Ptr_Cmp_Func cmp);
    /**************************************************************************/
    /*!
      \brief
        write the data to the output file/stream
      
      \param vector<CountryInfo> const& v
        reference to the vector with the data

      \param ostream& os
        output stream file name

      \param size_t fw
        size_t variable used for the limit

      \return void
        nil
    */
    /**************************************************************************/
    void write_to_ostream(vector<CountryInfo> const& v, ostream& os, size_t fw);
     /**************************************************************************/
    /*!
      \brief
        compare data and return lesser value
      
      \param CountryInfo const& left
        1st set of struct data

      \param CountryInfo const& right
        2nd set of struct data

      \return bool
        True or false value
    */
    /**************************************************************************/
    bool cmp_name_less(CountryInfo const& left, CountryInfo const& right);
     /**************************************************************************/
    /*!
      \brief
        compare data and return higher value
      
      \param CountryInfo const& left
        1st set of struct data

      \param CountryInfo const& right
        2nd set of struct data

      \return bool
        True or false value
    */
    /**************************************************************************/
    bool cmp_name_greater(CountryInfo const& left, CountryInfo const& right);
     /**************************************************************************/
    /*!
      \brief
        compare data and return lesser value
      
      \param CountryInfo const& left
        1st set of struct data

      \param CountryInfo const& right
        2nd set of struct data

      \return bool
        True or false value
    */
    /**************************************************************************/
    bool cmp_pop_less(CountryInfo const& left, CountryInfo const& right);
     /**************************************************************************/
    /*!
      \brief
        compare data and return higher value
      
      \param CountryInfo const& left
        1st set of struct data

      \param CountryInfo const& right
        2nd set of struct data

      \return bool
        True or false value
    */
    /**************************************************************************/
    bool cmp_pop_greater(CountryInfo const& left, CountryInfo const& right);
}
#endif