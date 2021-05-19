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
        //static StringBuilder sb = new StringBuilder();
        static int n;
        static int[,] arr;
        static void insert(int weight, int y, int x)
        {
            if(weight == 3)
            {
                arr[y, x] = 1;
                arr[y + 1, x - 1] = 1;
                arr[y + 1, x + 1] = 1;
                arr[y + 2, x - 2 + 0] = 1;
                arr[y + 2, x - 2 + 1] = 1;
                arr[y + 2, x - 2 + 2] = 1;
                arr[y + 2, x - 2 + 3] = 1;
                arr[y + 2, x - 2 + 4] = 1;
            }
            else
            {
                insert(weight / 2, y, x);
                insert(weight / 2, y + (weight / 2), x - (weight / 2));
                insert(weight / 2, y + (weight / 2), x + (weight / 2));
            }
        }
        static void Main(string[] args)
        {
            n = int.Parse(Console.ReadLine());
            arr = new int[n, n * 2];

            insert(n, 0, n - 1);

            StreamWriter streamWriter = new
                StreamWriter(Console.OpenStandardOutput());

            for (int y = 0; y < n; y++) 
            {
                for (int x = 0; x < n * 2; x++)
                {
                    streamWriter.Write((arr[y, x] == 1) ? "*" : " ");
                }
                streamWriter.Write("\n");
            }

            streamWriter.Close();
        }
    }
}

