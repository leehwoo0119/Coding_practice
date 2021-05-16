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

            int[] arr = new int[n];
            int[] pokjuk = new int[m + 1];
            int ans = 0;
            for (int i = 0; i < n; i++) 
            {
                int c = int.Parse(Console.ReadLine());
                arr[i] = c;
            }

            for (int i = 0; i < n; i++)
            {
                for (int j = arr[i]; j <= m; j+= arr[i])
                {
                    pokjuk[j] = 1;
                }
            }

            int cnt = 0;

            for (int i = 1; i <= m; i++)
            {
                if (pokjuk[i] == 1) cnt++;
            }
            Console.WriteLine(cnt);
        }
    }
}
