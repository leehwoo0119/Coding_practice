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
            int n;
            int k;
            int updownMaxCnt = 0; ;
            int updownCnt = 0; ;
            int saveY =0;
            int saveX =0;
            int[,] arr;
            n = int.Parse(Console.ReadLine());
            k = int.Parse(Console.ReadLine());
           
            arr = new int[n+1, n+1];
            int dep = 1,y = n / 2,x = n / 2;
            int type = 0;

           while(dep <= n * n)
            { 
                switch(type % 4)
                {
                    case 0:
                        arr[y, x] = dep;
                        if (updownCnt != updownMaxCnt)
                        {
                            updownCnt++;
                        }
                        else
                        {
                            updownCnt = 0;
                            type++;
                        }
                        if (dep == k)
                        {
                            saveY = y + 1; saveX = x + 1;
                        }
                        y -= 1; dep++;
                        break;
                    case 1:
                        arr[y, x] = dep;
                        if (updownCnt != updownMaxCnt)
                        {
                            updownCnt++;
                        }
                        else
                        {
                            updownCnt = 0; updownMaxCnt++;
                            type++;
                        }
                        if (dep == k)
                        {
                            saveY = y + 1; saveX = x + 1;
                        }
                        x += 1; dep++;
                        break;
                    case 2:
                        arr[y, x] = dep;
                        if (updownCnt != updownMaxCnt)
                        {
                            updownCnt++;
                        }
                        else
                        {
                            updownCnt = 0;
                            type++;
                        }
                        if (dep == k)
                        {
                            saveY = y + 1; saveX = x + 1;
                        }
                        y += 1; dep++;
                        break;
                        case 3:
                        arr[y, x] = dep;
                        if (updownCnt != updownMaxCnt)
                        {
                            updownCnt++;
                        }
                        else
                        {
                            updownCnt = 0; updownMaxCnt++;
                            type++;
                        }
                        if (dep == k)
                        {
                            saveY = y + 1; saveX = x + 1;
                        }
                        x -= 1; dep++;
                        break;
                    default: break;
                }

               
            }

            StringBuilder sb = new StringBuilder();

            for (int i = 0; i < n; i++) 
            {
                for (int j = 0; j < n; j++)
                {
                    sb.Append(arr[i, j] + " ");
                }
                sb.Append("\n");
            }
            Console.Write(sb);
            Console.Write(saveY+ " " + saveX);
        }
    }
}
