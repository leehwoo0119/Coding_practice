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
            int n = int.Parse(Console.ReadLine());

            while(n--!=0)
            {
                int floor = int.Parse(Console.ReadLine());
                int ho = int.Parse(Console.ReadLine());

                int[,] arr = new int[floor + 1, ho + 1];

                for (int i = 0; i <= floor; i++) 
                {
                    for (int j = 0; j < ho; j++)
                    {
                        if (i == 0) arr[i, j] = j + 1;
                        else
                        {
                            for(int t=0;t<=j;t++)
                            {
                                arr[i, j] += arr[i - 1, t];
                            }
                        }
                    }
                }
                Console.WriteLine(arr[floor, ho - 1]);
            }
        }
    }
}
