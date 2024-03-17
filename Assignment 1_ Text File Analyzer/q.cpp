/*!*************************************************************************
****
\file q.cpp
\author Yugendren S/O Sooriya Moorthi
\par DP email: 2201512@sit.singaporetech.edu.sg
\par Course: HLP2
\par Section: nil
\par Ass 01
\date 10-01-2023
\brief
This program takes a file and calulates various identity of such file, and prints
it to output  file.
The functions include:
- q
    takes a file and makes an output file, and does vaious analyitical 
    calulations such as no of characters, digits e.t.c
****************************************************************************
***/
#include <iostream>
#include <iomanip>
#include <fstream>

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
    void q(char const *input_filename, char const *analysis_file)
    {
        std::ifstream ifile(input_filename); //input file
        std::ofstream ofile(analysis_file); //output file
        
        
        if(!ifile.is_open())
        {

            std::cout<< "File "<< input_filename <<" not found."<< '\n';//error message 
        
        }
        else if(!ofile.is_open())
        {
            
            std::cout<< "Unable to create output file "<< analysis_file <<"."<< '\n';//error message 

        }
        else
        {
            ofile << "Statistics for file: " << input_filename << std::endl;
            ofile << "---------------------------------------------------------------------"<< std::endl << std::endl;
            ofile << "Total # of characters in file: ";
            
            char ch;
            int array[26]={0};
            double chara = 0; 
            int wspace=-1, other = 0, digit = 0, upper = 0, lower = 0;//-1 to account for EOF
            int alph = 0;


            int intno = 0;
            int x = 0;
            int integer[10]={0};//temporary storage of no
            int integercount[1000] ={0}; //permant storage of integer
            int integertotal = 0;//place holder for interger
            int power[] = {1,10,100,1000,10'000,100'000,1'000'000,10'000'000,100'000'000,1'000'000'000};
            int intstate = 0;

            while(ifile)
            {
                ifile.get(ch);
                if(ch >= 'a'&& ch<='z') 
                {
                    chara++;
                    lower++;
                    alph = ch -'a';
                    array[alph]+=1;
                    if(intstate>1)
                    {
                        int y = intstate;
                        for(int i = 0; i<y; i++)
                        {
                            integertotal+=integer[i]*power[--intstate]; 
                        }
                        integercount[x++] = integertotal;
                        integertotal = 0;
                    }
                    intstate = 0;                 
                }
                else if(ch>= 'A' && ch<= 'Z')
                {
                    chara++;
                    upper++;
                    alph = ch -'A';
                    array[alph]+=1;
                    if(intstate>1)
                    {
                        int y = intstate;
                        for(int i = 0; i<y; i++)
                        {
                            integertotal+=integer[i]*power[--intstate]; 
                        }
                        integercount[x++] = integertotal;
                        integertotal = 0;
                    }
                    intstate = 0;
                }
                else if(ch >='0'&& ch<='9' && intstate == 0)
                {
                    digit++;
                    intno++;
                    integer[intstate++] = ch -'0';
                    integercount[x++] = ch -'0';
                }
                else if(ch >='0'&& ch<='9' && intstate > 0)
                {
                    if(intstate == 1)
                    {
                        x--;
                    }   
                    digit++;
                    integer[intstate++] = ch-'0'; 
                }
                else if (isspace(ch))
                {
                    wspace++;
                    if(intstate>1)
                    {
                        int y = intstate;
                        for(int i = 0; i<y; i++)
                        {
                            integertotal+=integer[i]*power[--intstate]; 
                        }
                        integercount[x++] = integertotal;
                        integertotal = 0;
                    }
                    intstate = 0;
                }
                else 
                {
                    other++;
                    if(intstate>1)
                    {
                        int y = intstate;
                        for(int i = 0; i<y; i++)
                        {
                            integertotal+=integer[i]*power[--intstate];
                            
                        }
                        integercount[x++] = integertotal;
                        integertotal = 0;
                    }
                    intstate = 0;
                }
            }
            if(ch == '.')
            {
                wspace++;
                other--;

            }
            ifile.close();// close file

            double total = wspace + chara + other + digit;//account for EOF from -1 on others
            ofile << total << std::endl << std::endl;
            ofile <<std::left << "Category" <<std::setw(25);
            ofile<<std::right<<std::setw(28)<<"How many in file";
            ofile <<std::right<< std::setw(22)<<"% of file"<< std::endl;
            ofile <<"---------------------------------------------------------------------"<<std::endl;
            ofile <<std::left<<std::setw(25)<<"Letters";
            ofile<< std::right<< std::setw(11)<<chara;
            ofile <<std::right<< std::setw(20)<< std::setprecision(2)<<std::fixed<<(chara/total)*100<<" %"<< std::endl;

            ofile <<std::left<<std::setw(25)<<"White space";
            ofile<<std::right<<std::setw(11) <<wspace;
            ofile <<std::right<< std::setw(20)<< std::setprecision(2)<<std::fixed<<(wspace/total)*100<<" %"<< std::endl;

            ofile <<std::left<<std::setw(25)<<"Digits";
            ofile<<std::right<<std::setw(11)<< digit;
            ofile <<std::right<<std::setw(20)<< std::setprecision(2)<<std::fixed<<(digit/total)*100<<" %"<< std::endl;

            ofile  <<std::left<<std::setw(25)<<"Other characters";
            ofile  <<std::right<<std::setw(11)<< other;
            ofile <<std::right<<std::setw(20)<< std::setprecision(2)<<std::fixed<<(other/total)*100<<" %"<< std::endl;

            ofile << std::endl<<std::endl;
            ofile << "LETTER STATISTICS"<< std::endl<<std::endl;
            ofile << "Category            How many in file      % of all letters" <<std::endl;
            ofile <<"---------------------------------------------------------------------"<<std::endl;

            ofile <<std::left<<std::setw(25)<< "Uppercase";
            ofile <<std::right<<std::setw(11)<< upper;
            ofile <<std::right<<std::setw(20)<<std::setprecision(2)<<std::fixed<<(upper/chara)*100<<" %"<< std::endl;

            ofile <<std::left<<std::setw(25)<< "Lowercase";
            ofile <<std::right<<std::setw(11)<< lower;
            ofile <<std::right<<std::setw(20)<<std::setprecision(2)<<std::fixed<<(lower/chara)*100<<" %"<< std::endl;

            char a = 'a';
            for(int i =0; i<26; i++)
            {
                
                ofile  <<std::left<<std::setw(25)<< (char)a++;
                ofile <<std::right<<std::setw(11)<<array[i];
                ofile<<std::right<<std::setw(20)<<std::setprecision(2)<<std::fixed<<(array[i]/chara)*100<<" %"<< std::endl;
            }
            ofile<<std::endl<<std::endl<<"NUMBER ANALYSIS"<<std::endl<<std::endl;
            ofile<<"Number of integers in file:          "<< intno<<std::endl;
            int sum = 0;
            for(int i = 0; i<intno; i++)
            {
                sum+=integercount[i];
                //ofile<<sum<<std::endl; //debugger
            }
            ofile<<"Sum of integers:                     "<<sum<<std::endl;
            double denom = intno, average = 0;
            
            if(intno>0)
            {
            average = sum/denom;
            }
            
            ofile <<"Average of integers:                 "<<std::setprecision(2)<<std::fixed<<average<< std::endl;
            ofile <<"_____________________________________________________________________"<< std::endl;
            ofile.close();//close file
        }
    }
}