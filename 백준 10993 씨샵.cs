using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp2
{
   
    class Program
    { 
        static int n;
        static int[,] arr;
        static int height;
        static int weight;
        static void insert(int dep, int y, int x)
        {
            int height = (int)Math.Pow(2, dep) - 1;

            arr[y, x] = 1;
            if (dep == 1)
            {
                return;
            }

            int left = x; int right = x;
            for (int i = 0; i < height - 1; i++)
            {
                if (dep % 2 == 0)
                    y--;
                else
                    y++;

                left--; right++;
                arr[y, left] = 1; arr[y, right] = 1;
            }

            for (int i = left + 1; i < right; i++)
            {
                arr[y, i] = 1;
            }
            if (dep % 2 == 0) y++;
            else y--;
            insert(dep - 1, y, x);
        }
        static void Main(string[] args)
        {
            n = int.Parse(Console.ReadLine());
    
            height = (int)Math.Pow(2, n) - 1;
            weight = (height * 2 - 1);

            arr = new int[height, weight];

            int start_y = (n % 2 != 0) ? 0 : height - 1;
            int start_x = weight / 2;

            insert(n, start_y, start_x);

            StreamWriter streamWriter = new
                StreamWriter(Console.OpenStandardOutput());

            for (int y = 0; y < height; y++)
            {
                if (n % 2 == 0)
                {
                    for (int x = 0; x < weight - y; x++)
                    {
                        streamWriter.Write((arr[y, x] == 1) ? "*" : " ");
                    }
                }
                else
                {
                    for (int x = 0; x < weight / 2 + y + 1; x++)
                    {
                        streamWriter.Write((arr[y, x] == 1) ? "*" : " ");
                    }
                }  
                streamWriter.Write("\n");
            }
            streamWriter.Close();
        }
    }
}

