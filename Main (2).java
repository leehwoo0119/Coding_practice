package com.example.javalib;
import java.util.Scanner;
import java.util.Arrays;
public class Main {
    public static void main(String args[])
    {
        Scanner s = new Scanner(System.in);
        int[] day={31,28,31,30,31,30,31,31,30,31,30,31};
        int x=s.nextInt();
        int y=s.nextInt();
        int sum=0;
        for(int i=0;i<=x-2;i++)sum+=day[i];
        sum+=y;
        switch(sum%7)
        {
            case 1:
                System.out.println("MON");
                break;
            case 2:
                System.out.println("TUE");
                break;
            case 3:
                System.out.println("WED");
                break;
            case 4:
                System.out.println("THU");
                break;
            case 5:
                System.out.println("FRI");
                break;
            case 6:
                System.out.println("SAT");
                break;
            case 0:
                System.out.println("SUN");
                break;
        }
    }
}