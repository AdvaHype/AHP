#include <map>
#include <vector>
#include <string>
#include <cctype>
#include <sstream>
#include <csignal>
#include <fstream>
#include <iostream>

#include "ConsoleColor.h"
#include "Logger.hpp"
#include "TokenType.h"
#include "Position.hpp"
#include "Token.hpp"
#include "Lexer.hpp"

using namespace std;

int main(int argc, char* argv[])
{
    if (argc > 1)
    {
        string line;
        int index = 0;
        string command = argv[1];

        if (command == "-t")
        {
            while (true)
            {
                cout << "AHP > ";
                getline(cin, line);

                if (line.empty())
                {
                    continue;
                }

                Lexer lexer = Lexer(line);
                vector<Token> tokens = lexer.tokenize();

                cout << "[";

                for (Token token: tokens)
                {
                    cout << (string) token;

                    if (tokens.size() - 1 > index)
                    {
                        cout << ", ";
                    }

                    index++;
                }

                cout << "]" << endl;

            }
        }

        else
        {
            ifstream handle(command);

            if (!handle.is_open())
            {
                Logger::error("unable to open " + command + " file");
            }

            string data;

            while (getline(handle, line))
            {
                data += line;
            }

            Lexer lexer = Lexer(data);
            vector<Token> tokens = lexer.tokenize();

            cout << "[";

            for (Token token: tokens)
            {
                cout << (string) token;

                if (tokens.size() - 1 > index)
                {
                    cout << ", ";
                }

                index++;
            }

            cout << "]" << endl;
        }
    }

    return EXIT_SUCCESS;
}