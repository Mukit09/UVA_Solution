package com.solution._10992;

import java.util.*;
import java.math.*;

public class Main {
	
	public static final int GHOST_NUMBER = 9;

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		BigInteger b0, b1, b4, b100, b400, bStart, diff, bTemp;
		List<String> ghostList = new ArrayList<>();
		String[] ghostNameArray = new String[GHOST_NUMBER];
		int[] timeArray = new int[GHOST_NUMBER];
		int i;
		boolean flag = false;
		
		ghostNameArray[0] = "Tanveer Ahsan";
		ghostNameArray[1] = "Shahriar Manzoor";
		ghostNameArray[2] = "Adrian Kugel";
		ghostNameArray[3] = "Anton Maydell";
		ghostNameArray[4] = "Derek Kisman";
		ghostNameArray[5] = "Rezaul Alam Chowdhury";
		ghostNameArray[6] = "Jimmy Mardell";
		ghostNameArray[7] = "Monirul Hasan";
		ghostNameArray[8] = "K. M. Iftekhar";
		
		timeArray[0] = 2;
		timeArray[1] = 5;
		timeArray[2] = 7;
		timeArray[3] = 11;
		timeArray[4] = 15;
		timeArray[5] = 20;
		timeArray[6] = 28;
		timeArray[7] = 36;
		timeArray[8] = -1;
		
		bStart = new BigInteger("2148");
		b0 = BigInteger.ZERO;
		b4 = new BigInteger(Integer.toString(4));
		b100 = new BigInteger(Integer.toString(100));
		b400 = new BigInteger(Integer.toString(400));
		
		while(sc.hasNext()) {
			
			b1 = sc.nextBigInteger();
			if(b1.compareTo(b0) == 0)
				break;
			
			if(flag)
				System.out.println();
			flag = true;
			System.out.println(b1);
			if(b1.compareTo(bStart) < 0) {
				
				System.out.println("No ghost will come in this year");
				continue;
			}
			
			diff = b1.subtract(bStart);
			for(i = 0;i < 8; i++) {
				
				bTemp = new BigInteger(Integer.toString(timeArray[i]));
				if(diff.remainder(bTemp) == BigInteger.ZERO) {
					
					ghostList.add(ghostNameArray[i]);
				}
			}
			if((b1.remainder(b4) == BigInteger.ZERO && b1.remainder(b100) != BigInteger.ZERO)
					|| b1.remainder(b400) == BigInteger.ZERO) {
				
				ghostList.add("K. M. Iftekhar");
			}
			
			if(ghostList.size() == 0)
				System.out.println("No ghost will come in this year");
			else {
				
				for(i = 0; i < ghostList.size(); i++) {
					
					System.out.println("Ghost of " + ghostList.get(i) + "!!!");
				}
				
				ghostList.clear();
			}
		}
	}
}
