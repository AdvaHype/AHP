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
 * class Lexer
*/
class Lexer
{
    protected:

        /**
         * @var data
        */
        string data;

        /**
         * @var length
        */
        int length;

        /**
         * @var current current character
        */
        char current;

        /**
         * @var position
        */
        Position position = Position(-1, 1, -1);

        /**
         * Has lex continue
         *
         * @return bool true if lex has continue
        */
        bool hasContinue()
        {
            return length > position.index;
        }

        /**
         * Advance
         *
         * @return void
        */
        void advance()
        {
            if (hasContinue())
            {
                position.advance(current);
                current = data[position.index];
            }
            else
            {
                current = '\0';
            }
        }

        /**
         * Is next char
         *
         * @param char toCompare
         * @return bool
        */
        bool isNextChar(char toCompare)
        {
            return length > position.index + 1 and toCompare == data[position.index + 1];
        }

        /**
         * Get comment
         *
         * @return Token
        */
        Token getComment()
        {
            string comment = "";

            // Getting single line comment

            if (isNextChar('/'))
            {
                position.index++;
                advance();

                int currentLine = position.line;

                while (hasContinue() and currentLine == position.line)
                {
                    comment += current;
                    advance();
                }
            }

            // Getting multi line comment

            else
            {
                while (hasContinue() and !(current == '*' and isNextChar('/')))
                {
                    comment += current;
                    advance();

                    if (!hasContinue() and !(current == '*' and isNextChar('/')))
                    {
                        Logger::error("unterminated comment starting", position.line);
                    }
                }

                advance();
            }

            return Token(TokenType::Comment, comment);
        }

        /**
         * Making numbers
         *
         * @return Token
        */
        Token makeNumber()
        {
            string number;
            bool isDecimal = false;
            int decimalDigitsCount = 0;

            while (hasContinue() and (isdigit(current) or current == '.'))
            {
                if (current == '.')
                {
                    if (isDecimal)
                    {
                        Logger::error("syntax error, unexpected floating-point", position.line);
                    }

                    isDecimal = true;
                }

                if (isDecimal)
                {
                    decimalDigitsCount++;
                }

                number += current;
                advance();
            }

            return Token(
                isDecimal ?
                (decimalDigitsCount <= 7 and number.length() <= 38 ? TokenType::Float : TokenType::Double) :
                (number.length() <= 10 ? TokenType::Int : TokenType::Long),

                number
            );
        }

    public:

        /**
         * Constructor
         *
         * @param data
        */
        Lexer(string data)
        {
            this->data = data;
            length = data.length();

            advance();
        }

        /**
         * Tokenize
         *
         * @return vector<Token>
        */
        vector<Token> tokenize()
        {
            Token token = Token(TokenType::Start);
            vector<Token> tokens;

            while (hasContinue())
            {
                // Skipping from escapable chars

                if (current == '\r' or current == '\n' or current == '\t' or current == ' ')
                {
                    advance();
                    continue;
                }

                // Getting number

                if (isdigit(current))
                {
                    token = makeNumber();
                    token.setPosition(position);
                    tokens.push_back(token);

                    continue;
                }

                else
                {
                    switch (current)
                    {
                        case '+':
                            token = Token(TokenType::Plus);
                            break;
                        case '-':
                            token = Token(TokenType::Minus);
                            break;
                        case '*':
                            token = Token(TokenType::Mul);
                            break;
                        case '/':

                            if (isNextChar('*') or isNextChar('/'))
                            {
                                token = getComment();
                            }
                            else
                            {
                                token = Token(TokenType::Div);
                            }
                            break;
                        case '%':
                            token = Token(TokenType::Mod);
                            break;
                        case '(':
                            token = Token(TokenType::Lparen);
                            break;
                        case ')':
                            token = Token(TokenType::Rparen);
                            break;
                        case '=':
                            token = Token(TokenType::Assign);
                            break;
                        default:
                            string message = "unexpected token '";
                            message += current;
                            message += '\'';

                            Logger::error(message, position.line);
                            break;
                    }

                    token.setPosition(position);
                    tokens.push_back(token);
                }

                advance();
            }

            return tokens;
        }
};