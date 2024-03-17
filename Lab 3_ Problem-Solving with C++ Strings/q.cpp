/*!*************************************************************************
****
\file q.cpp
\author Yugendren S/O Sooriya Moorthi
\par DP email: 2201512@sit.singaporetech.edu.sg
\par Course: HLP2
\par Section: nil
\par Lab 03
\date 24-01-2023
\brief
This program contains functions used in q-driver.c. The functions include:
- to_piglatin
    takes a string and changes it into pig_latin
****************************************************************************
***/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm> 

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
    std::string to_piglatin(std::string word)
    {
    	std::vector<char> data(word.begin(), word.end());
    	std::vector<char> vowel{ 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    	std::vector<std::string> Pigl{ "-yay", "-ay", "-way"};
    	int diff = 'a' - 'A';
    	int state{ 0 };
    	
        if (data[0] >= 'A' && data[0] <= 'Z')//check if first word is a capital
    	{
    		data[0] += diff;
    		state = 1;
    	}
    	
    	if (data[0] != 'y')//check if Y is a vowel
    	{
    		vowel.push_back('y');
    	}
    	
    	
    	for (long unsigned int i{ 0 }; i < vowel.size(); i++)//if the vowel is first,append and return
    	{
    		if (data[0] == vowel[i])
    		{
    		    	if (state == 1)
    				{
    					data[0] -= diff;
    				}
    			std::string ans(data.begin(), data.end());
    			ans += Pigl[0];
    			return ans;
    		}
    	}
    
    	
    	for (long unsigned int i{ 0 }; i < data.size(); i++)//if the vowel is in other letter, adjust, append and return
    	{
    		for (long unsigned int j{ 0 }; j < vowel.size(); j++)
    		{
    			if (data[i] == vowel[j])
    			{
    				for (long unsigned int k{ 0 }; k < i; k++)
    				{
    					std::rotate(data.begin(), data.begin() + 1, data.end());
    				}
    				
    				if (state == 1)
    				{
    					data[0] -= diff;
    				}
    				
    				std::string ans(data.begin(), data.end());
    				ans += Pigl[1];
    				return ans;
    			}
    		}
    	}
    	
    	if (state == 1)
		{
			data[0] -= diff;
		}
    	std::string ans(data.begin(), data.end());
    	ans += Pigl[2];
    	return ans;
    }
}
