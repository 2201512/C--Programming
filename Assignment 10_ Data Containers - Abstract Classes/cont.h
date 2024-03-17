/*!*************************************************************************
****
\file cont.h
\author Yugendren S/O Sooriya Moorthi
\par DP email: 2201512@sit.singaporetech.edu.sg
\par Course: HLP2
\par Section: nil
\par Ass 10
\date 02-04-2023
\brief
This program is header file for list.cpp
****************************************************************************
***/
#ifndef CONT_H
#define CONT_H
#include<cstddef>
namespace hlp2 
{
	class cont
	{
    	public:
    		// Other declarations
    
            virtual ~cont() {}
    		virtual size_t size() const = 0;
    		virtual void clear() = 0;
            virtual bool is_empty() const{return size() == 0;}
    		
	};
}

#endif
