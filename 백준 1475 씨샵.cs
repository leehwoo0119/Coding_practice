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
            int[] num = new int[10];

            int input = int.Parse(Console.ReadLine());

            while(input!=0)
            {
                num[input % 10]++;
                input /= 10;
            }

            num[6] += num[9];
            num[9] = 0;

            int cnt = 0;
            while(true)
            {
                cnt++;              
                for(int i=0;i<9;i++)
                {
                    if (i != 6) num[i] = (num[i] > 0) ? num[i] -= 1 : num[i] -= 0;
                    else num[i] = (num[i] > 1) ? num[i] -= 2: (num[i] > 0) ? num[i] -= 1 : num[i] -= 0;
                }
                int sum = num.Sum();
                if (sum == 0) break;
            }
            Console.WriteLine(cnt);
        }
    }
}
