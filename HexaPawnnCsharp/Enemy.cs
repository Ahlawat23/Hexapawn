using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HexaPawnnCsharp
{
    internal class Enemy
    {
        Random random = new Random();   


        public void turn()
        {
            Console.WriteLine("enemy turn....");
            Console.WriteLine();
            enemyBrainCalculation();
            Board.DrawBoard();
        }

        public void enemyBrainCalculation()
        {
           
            int PawnToMove = random.Next(0, 6);

           

                if (IfPawnCanMove(PawnToMove) && Board.box[PawnToMove] == Board.enemy)
                {
                    MoveOrKill(PawnToMove);
                }
                else
                {
                    enemyBrainCalculation();
                }

            
        }


        //a check system if the randomazide enemy can actuall move
         bool IfPawnCanMove(int PawnToMove)
        {
            //special case if pawnToMove is 5
            if (PawnToMove == 5)
            {
                if (Board.box[8] == Board.vaccant || Board.box[7] == Board.player)
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                //check if it can move forward
                if (Board.box[PawnToMove + 3] == Board.vaccant)
                {
                    return true;

                }
                //check if there is a player pawn in diagnol
                if (Board.box[PawnToMove + 2] == Board.player || Board.box[PawnToMove + 4] == Board.player)
                {
                    return true;
                }

                //if not return false
                return false;

            }

        }


        //randomise between move forward or kill
        void MoveOrKill(int pawnToMove)
        {
            int rand = random.Next(0, 3);

            

                switch (rand)
                {
                    case 0:
                        moveForward(pawnToMove);  
                        break;

                    case 1:
                        KillFor2(pawnToMove);
                        break;
                    case 2:
                        killFor4(pawnToMove);
                     
                        break;


                }

            
            
        }

        //check if it can move forward, if true, move or else randomaise move or kill
        void moveForward(int  PawnToMove)
        {
            if (Board.box[PawnToMove + 3] == Board.vaccant)
            {
                Board.box[PawnToMove + 3] = Board.enemy;
                Board.box[PawnToMove] = Board.vaccant;
            }
            else
            {
                MoveOrKill(PawnToMove);
            }

        }

        //check if it can kill, if true, kill, or else radomaise move or kill
        void KillFor2(int PawnToMove)
        {
            if (Board.box[PawnToMove + 2] == Board.player)
            {
                Board.box[PawnToMove + 2] = Board.enemy;
                Board.box[PawnToMove] = Board.vaccant;
                
            }
            else
            {
                MoveOrKill(PawnToMove);
            }

        }

        //check if it can kill, if true, kill, or else radomaise move or kill
        void killFor4(int PawnToMove)
        {
            if(Board.box[PawnToMove + 4] == Board.player)
                {
                Board.box[PawnToMove + 4] = Board.enemy;
                Board.box[PawnToMove] = Board.vaccant;
                
            }
            else
            {
                MoveOrKill(PawnToMove);
            }

        }

    }
}
