using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp2
{
    public class Stack
    {
        public int[] arr;
        public int len;
    }


    class Program
    {
        static StringBuilder sb = new StringBuilder();
        static void Push(Stack stack, int input)
        {
            stack.arr[stack.len++] = input;
        }
        static int Pop(Stack stack)
        {
            if (stack.len == 0)
                return -1;
            else
            {
                stack.len--;
                int top = stack.arr[stack.len]
                return top;
            }

        }
        static int Size(Stack stack)
        {
            return stack.len;
        }
        static int Empty(Stack stack)
        {
            if (stack.len == 0)
                return 1;
            else
                return 0;
        }
        static int Top(Stack stack)
        {
            if (Empty(stack) == 1)
                return -1;
            else
                return stack.arr[stack.len - 1];
        }
        static void Main(string[] args)
        {

            Stack stack = new Stack();
            stack.arr = new int[100000];
            stack.len = 0;

            int n = int.Parse(Console.ReadLine());

            while (n-- != 0)
            {
                string input = Console.ReadLine();
                string[] inputarr = input.Split(' ');

                string OrderType = inputarr[0];
                int num = 0;
                if (OrderType == "push")
                    num = int.Parse(inputarr[1]);

                if (OrderType == "push")
                {
                    Push(stack, num);
                }
                else if (OrderType == "pop")
                {
                    sb.Append(Pop(stack) + "\n");
                }
                else if (OrderType == "size")
                {
                    sb.Append(Size(stack) + "\n");
                }
                else if (OrderType == "empty")
                {
                    sb.Append(Empty(stack) + "\n");
                }
                else if (OrderType == "top")
                {
                    sb.Append(Top(stack) + "\n");
                }

            }
            Console.Write(sb);
        }
    }
}


