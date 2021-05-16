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
            int s = int.Parse(inputarr[1]);

            string input_2 = Console.ReadLine();
            string[] inputarr_2 = input_2.Split();
            int[] arr = new int[n];

            for(int i=0;i<n;i++)
            {
                arr[i] = int.Parse(inputarr_2[i]);
            }

            int left = 0;
            int right = 0;           
            int temp = arr[left];
            int cnt = n + 1;
            while(left <= right && right < n)
            {
                if (temp < s ) 
                {
                    right++;
                    if(right<n) temp += arr[right];
                }
                else
                {
                    if (cnt > right - left)
                        cnt = right - left;
                    temp -= arr[left];
                    left++;
                }

                // Console.Write(right + " " + left + " " + temp + "\n");
            }
            if(cnt == n + 1) Console.WriteLine("0");
            else Console.WriteLine(cnt + 1);
        }
    }
}
