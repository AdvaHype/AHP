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

class Position
{

    public:

        int index;
        int line;
        int column;

        /**
         * Constructor
         * 
         * @param index
         * @param line
         * @param column
         *
         * @return void
        */
        Position(int index, int line, int column)
        {
            this->index = index;
            this->line = line;
            this->column = column;
        }

        /**
         * Advance
         *
         * @param currentCharacter
         * @return void
        */
        void advance(char currentCharacter)
        {
            this->index++;

            if (currentCharacter == '\n')
            {
                this->line++;
                this->column = 0;
            } else {
                this->column++;
            }
        }

        /**
         * Find the start position of line
         *
         * @param data
         * @param line
         *
         * @return int start position
        */
        int findStartPosition(string data, int line)
        {
            int currentLine = 1;
            int currentPosition = 0;
            int dataLength = data.length();

            while (dataLength > currentPosition)
            {
                char currentChar = data[currentPosition];

                if (currentChar == '\n')
                {
                    currentLine++;
                }

                if (currentLine == line)
                {
                    return currentPosition;
                }

                currentPosition++;
            }

            return -1;
        }

        /**
         * Find the end position of line
         *
         * @param data
         * @param line
         *
         * @return int start position
        */
        int findEndPosition(string data, int line)
        {
            int currentLine = 0;
            int currentPosition = 0;
            int dataLength = data.length();

            while (dataLength > currentPosition)
            {
                char currentChar = data[currentPosition];

                if (currentChar == '\n')
                {
                    currentLine++;
                }

                if (currentLine == line)
                {
                    return currentPosition - 1;
                }

                currentPosition++;
            }

            return -1;
        }

        /**
         * Get char
         * 
         * @param data
         * @param length
         * @param index
         * 
         * @return char
        */
        char getCharacter(string data, int length, int index)
        {
            char output = '\0';

            if (length > index)
            {
                output = data[index];
            }

            return output;
        }
};