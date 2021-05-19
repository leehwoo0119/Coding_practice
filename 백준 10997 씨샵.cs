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
        static int[,] arr;
        static int updownMaxCnt;
        static void insert(int y, int x, int dir)
        {           

            //Console.Write(y + " " + x + "\n");
            if (dir == 4) dir = 0;

            switch(dir)
            {
                case 0:
                    for (int i = 0; i < updownMaxCnt; i++) 
                    {
                        y--; arr[y, x] = 2;
                    }
                    break;
                case 1:
                    for (int i = 0; i < updownMaxCnt; i++)
                    {
                        if (y == 0 && x > n * 4 - 5)
                            return;
                        x++; arr[y, x] = 2;
                    }
                    updownMaxCnt += 2;
                    break;
                case 2:
                    for (int i = 0; i < updownMaxCnt; i++)
                    {
                        y++; arr[y, x] = 2;
                    }
                    break;
                case 3:
                    for (int i = 0; i < updownMaxCnt; i++)
                    {
                        x--; arr[y, x] = 2;
                    }
                    updownMaxCnt += 2;
                    break;
                default:
                    break;
            }
            
            insert(y, x, dir + 1);
        }
        static void Main(string[] args)
        {
            n = int.Parse(Console.ReadLine());
            if (n == 1)
                arr = new int[1, 1];
            else
                arr = new int[n * 4 - 1, n * 4 - 3];

            updownMaxCnt = 2;

            if (n == 1)
                sb.Append("*");
            else
            {
                arr[n * 2, n * 2 - 2] = 2;
                insert(n * 2, n * 2 - 2, 0);

                for (int i = 0; i < n * 4 - 1; i++)
                {
                    for (int j = 0; j < n * 4 - 3; j++)
                    {
                        if (arr[i, j] == 2)
                            sb.Append("*");
                        else
                            sb.Append(" ");
                    }
                    sb.Append("\n");
                }
            }
          
          
            Console.Write(sb);
        }
    }
}

