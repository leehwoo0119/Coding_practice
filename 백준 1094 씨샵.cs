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
            int input = int.Parse(Console.ReadLine());
            
            int cnt = 0;
            int stick = 64;
            while (stick != 0) 
            {
                
                if (stick == input)
                {
                    cnt++;
                    break;
                }
                if (input > stick)
                {
                    cnt++;
                    input -= stick;
                } 
                 stick /= 2;
            }

            Console.WriteLine(cnt);
        }
    }
}
