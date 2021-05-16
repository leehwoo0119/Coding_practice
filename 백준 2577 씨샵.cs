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
            int[] numCnt = new int[10];
            int a, b, c;
            a = int.Parse(Console.ReadLine());
            b = int.Parse(Console.ReadLine());
            c = int.Parse(Console.ReadLine());
            int temp = a * b * c;

            while(temp!=0)
            {
                numCnt[temp % 10]++;
                temp /= 10;
            }

            foreach(int i in numCnt)
            {
                Console.WriteLine(i);
            }
        }
    }
}
