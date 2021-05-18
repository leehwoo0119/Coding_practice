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
            int n = 10001;
            string input = Console.ReadLine();
            string[] inputarr = input.Split();
            int r1 = int.Parse(inputarr[0] ) + 5000;
            int c1 = int.Parse(inputarr[1] ) + 5000;
            int r2 = int.Parse(inputarr[2] ) + 5000;
            int c2 = int.Parse(inputarr[3] ) + 5000;

            long[,] arr = new long[r2 - r1 + 1, c2 - c1 + 1];


            for (int i = 0; i <= r2 - r1; i++)
            {
                for (int j = 0; j <= c2 - c1; j++)
                {
                    arr[i, j] = 1;
                }
            }

            int updownMaxCnt = 1;

            int len = (n + n + 1) * (n + n + 1);

            int dep = 1, y = n / 2, x = n / 2;
            int type = 0;

            int rLen = (r2 - r1 > 0) ? (r2 - r1) * 1 : (r2 - r1) * -1;
            int cLen = (c2 - c1 > 0) ? (c2 - c1) * 1 : (c2 - c1) * -1;
          



            if (y >= r1 && x >= c1 && y <= r2 && x <= c2)
                arr[y - r1, x - c1] = dep;

            dep += 1;

            long max = 0;

            while (dep < n * n)
            {
                if (type == 4) type = 0;



                for (int j = 0; j < updownMaxCnt; j++)
                {
                    if (type == 0) x++;
                    else x--;
                    if (y >= r1 && x >= c1 && y <= r2 && x <= c2)
                    {
                        arr[y - r1, x - c1] = dep;
                        if (max < dep) max = dep;
                    }
                    dep++; 
                }
                type++;

                for (int j = 0; j < updownMaxCnt; j++)
                {
                    if (type == 1) y--;
                    else y++;
                    if (y >= r1 && x >= c1 && y <= r2 && x <= c2)
                    {
                        arr[y - r1, x - c1] = dep;
                        if (max < dep) max = dep;
                    }
                    dep++; 
                }
                type++;
                updownMaxCnt++;
            }
            
           


            int wordlen = 0;
            while (max != 0)
            {
                wordlen++;
                max /= 10;
            }
            StringBuilder sb = new StringBuilder();

            for (int i = 0; i <= rLen; i++)
            {
                for (int j = 0; j <= cLen; j++)
                {
                  
                    sb.Append(arr[i, j].ToString().PadLeft(wordlen) + " ");
                }
                sb.Append("\n");
            }
            Console.Write(sb);
        }
    }
}

