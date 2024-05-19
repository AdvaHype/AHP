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

class Token
{
    protected:

        TokenType type;
        string value;
        Position position = Position(-1, -1, -1);

    public:

        /**
         * Constructor
         *
         * @param type
         * @param value
        */
        Token(TokenType type, string value = "\0")
        {
            this->type = type;
            this->value = value;
        }

        /**
         * Set position
         *
         * @param position
         * @return void
        */
        void setPosition(Position position)
        {
            this->position = position;
        }

        /**
         * Get position
         *
         * @return Position
        */
        Position getPosition()
        {
            return this->position;
        }

        /**
         * Get raw token type
         *
         * @return TokenType
        */
        TokenType getRawType()
        {
            return this->type;
        }

        /**
         * Get type
         *
         * @return string
        */
        string getType()
        {
            switch (this->type)
            {
                case TokenType::Start:
                    return "START";
                    break;

                case TokenType::Int:
                    return "INTEGER";
                    break;

                case TokenType::Long:
                    return "LONG";
                    break;

                case TokenType::Char:
                    return "CHAR";
                    break;

                case TokenType::String:
                    return "STRING";
                    break;

                case TokenType::Array:
                    return "ARRAY";
                    break;

                case TokenType::Plus:
                    return "PLUS";
                    break;

                case TokenType::Minus:
                    return "MINUS";
                    break;

                case TokenType::Mul:
                    return "MUL";
                    break;

                case TokenType::Div:
                    return "DIV";
                    break;

                case TokenType::Mod:
                    return "MOD";
                    break;

                case TokenType::Lparen:
                    return "LPAREN";
                    break;

                case TokenType::Rparen:
                    return "RPAREN";
                    break;

                case TokenType::Assign:
                    return "ASSIGN";
                    break;

                case TokenType::Comment:
                    return "COMMENT";
                    break;

                case TokenType::Float:
                    return "FLOAT";
                    break;

                case TokenType::Double:
                    return "DOUBLE";
                    break;

                default:
                    return "UNDEFINED";
            }
        }

        /**
         * Get value
         *
         * @return string
        */
        string getValue()
        {
            return this->value;
        }

        /**
         * To string
         * 
         * @return string
        */
        operator string()
        {
            string type = this->getType();

            if (this->value.empty())
            {
                return type;
            }

            if (type == "STRING" or type == "CHAR")
            {
                return type + ":'" + this->value + "'";
            }

            return type + ":" + this->value;
        }
};