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
            int[] scoreTeam = new int[2];
            int[] timePoint = new int[n];
            int[] ans = new int[2];
            int startTime = 0;
            bool startflag = false;
            for (int i = 0; i < n; i++)
            {
                string[] input = Console.ReadLine().Split(' ');
                string[] time = input[1].Split(':');

                scoreTeam[int.Parse(input[0]) - 1]++;
                timePoint[i] = int.Parse(time[0]) * 60 + int.Parse(time[1]);

                if (scoreTeam[0] != scoreTeam[1] && !startflag)
                {
                    startflag = true;
                    startTime = timePoint[i];
                }

                if (scoreTeam[0] == scoreTeam[1] && startflag)
                {
                    startflag = false;
                    int prevWinTeam = (int.Parse(input[0]) == 1) ? 2 : 1; 

                    ans[prevWinTeam - 1] += timePoint[i] - startTime;
                }

                if (i == n - 1) 
                {
                    if (scoreTeam[0] != scoreTeam[1])
                    {
                        int prevWinTeam = (scoreTeam[0] > scoreTeam[1]) ? 1 : 2;
                        ans[prevWinTeam - 1] += 2880 - startTime;
                    }
                }
            }
            Console.WriteLine("{0:D2}:{1:D2}", ans[0] / 60, ans[0] % 60);
            Console.WriteLine("{0:D2}:{1:D2}", ans[1] / 60, ans[1] % 60);
        } 
    }
}
