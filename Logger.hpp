#pragma once

/* ------------------------------------------------------ *

 -     ___    __  ______     __ 
 -    /   |  / / / / __ \   / /   ____ _____  ____ ___  ______ _____ ____
 -   / /| | / /_/ / /_/ /  / /   / __ `/ __ \/ __ `/ / / / __ `/ __ `/ _ \
 -  / ___ |/ __  / ____/  / /___/ /_/ / / / / /_/ / /_/ / /_/ / /_/ /  __/
 - /_/  |_/_/ /_/_/      /_____/\__,_/_/ /_/\__, /\__,_/\__,_/\__, /\___/
 -                                         /____/            /____/


 - Author: AdvaHype 2024 - 2025
 - Copyright: AdvaHype 2024 - 2025

 * ------------------------------------------------------ */

using namespace std;

/**
 * class Logger
*/
class Logger
{
    public:

        /**
         * Warning
         *
         * @param details string
         * @param line line
         *
         * @return void
        */
        static void warning(string details, int line = 0)
        {
            cout << LightYellow << "Warning: " << DefaultColor << details;

            if (line > 0)
            {
                cout << " in line " << line;
            }

            cout << endl;
        }

        /**
         * Notice
         *
         * @param details string
         * @param line line
         *
         * @return void
        */
        static void notice(string details, int line = 0)
        {
            cout << LightCyan << "Notice: " << DefaultColor << details;

            if (line > 0)
            {
                cout << " in line " << line;
            }

            cout << endl;
        }

        /**
         * Error
         *
         * @param details string
         * @param line line
         *
         * @return void
        */
        static void error(string details, int line = 0)
        {
            cout << LightRed << "Error: " << DefaultColor << details;

            if (line > 0)
            {
                cout << " in line " << line;
            }

            exit(EXIT_FAILURE);
        }
};