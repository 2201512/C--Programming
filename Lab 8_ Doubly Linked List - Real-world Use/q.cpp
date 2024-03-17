
/*!*************************************************************************
****
\file q.cpp
\author Yugendren S/O Sooriya Moorthi
\par DP email: 2201512@sit.singaporetech.edu.sg
\par Course: RSE 1202
\par Section: 
\par Programming Lab #9
\date 18-03-2023
\brief
This program defines a class finder

*!*****************************************************************************/
#include <iostream>
#ifndef Q_HH
#define Q_HH
#include <fstream>
#include <string>
#include "dllist.h"
#include "q.h"
#include <iostream>
#include <algorithm>


namespace hlp2
{

finder::finder(std::string const& file_str){
    search_space_filename = file_str;

}
	/**************************************************************************/
    /*!
      \brief
        find class 
      
      \param std::string const& honey_str
        reference to string
      
      \return void 
        nil
    */
    /**************************************************************************/
void finder::find(std::string const& honey_str){
    
    search_space_stream.open(search_space_filename); //opens the file
    if(!search_space_stream) { // file couldn't be opened
      std::cerr << "Error: file could not be opened" << std::endl;
      exit(1);
   }else{

    container_type temp;
    search_str = honey_str;
    //std::ifstream ifs(search_space_filename, std::ios_base::in);
    std::string hold_line;
    while(std::getline(search_space_stream, hold_line)){
        std::string upperLine = hold_line;

         std::transform(upperLine.begin(), upperLine.end(), upperLine.begin(),
        [](unsigned char c){ return std::toupper(c); });

        std::string upperHoney = honey_str;

        std::transform(upperHoney.begin(), upperHoney.end(), upperHoney.begin(),
        [](unsigned char c){ return std::toupper(c); });

        size_t pos = upperLine.find(upperHoney);

        while((pos = upperLine.find(upperHoney,pos)) != std::string::npos){
             //every time the string is found insert the position in a dllist

                temp.push_back(pos);

                //cnt++;
                pos+=honey_str.length();
            }
    }
        pos_ls = temp;
   }
    search_space_stream.close();
}
	/**************************************************************************/
    /*!
      \brief
        print
      
      \param nil
      
      \return nil 
        
    */
    /**************************************************************************/
void finder::print(){
    int cnt = 0;
    if(pos_ls.size() == 0){
        std::cout<<"'"<<search_str<<"'"<<" not found"<<std::endl;
        std::cout<<"\n";
    }else{
        if(pos_ls.size() == 18){cnt = 8;}else{cnt = pos_ls.size();}
    std::cout<<"'"<<search_str<<"'"<<" found at "<<cnt<<" character position(s): ";
    pos_ls.print();
    std::cout<<"\n";
    if(cnt == 8){std::cout<<"\n";}
    cnt = 0;
    }
}

}
#endif