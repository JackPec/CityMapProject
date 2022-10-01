/*
    Header file for Input_prot2 //can split this into
    implementation and interfaces, but I think inline functions can work too
*/
#pragma once //for most cases
#include <iostream>
#include <limits>
#include <string>
#include <vector>

const bool USING_MAX = 0;
const bool USING_MIN = 1;

//error place for edit
std::string errorInvalidChoice = "Error! Your choice is not valid.\n";
std::string errorCantRead = "Error! Cannot read input.\n";

void inline quitOrNot(bool &valid){ //Tried to make this work but its a hassle
    std::cout << "Do you want to retry your entry or quit this entry?"
            <<", type Q to quit, any other input to proceed: " ;

        char in;
        std::cin >> in;
        if (std::cin.peek() == '\n'){
            std::cin.ignore();
        }

        if(in == 'Q'){
            valid = false;
        }


}

template<typename inputType>
bool inline searchListMatch(inputType returnValue
                            ,const std::vector<inputType> &vec){

typedef typename std::vector<inputType>::size_type vecPos;
   bool match = false;
    for(vecPos i = 0; i < vec.size();i++){
            if(returnValue == vec[i]){
            return match = true;
            }
    }

    return match;

}


template<typename inputType>
inputType inline input_protectChoice(std::string const &prompt
                                     ,std::vector<inputType> vec)
                                     //does not work with bools
{
    inputType returnValue;

	    	std::cout << prompt;
            std::cin >> returnValue;

            while (std::cin.fail()==1) {
                std::cout << errorCantRead;


                std::cin.clear();
                std::cin.ignore(
                std::numeric_limits<std::streamsize>::max(),'\n');
                std::cout << prompt;
                std::cin >> returnValue;
            }

              while (searchListMatch(returnValue,vec) == false) {
                std::cout << errorInvalidChoice;
                std::cin.clear();
                std::cin.ignore(
                std::numeric_limits<std::streamsize>::max(),'\n');
                std::cout << prompt;
                std::cin >> returnValue;
            }

return returnValue;

}

template<typename inputType>
// added templates for use for more data types,
//  and inline to experiment with different kinds of libs
inline inputType input_protect(std::string const &prompt)
{

bool valid = true;
inputType returnValue=0;


while(valid == true){
        // aborting this seems hard, tried to work on it but oh well

	std::cout << prompt;
	std::cin >> returnValue;

	while (std::cin.fail()==1) {


		std::cout << errorCantRead;

		std::cin.clear();
		std::cin.ignore(
        std::numeric_limits<std::streamsize>::max(),'\n');

		std::cout << prompt;
		std::cin >> returnValue;
	}

valid = false;
}
return returnValue;

}


template<typename inputType>
inline inputType input_protect(std::string const &prompt
                               , inputType minValue)
{
	inputType returnValue=0;
	returnValue=input_protect<inputType>(prompt);
	while (returnValue < minValue) {
		std::cout << "Value must be >= " << minValue << std::endl;
		returnValue=input_protect<inputType>(prompt);
	}
	return returnValue;
}

template<typename inputType>
inline inputType input_protect(inputType maxValue
                               ,std::string const &prompt)
{
	inputType returnValue=0;
	returnValue=input_protect<inputType>(prompt);
	while (returnValue > maxValue) {
		std::cout << "Value must be <= " << maxValue << std::endl;
		std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
		returnValue=input_protect<inputType>(prompt);
	}
	return returnValue;
}


template<typename inputType>
inline inputType input_protect(std::string const &prompt
                               , inputType minValue
                               , inputType maxValue)
{
	inputType returnValue=0;
	returnValue=input_protect<inputType>(prompt,minValue);
	while (returnValue > maxValue) {
		std::cout << "Value must be <= " << maxValue << std::endl;
		std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
		returnValue=input_protect<inputType>(prompt,minValue);
	}
	return returnValue;
}


template<typename inputType>
inline inputType input_protect(bool i,std::string const &prompt
                               ,inputType maxormaxValue)
{
	inputType returnValue=0;
	returnValue=input_protect<inputType>(prompt);


	if(i == USING_MAX){
        while (returnValue > maxormaxValue) {
            std::cout << "Value must be <= " << maxormaxValue << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            returnValue=input_protect<inputType>(prompt);
        }

	}else if(i == USING_MIN){
        while (returnValue < maxormaxValue) {
		std::cout << "Value must be >= " << maxormaxValue << std::endl;
		std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
		returnValue=input_protect<inputType>(prompt);
        }



	}

	 return returnValue;

}


bool inline input_protectChoiceBool(std::string const &prompt
                                    ,std::string validChars)
{
    bool returnValue;

    char input = input_protect<char>(prompt);

            while (validChars.find_first_of(input)
                   == std::string::npos) {
                std::cout << errorInvalidChoice;
                std::cin.clear();
                std::cin.ignore(
                std::numeric_limits<std::streamsize>::max(),'\n');
                input = input_protect<char>(prompt);

            }

            if(input == 'Y' || input == 'y' ){
                    // this part has to be hardcoded for now
                   returnValue = true;
            }
            else{
                returnValue = false;
            }

return returnValue;

}
