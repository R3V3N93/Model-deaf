#include <iostream>
#include <string>
#include <fstream>

#define CONST_MAX_PARAMS 3

using namespace std;
string _framename = "R3V";
const string _paramnames[CONST_MAX_PARAMS] = {"-framename", "-framenumber", "-modelnumber"};
int _framenumber = 0;
int _modelnumber = 1;
const char _spriteindex[37] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const char _alphabet[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";


int main(int argc, char *argv[])
{
	/*std::cout << "current argc : " << argc << endl;
	for(int i = 1; i <= argc; i++)
	{
		std::cout << argv[i] << " " << i << "\n";
	}
	*/
    if(argc == 1)
    {
        std::cout << "[COMMANDS] \n\n  -framename : has to be either three or four digits. If only three is given, you will only be able to export at the max of 26 frames(0~25). Max value is 935(if the value is 4)\n\n   -framenumber : sets maximum number of frames. Keep in mind that the frame starts from 0\n\n   -modelnumber : sets how many models parts to get their animations frames. Also keep in mind that this starts from 0, but it works differently (f.e. passing 1 only provide model 0 frames.)" << endl;
        return 0;
    }

    string _nextparam = "R3V";

    for(int i = 1; i < argc; i++)
    {
        if(argv[i + 1] != NULL)
        {
            _nextparam = argv[i + 1];
        }

        
    	#ifdef _DEBUG
            std::cout << i << endl;	
        #endif 

        if(string(argv[i]) == "-framename")
        {
            #ifdef _DEBUG
        	    std::cout << "-filename valid" << endl;
            #endif    
        	
            _framename = string(_nextparam);

            for(int j = 0; j < CONST_MAX_PARAMS; j++)
            {
                if((_nextparam) == _paramnames[j] || string(_nextparam) == "R3V")
                {
                    std::cout << "The parameter is empty." << endl;
                    _framename = "R3V";
                    break;
                }
            }

            if((_nextparam).length() != 3 && string(_nextparam).length() != 4)
            {
                std::cout << "Warning! -framename's value is not either 3 or 4 digits. setting it to default value(R3V)" << endl;
                _framename = "R3V";
            }
        }

        if(string(argv[i]) == "-framenumber")
        {
            
            #ifdef _DEBUG
                std::cout << "-framenumber valid" << endl;
            #endif 

            _framenumber = stoi(_nextparam);

            for(int j = 0; j < CONST_MAX_PARAMS; j++)
            {
                if((_nextparam) == _paramnames[j])
                {
                    std::cout << "The parameter is empty." << endl;
                    _framenumber = 0;
                    break;
                }
            }

            if(_framenumber > 935)
            {
                std::cout << "-framenumber exceeded its maximum value. setting it to the max value(935)." << endl;
                _framenumber = 935;
            }

            if(_framenumber < 0)
            {
                std::cout << "-framenumber received wrong value. Setting it to default value(0)." << endl;
                _framenumber = 0;
            }
        }

        if(string(argv[i]) == "-modelnumber")
        {
            #ifdef _DEBUG
                std::cout << "-modelnumber valid" << endl;
            #endif 
            _modelnumber = stoi(_nextparam);

            for(int j = 0; j < CONST_MAX_PARAMS; j++)
            {
                if((_nextparam) == _paramnames[j])
                {
                    std::cout << "The parameter is empty." << endl;
                    _modelnumber = 1;
                    break;
                }
            }

            if(_modelnumber <= 0)
            {
                std::cout << "-modelnumber received wrong value. Setting it to default value(1)." << endl;
                _modelnumber = 1;
            }
        }
        #ifdef _DEBUG
            std::cout << i << endl;	
        #endif 
        
    }
    
    ofstream _outfile;
    _outfile.open("modeldeaf.output");

    #ifdef _DEBUG
	    std::cout << "framename : " << _framename << " framenumber : " << _framenumber << " modelnumber : " << _modelnumber << endl;
    #endif
	
    string _framemaster;

    try
    {
        if(_framename.length() == 4)
        {
            throw 1;
        }



        for(int i = 0; i <= _framenumber; i++)
        {
            for(int k = 0; k < _modelnumber; k++)
            {
                _framemaster += ("Frameindex " + _framename + _spriteindex[i / 26 % 36] + " " + _alphabet[i % 26] + " " + to_string(k) + " " + to_string(i) + "\n");
                
                //"Frameindex " << _framename << _spriteindex[i % 36] << " " << _alphabet[i % 26] << " " << k << " " << i
            }
        }	
    }
    catch(int expn)
    {
        #ifdef _DEBUG
            std::cout << "generation w/ 4digts" << endl;
        #endif    

        for(int i = 0; i <= _framenumber; i++)
        {
            if(i > 25){break;}
            for(int k = 0; k < _modelnumber; k++)
            {
                _framemaster += ("Frameindex " + _framename + " " + _alphabet[i % 26] + " " + to_string(k) + " " + to_string(i) + "\n");
                
                //"Frameindex " << _framename << _spriteindex[i % 36] << " " << _alphabet[i % 26] << " " << k << " " << i
            }
        } 
    }
    #ifdef _DEBUG
        std::cout << _framemaster << endl;
    #endif  
    std::cout << "Process done. check modeldeaf.output file generated in where you executed the program." << endl;
    _outfile << _framemaster;
    _outfile.close();
    
}
