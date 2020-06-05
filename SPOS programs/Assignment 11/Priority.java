/*
 * Program : Priority Scheduling
 * Name    : PranaV Shimpi
 * Class   : TE A
 * RNo.    : 62
 */

import java.util.*;
import java.util.Scanner;

public class Priority
{
	public static void main(String[] Args)
	{
		Scanner sc = new Scanner(System.in);
		int n,i,j,temp;
		System.out.print("Enter the number of processes : ");
		n = sc.nextInt();
		int[] BurT = new int[n];
		int[] PNo = new int[n];
		int[] P = new int[n];
		int[] ST = new int[n];
		int[] CT = new int[n];
		System.out.print("\n");
		for(i = 0; i < n; i++)
		{
			System.out.print("Enter the Process number : ");
			PNo[i] = sc.nextInt();
			System.out.print("Enter the Burst Time of : ");
			BurT[i] = sc.nextInt();
			System.out.print("Enter the priority of : ");
			P[i] = sc.nextInt();
			ST[i] = 0;
			CT[i] = 0;
			System.out.print("\n");
		}
		System.out.print("\n");
		System.out.print("---------------------------------------------------------\n");
		System.out.print("|Process\t|\tBurst_Time\t|\tPriority|\n");
		System.out.print("---------------------------------------------------------\n");
		for(i = 0; i < n; i++)
		{
			System.out.print("|"+ PNo[i] +"\t\t|\t"+ BurT[i] +"\t\t|\t"+ P[i] +"\t|\n");
			System.out.print("---------------------------------------------------------\n");
		}
		for(i = 0; i < n; i++)
		{
			for(j = i + 1; j < n; j++)
			{
				if(P[i] > P[j])
				{
					temp = P[i];
					P[i] = P[j];
					P[j] = temp;
					
					temp = BurT[i];
					BurT[i] = BurT[j];
					BurT[j] = temp;
					
					temp = PNo[i];
					PNo[i] = PNo[j];
					PNo[j] = temp;
				}
			}
		}
		System.out.print("\n Table after Sorting \n");
		System.out.print("---------------------------------------------------------\n");
		System.out.print("|Process\t|\tBurst_Time\t|\tPriority|\n");
		System.out.print("---------------------------------------------------------\n");
		for(i = 0; i < n; i++)
		{
			System.out.print("|"+ PNo[i] +"\t\t|\t"+ BurT[i] +"\t\t|\t"+ P[i] +"\t|\n");
			System.out.print("---------------------------------------------------------\n");
		}
		System.out.print("\n");
		for(i = 0; i < n; i++)
		{
			System.out.print("----------------");	
		}
		System.out.print("\n|");
		for(i = 0; i < n; i++)
		{
			System.out.print("\t" + PNo[i] + "\t|");
		}
		System.out.print("\n");
		for(i = 0; i < n; i++)
		{
			System.out.print("----------------");	
		}
		System.out.print("\n");
		for(i = 0; i < n; i++)
		{
			if(i == 0)
			{
				CT[i] = BurT[i];
				System.out.print(""+ ST[i] +"\t\t"+ CT[i]);
			}
			else
			{
				ST[i] = CT[i - 1];
				CT[i] = CT[i - 1] + BurT[i];
				System.out.print("\t\t"+ CT[i]);
			}
		}
		System.out.print("\n");
	}
}

/*

Output:

C:\Users\Lenovo\Downloads>javac Priority.java

C:\Users\Lenovo\Downloads>java Priority
Enter the number of processes : 3

Enter the Process number : 1
Enter the Burst Time of : 4
Enter the priority of : 2

Enter the Process number : 2
Enter the Burst Time of : 3
Enter the priority of : 1

Enter the Process number : 3
Enter the Burst Time of : 4
Enter the priority of : 3


---------------------------------------------------------
|Process        |       Burst_Time      |       Priority|
---------------------------------------------------------
|1              |       4               |       2       |
---------------------------------------------------------
|2              |       3               |       1       |
---------------------------------------------------------
|3              |       4               |       3       |
---------------------------------------------------------

 Table after Sorting
---------------------------------------------------------
|Process        |       Burst_Time      |       Priority|
---------------------------------------------------------
|2              |       3               |       1       |
---------------------------------------------------------
|1              |       4               |       2       |
---------------------------------------------------------
|3              |       4               |       3       |
---------------------------------------------------------

------------------------------------------------
|       2       |       1       |       3       |
------------------------------------------------
0               3               7               11

*/
