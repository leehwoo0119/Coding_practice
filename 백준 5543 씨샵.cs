using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp2
{
    class Program
    {
        static void Main(string[] args)
        {
           int[] berger = new int[3];
           int[] drink = new int[2];
           for (int i=0;i<5;i++)
           {
                int price = int.Parse(Console.ReadLine());
                if (i < 3) berger[i] = price;
                else drink[i - 3] = price;
           }
            Array.Sort(berger);
            Array.Sort(drink);

            Console.WriteLine(berger[0] + drink[0] - 50);
        }
    }
}
