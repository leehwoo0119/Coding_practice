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
            int Num = int.Parse(Console.ReadLine());
            while(Num--!=0)
            {
                string input = Console.ReadLine();
                string[] inputarr = input.Split();
                int studentNum = int.Parse(inputarr[0]);
                int[] score = new int[studentNum];

                int avg = 0;
                for (int i = 0; i < studentNum; i++)
                {
                    score[i] = int.Parse(inputarr[i + 1]);
                    avg += score[i];
                }
                avg /= studentNum;
                int cnt = 0;
                for (int i = 0; i < studentNum; i++)
                {
                    if (score[i] > avg) cnt++;
                }
                float result = cnt / (float)studentNum;
                Console.WriteLine("{0:#0.000}" + "%", result);
            }
           
        }
    }
}
