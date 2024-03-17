/*!*************************************************************************
****
\file q.hpp
\author Yugendren S/O Sooriya Moorthi
\par DP email: 2201512@sit.singaporetech.edu.sg
\par Course: HLP2
\par Section: nil
\par Lab 03
\date 24-01-2023
\brief
This program header file for functions used in q-driver.c. The functions include:
- to_piglatin
    takes a string and changes it into pig_latin
****************************************************************************
***/
namespace hlp2
{
/*!*************************************************************************
****
\brief
takes a string and changes it to the pig_latin format
\param std::string word
string to be used
\return std::string
pig_latin formatted string
****************************************************************************
***/
std::string to_piglatin(std::string word);

}