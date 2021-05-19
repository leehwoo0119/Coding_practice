using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp2
{
    class Program
    {
        static StringBuilder sb = new StringBuilder();
        static int n;
        static void insert(int cnt, int y, int x)
        {
            if ((y / cnt) % 3 == 1 && (x / cnt) % 3 == 1)
            {
                sb.Append(" ");
                return;
            }
            else
            {
                if (cnt / 3 == 0)
                {
                    sb.Append("*");
                    return;
                }
                else
                {
                    
                    insert(cnt / 3, y, x);
                }
            }             
        }
        static void Main(string[] args)
        {
            n = int.Parse(Console.ReadLine());

            for (int y = 0; y < n; y++) 
            {
                for (int x = 0; x < n; x++)
                {
                    insert(n, y, x);
                }
                sb.Append("\n");
            }
            Console.Write(sb);
        }
    }
}

