/*!*************************************************************************
****
\file pa.cpp
\author Yugendren S/O Sooriya Moorthi
\par DP email: 2201512@sit.singaporetech.edu.sg
\par Course: HLP2
\par Section: nil
\par Ass 03
\date 19-01-2023
\brief
This program is the source file for functions used in pa.cpp. The functions include:
- fill_vector_from_istream, max_name_length, sort, write_to_ostream,cmp_name_less,
cmp_name_greater, cmp_pop_less, bool cmp_pop_greater
    takes inputs from command line to get input and output file, to categorise 
    input file and print to output file.
****************************************************************************
***/
#include<vector>
#include<iomanip>
#include<string>
#include "pa.hpp"
using namespace std;

namespace HLP2
{
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
    vector<CountryInfo> fill_vector_from_istream(istream& is)
    {
        string country;
        string population;
        string white = " \n\r\t\f\v";
        vector<CountryInfo> list;
        for (string line; getline(is, line);)
        {
            size_t countryIndex = line.find_first_of("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
            size_t populationIndex = line.find_first_of("0123456789");

            country = line.substr(countryIndex, populationIndex - countryIndex);
            population = line.substr(populationIndex);

            country = (country.find_last_not_of(white) == string::npos) ? "" : country.substr(0, country.find_last_not_of(white) + 1);
            for (char c : population) if (c == ',') population.erase(population.find(c), 1);
            list.push_back(CountryInfo{country, stol(population)});
        }
        return list;
    }
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
    size_t max_name_length(vector<CountryInfo> const& list)
    {
        size_t length = 0;
        for (CountryInfo i : list) if (i.name.length() > length) length = i.name.length();
        return length;
    }
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
    void sort(vector<CountryInfo>& rv, Ptr_Cmp_Func cmp)
    {
        for (size_t x = 0; x < rv.size(); x++) for (size_t i = 0; i < rv.size() - 1; i++) if (cmp(rv[i], rv[i + 1]))
        {
            CountryInfo temp = rv[i];
            rv[i] = rv[i + 1];
            rv[i + 1] = temp;
        }
    }
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
    void write_to_ostream(vector<CountryInfo> const& v, ostream& os, size_t fw)
    {
        for (CountryInfo i : v)
        {
            os << left << setw(fw) << i.name << i.pop << endl;
        }
    }
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
    bool cmp_name_less(CountryInfo const& left, CountryInfo const& right)
    {
        if (string(left.name) > string(right.name)) return true;
        else return false;
    }
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
    bool cmp_name_greater(CountryInfo const& left, CountryInfo const& right)
    {
        if (string(left.name) < string(right.name)) return true;
        else return false;
    }
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
    bool cmp_pop_less(CountryInfo const& left, CountryInfo const& right)
    {
        if (left.pop > right.pop) return true;
        else return false;
    }
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
    bool cmp_pop_greater(CountryInfo const& left, CountryInfo const& right)
    {
        if (left.pop < right.pop) return true;
        else return false;
    }
}