using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HexaPawnnCsharp
{
    internal class player
    {
        public int choose()
        {
            string choice = Console.ReadLine();
            if (choice.All(char.IsDigit))
            {
                int chosed = int.Parse(choice);
                return chosed;
            }
            else
            {
                Console.WriteLine("Choose an appropriate number");
                return choose();
            }

        }

        
        void movePlayer(int from, int to)
        {
            Board.box[from] = Board.vaccant;
            Board.box[to] = Board.player;
        }

        public void turn1(int choice)
        {
            if(choice == 1)
            {
                movePlayer(6, 3);   
            }

            if(choice == 2)
            {
                movePlayer(7, 4);
               
            }

            Board.DrawBoard();
        }

        public void turn3(int choice)
        {
            if (choice == 1)
            {
                //for sidePawn

                //if the pawn is at leftmiddle
                if(checkIfPlayer(3) && checkIfEnemy(1))
                {
                    movePlayer(3, 1);                   
                }

                if (checkIfPlayer(6) &&  checkIfVaccant(3))
                {
                    Console.WriteLine("type 1 for the left side pawn, type 2 for the right side pawn");
                    int choice1 = choose();

                    if (choice1 == 1)
                    {
                        //if the pawn is at leftdown
                        if(checkIfPlayer(4) && checkIfVaccant(3))
                        {
                            movePlayer(6, 3);      
                        }
                        else
                        {
                            Console.WriteLine("type 1 to move forward, type 2 to kill ");
                            int choice2 = choose();


                            if(choice2 == 1)
                            {
                                movePlayer(6, 3);
                               
                            }
                            if(choice2 == 2)
                            {
                                movePlayer(6, 4);
                            }
                        }
                    }

                    if(choice1 == 2)
                    {
                        //if the pawn is at rightdown
                        if (Board.box[4] == Board.player && Board.box[5] == Board.vaccant)
                        {
                            movePlayer(8, 5);
                        }
                        else
                        {
                            moveRightDownPawn();
                        }
                    }
                }
            }

            if (choice == 2)
            {
                if (!checkIfPlayer(7) && !checkIfPlayer(4))
                {
                    Console.WriteLine("there is no middle pawn, side pawns will moved");
                    turn3(1);

                }
               

                if(checkIfEnemy(4) )
                {
                    Console.WriteLine("No move for middle pawn, right side pawn will be moved...");
                    moveRightDownPawn();

                }

                if (checkIfPlayer(4) && checkIfVaccant(7))
                {
                    if (checkIfEnemy(0))
                    {
                        movePlayer(4, 0);
                    }
                    else
                    {
                        movePlayer(4, 2);
                    }
                }

                if (checkIfVaccant(4))
                {
                    Console.WriteLine("type 1 to move forward, type 2 to kill ");
                    int choice3 = choose();


                    if (choice3 == 1)
                    {
                        movePlayer(7, 4);
                    }
                    if (choice3 == 2)
                    {
                        if (checkIfEnemy(3))
                        {
                            movePlayer(7, 3);
                        }

                        if (checkIfEnemy(5))
                        {
                            movePlayer(7, 5);
                        }
                    }

                }

            }

            Board.DrawBoard();

        }

        public void turn5(int choice)
        {

        }


        void moveRightDownPawn()
        {
            Console.WriteLine("type 1 to move forward, type 2 to kill, THIS IS MOVERIGHTDOWNPAWN");
            int choice = choose();


            if (choice == 1)
            {
                movePlayer(8, 5);
            }
            if (choice == 2)
            {
                movePlayer(8, 4);
            }

        }

        bool checkIfPlayer(int index)
        {
            return Board.box[index] == Board.player;
        }

        bool checkIfEnemy(int index)
        {
            return Board.box[index] == Board.enemy;
        }

        bool checkIfVaccant(int index)
        {
            return Board.box[index] == Board.vaccant;
        }
    }
}
