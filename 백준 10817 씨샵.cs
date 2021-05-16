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
            string input = Console.ReadLine();
            string[] inputarr = input.Split();
            int[] num = new int[3];
            for (int i = 0; i < 3; i++) 
            {
                num[i] = int.Parse(inputarr[i]);
            }
            Array.Sort(num);
            Console.WriteLine(num[1]);
        }
    }
}
