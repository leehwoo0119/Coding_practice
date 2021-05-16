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
            HashSet<int> s = new HashSet<int>();
            int[] num = new int[10];

            for (int i = 0; i < 10; i++) 
            {
                int input= int.Parse(Console.ReadLine());
                s.Add(input % 42);
            }

            Console.WriteLine(s.Count());
        }
    }
}
