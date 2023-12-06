#include <iostream>
#include <string>
#include <fstream>

#define CONST_MAX_PARAMS 3

using namespace std;
string _framename = "TNT";
const string _paramnames[CONST_MAX_PARAMS] = {"-framename", "-framenumber", "-modelnumber"};
int _framenumber = 0;
int _modelnumber = 1;
char _alphabet[27] = "abcdefghijklmnopqrstuvwxyz";


int main(int argc, char *argv[])
{
    if(argc == 0)
    {
        cout << "[COMMANDS] \n  -framename : has to be either three or four digits. If only three is given, you will only be able to export at the max of 26 frames(0~25)\n   -framenumber : sets maximum number of frames. Keep in mind that the frame starts from 0\n   -modelnumber : sets how many models parts to get their animations frames. Also keep in mind that this starts from 0, but it works differently (f.e. passing 1 only provide model 0 frames.)" << endl;
        return 0;
    }
    if(argc >= 1)
    {
        for(int i = 0; i < argc; i++)
        {
            if(argv[i] == "-framename")
            {
                _framename = string(argv[i + 1]);
                for(int j = 0; j < CONST_MAX_PARAMS; j++)
                {
                    if(argv[i + 1] == _paramnames[j])
                    {
                        cout << "The parameter is empty." << endl;
                        _framename = "TNT";
                    }
                }
            }

            if(argv[i] == "-framenumber")
            {
                _framenumber = int(argv[i + 1]);
                
                for(int j = 0; j < CONST_MAX_PARAMS; j++)
                {
                    if(argv[i + 1] == _paramnames[j])
                    {
                        cout << "The parameter is empty." << endl;
                        _framenumber = 0;
                    }
                }

                if(_framenumber < 0)
                {
                    cout << "-modelnumber received wrong value. Setting it to default value(0)." << endl;
                }
            }

            if(argv[i] == "-modelnumber")
            {
                _modelnumber = int(argv[i + 1]);

                for(int j = 0; j < CONST_MAX_PARAMS; j++)
                {
                    if(argv[i + 1] == _paramnames[j])
                    {
                        cout << "The parameter is empty." << endl;
                        _modelnumber = 1;
                    }
                }

                if(_modelnumber <= 0)
                {
                    cout << "-modelnumber received wrong value. Setting it to default value(1)." << endl;
                }
            }
        }
    }

    ofstream _outfile;
    _outfile.open("modeldeaf.output");

    string _framemaster;
    for(int i = 0; i <= _framenumber; i++)
    {
        for(int j = 0; j < 26; j++)
        {
            for(int k = 0; k < _modelnumber; k++)
            {
                cout << "Frameindex " << _framename << " " << _alphabet[j] << " " << k << " " << i << endl;
                _framemaster += ("Frameindex " + _framename + " " + _alphabet[j] + " " + string(k) + " " + string(i) + "\n");
            }
        }
    }
}