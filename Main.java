package com.example.javalib;
import java.util.Scanner;
import java.util.Arrays;
public class Main {
    public static void main(String args[])
    {
        Scanner s = new Scanner(System.in);
        int a=s.nextInt();
        int b=s.nextInt();
        int c=s.nextInt();
        int []arr=new int[10];
        long temp= a*b*c;
        int n=0;
        while(temp!=0)
        {
            arr[(int)(temp%10)]++;
            temp/=10;
        }
        for(int x:arr)
            System.out.println(x);
    }
}