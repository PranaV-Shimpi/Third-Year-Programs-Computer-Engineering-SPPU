/*
Problem Statement-Write a program to demonstrate subnetting and find the subnet masks.

*/



import java.util.Scanner; 
class subnet 
{ 
	public static void main(String args[]) 
	{ 
		Scanner sc = new Scanner(System.in); 
		System.out.print("\nEnter the ISP ip address : ");
		String ip = sc.nextLine();  
		String split_ip[]=ip.split("\\.");
	         //SPlit the string after every . 
		String split_bip[] = new String[4]; 
	        //split binary ip 
	    String bip = ""; 
		for(int i=0;i<4;i++)
		{
			split_bip[i] = appendZeros(Integer.toBinaryString(Integer.parseInt(split_ip[i]))); 
				// “18” => 18 => 10010=>00010010 // parseInt:- convert string to integer
				//   toBinarystring :-convert int to binary
			bip += split_bip[i]; 
		} 
        System.out.print("IP in binary is "+ bip); 

        System.out.print("\n\nEnter the number of addresses : "); 
        int n = sc.nextInt(); 
    		//Calculation of mask 
        int bits = (int)Math.ceil(Math.log(n)/Math.log(2));  
    	    /*eg if address = 20, log 20/log 2 gives log to the base 2 => 4.9068, ceil gives us upper integer */ 
        System.out.print("\nNumber of bits required for address = " + bits); 
        int mask = 32-bits; 
        System.out.print("\nThe subnet mask is = "  + mask);



		//Calculation of first address and last address
		System.out.println(); 
		
		int cMask[] = new int[32];			//Complement of mask
		for(int i=0;i<32;i++)
		{
			if(i < mask)
				cMask[i] = 1;
			else
				cMask[i] = 0;	
		}
		int fbip[] = new int[32]; 
		for(int i=0; i<32;i++) 
		{
			fbip[i] = (int) bip.charAt(i) - 48; 		//convert character ASCII 0,1 to integer 0,1 
		}
		for(int i=0;i<32;i++)	
		{
			fbip[i] &= cMask[i];			//Get first address by ANDing last n bits with 0  
		}
		String fip[] = {"","","",""}; 
		for(int i=0;i<32;i++) 
			fip[i/8] = new String(fip[i/8]+fbip[i]); 
		System.out.print("\nFirst address is = "); 
		for(int i=0;i<4;i++)
		{ 
			System.out.print(Integer.parseInt(fip[i],2)); //parseInt("20", 16) returns 16, (2)*16^1 + (0)*16^0 = 32
									//means to convert binary to decimal
			if(i!=3)
				System.out.print(".");
		} 
		System.out.println(); 
		
		for(int i=0;i<32;i++)
		{
			if(i < mask)
				cMask[i] = 0;
			else
				cMask[i] = 1;	
		}
		int lbip[] = new int[32]; 
		for(int i=0; i<32;i++) 
			lbip[i] = (int)bip.charAt(i)-48; 	//convert character 0,1 to integer 0,1 
			
		for(int i=0;i<32;i++)       //Get last address by ORing last n bits with 1 
			lbip[i] |= cMask[i];
		
		
		//Convert binary ip to dotted decimal	 
		String lip[] ={"","","",""}; 
		for(int i=0;i<32;i++) 
			lip[i/8] = new String(lip[i/8]+lbip[i]); 
		System.out.print("Last address is = ");
 		for(int i=0;i<4;i++)
		{ 
       		System.out.print(Integer.parseInt(lip[i],2)); 
			if(i!=3) 
				System.out.print(".");
		}

		System.out.print("\n\n"); 
	} 

	static String appendZeros(String s)
	{ 
		String temp = new String("00000000"); 
		return temp.substring(s.length()) + s;
	} 
} 

/*
Output
Enter the ip address: 100.110.150.10 
IP in binary is 01100100011011101001011000001010 
Enter the number of addresses: 7 
Number of bits required for address = 3 
The subnet mask is = 29 
First address is = 100.110.150.8 
Last address is = 100.110.150.15 
*/
