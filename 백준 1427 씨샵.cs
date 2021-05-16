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
            int saveinput = input;
            int cnt = 0;
            while (saveinput != 0)
            {
                cnt++;
                saveinput /= 10;
            }
            int[] arr = new int[cnt];
            for (int i = 0; i < cnt; i++) 
            {
                arr[i] = input % 10;
                input /= 10;
            }
            Array.Sort(arr);
            for (int i = cnt - 1; i >= 0; i--)
            {
                Console.Write(arr[i]);
            }
               
        }
    }
}
