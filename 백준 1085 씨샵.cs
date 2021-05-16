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
            int x = int.Parse(inputarr[0]);
            int y = int.Parse(inputarr[1]);
            int w = int.Parse(inputarr[2]);
            int h = int.Parse(inputarr[3]);

            int x_w_Len = w - x;   
            int t_h_Len = h - y;

            int[] val = new int[4] { x, y, x_w_Len, t_h_Len };
            Console.WriteLine(val.Min());
        }
    }
}
