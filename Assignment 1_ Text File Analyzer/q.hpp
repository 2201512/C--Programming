/*!*************************************************************************
****
\file q.hpp
\author Yugendren S/O Sooriya Moorthi
\par DP email: 2201512@sit.singaporetech.edu.sg
\par Course: HLP2
\par Section: nil
\par Ass 01
\date 10-01-2023
\brief
This program header file for functions used in q-driver.cpp. The functions include:
- q
    takes a file and makes an output file, and does vaious analyitical 
    calulations such as no of characters, digits e.t.c
****************************************************************************
***/
#ifndef Q_HPP_
#define Q_HPP_

namespace hlp2 
{
/*!*************************************************************************
****
\brief
prints a vaious statements and calulations in a specific format to output file
\param char const *input_filename
name of file that is used
\param char const *analysis_file
name of output file
\return
void, as the changes are printed out
****************************************************************************
***/
void q(char const *input_filename, char const *analysis_file);
}
#endif