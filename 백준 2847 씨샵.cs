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
            int[] arr = new int[n];
            for(int i=0;i<n;i++)
            {
                int m = int.Parse(Console.ReadLine());
                arr[i] = m;
            }
            int cnt = 0;
            for(int i=n-1;i>0;i--)
            {
                if (arr[i] < arr[i - 1])
                {
                    cnt += arr[i - 1] - arr[i] + 1;
                    arr[i - 1] = arr[i] - 1;
                }
           
            }
            Console.WriteLine(cnt);
        }
    }
}
