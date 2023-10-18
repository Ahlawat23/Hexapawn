
using System;
using System.Collections.Generic;
using System.Linq;

namespace HexaPawnnCsharp
{
    public class Program
    {

        
        public static void Main(string[] args)
        {
            Game();
        }

        static void Game()
        {

            Console.WriteLine("-------------NEW GAME STARTED!!-------------");
            Board.intializelistBox();
            Board.DrawBoard();

            player p = new player();
            Enemy e = new Enemy();

            playerTurnLine();

            int value = p.choose();

            //add a condition which dosent allow player to choose 3

            p.turn1(value);
            e.turn();

            playerTurnLine();

            value = p.choose();

            p.turn3(value);
            checkWin();
            e.turn();
            checkWin();

        }

        static void playerTurnLine()
        {
            Console.WriteLine("type 1 to move the side pawn, type 2 to move the middle pawn");
        }

        static void checkWin()
        {
            if(Board.box[0] == Board.player || Board.box[1] == Board.player || Board.box[2] == Board.player)
            {
                Console.WriteLine("-----------------HEY YOU WON!!!!!!!--------------");
                Console.WriteLine("press 1 to exit, press 2 to play agian");

                player p = new player();  
                
                int value = p.choose();

                if(value == 1)
                {
                    Environment.Exit(0);    
                }
                else if(value == 2)
                {
                    Game();

                }
            }

            else if(Board.box[6] == Board.enemy || Board.box[7] == Board.enemy || Board.box[8]== Board.enemy)
            {
                Console.WriteLine("-----------------YOU LOST!! BETTER LUCK NEXT TIME--------------");
                Console.WriteLine("press 1 to exit, press 2 to play agian");

                player p = new player();

                int value = p.choose();

                if (value == 1)
                {
                    Environment.Exit(0);
                }
                else if (value == 2)
                {
                    Game();

                }

            } 
        }
    }
}
