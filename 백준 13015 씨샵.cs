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
        static void draw(int i)
        {
            for (int j = 0; j < i; j++) 
            {
                sb.Append(" ");
            }
            sb.Append("*");
            for (int j = 0; j < n - 2; j++)
            {
                sb.Append(" ");
            }
            sb.Append("*");
            for (int j = 2 * (n - 1 - i) - 1; j > 0; j--)
            {
                sb.Append(" ");
            }
            if (i != n - 1) sb.Append("*");
            for (int j = 0; j < n - 2; j++)
            {
                sb.Append(" ");
            }
            sb.Append("*");
            sb.Append("\n");
        }

        static void drawUpDown()
        {
            for (int t = 1; t <= n; t++) sb.Append("*");
            for (int t = 1; t <= 1 + 2 * (n - 2); t++) sb.Append(" ");
            for (int t = 1; t <= n; t++) sb.Append("*");
        }
        static void Main(string[] args)
        {
            n = int.Parse(Console.ReadLine());


            drawUpDown();
            sb.Append("\n");
            for (int i = 1; i < n; i++) draw(i);
            for (int i = n - 2; i > 0; i--) draw(i);
            drawUpDown();
            Console.Write(sb);
        }
    }
}

