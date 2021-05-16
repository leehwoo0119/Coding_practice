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

            int n = int.Parse(inputarr[0]);
            int m = int.Parse(inputarr[1]);

            string input_2 = Console.ReadLine();
            string[] inputarr_2 = input_2.Split();
            int[] num = new int[n];

            for (int i = 0; i < n; i++)
            {
                num[i] = int.Parse(inputarr_2[i]);
            }
            int sum = 0;
            int maxSum = 0;
            for (int i = 0; i < n; i++) 
            {
                for (int j = i + 1; j < n; j++)
                {
                    for (int t = j + 1; t < n; t++)
                    {
                        // Console.Write(i + " " + j + " " + t + "\n");
                        sum = num[i] + num[j] + num[t];

                        if(sum<=m)
                        {
                            if (maxSum < sum)
                            {
                                maxSum = sum;
                            }
                        }
                        
                    }
                }
            }
            Console.Write(maxSum);
        }
    }
}
