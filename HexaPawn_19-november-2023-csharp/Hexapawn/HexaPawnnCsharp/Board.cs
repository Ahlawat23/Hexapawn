using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HexaPawnnCsharp
{
    internal static class Board
    {
        public static string[] box = new string[9];

        public static string enemy = "O";
        public static string vaccant = " ";
        public static string player = "X";

        public static void intializelistBox()
        {
            box[0] = enemy;
            box[1] = enemy;
            box[2] = enemy;
            box[3] = vaccant;
            box[4] = vaccant;   
            box[5] = vaccant;
            box[6] = player;
            box[7] = player;
            box[8] = player;

        }

        public static void DrawBoard()
        {
            Console.WriteLine("    " + box[0] + "|" + box[1] + "|" + box[2]);
            Console.WriteLine("    " + "-----");
            Console.WriteLine("    " + box[3] + "|" + box[4] + "|" + box[5]);
            Console.WriteLine("    " + "-----");
            Console.WriteLine("    " + box[6] + "|" + box[7] + "|" + box[8]);

        }

        
    }
}
