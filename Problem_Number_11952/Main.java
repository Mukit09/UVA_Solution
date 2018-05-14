package com.solution._11952;

import java.util.*;
import java.math.*;

public class Main {
	
	public static boolean checkBase(String temp, int base) {
		
		for(int j = 0; j < temp.length(); j++) {
			
			if(temp.charAt(j) - 48 >= base )
				return false;
		}
		return true;
	}
	
	public static int getPow(int b, int power) {
		
		int i = 1, ret = 1;
		
		while(i <= power) {
			
			ret *= b;
			i++;
		}
		return ret;
	}

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		
		String st;
		String[] temp = new String[4];
		int testCase, a, b, n, i, j, tempLength, tempA, tempB, tempN;
		boolean found;
		
		testCase = sc.nextInt();
		sc.nextLine();
		while(testCase-- > 0) {
			
			st = sc.nextLine();
			temp = st.split("[ =+]+");
			found = false;
			
			for(i = 2; i <= 19; i++) {
			
				a = b = n = 0;
				
				if(checkBase(temp[0], i) && checkBase(temp[1], i) && checkBase(temp[2], i))
				{
					tempLength = temp[0].length();
					for(j = 0; j < temp[0].length(); j++) {
						
						tempA = (temp[0].charAt(j) - 48) * getPow(i, tempLength - 1);
						a = a + tempA;
						tempLength--;
					}
				
					tempLength = temp[1].length();
					for(j = 0; j < temp[1].length(); j++) {
						
						tempB = (temp[1].charAt(j) - 48) * getPow(i, tempLength - 1);
						b = b + tempB;
						tempLength--;
					}
					
					tempLength = temp[2].length();
					for(j = 0; j < temp[2].length(); j++) {
						
						tempN = (temp[2].charAt(j) - 48) * getPow(i, tempLength - 1);
						n = n + tempN;
						tempLength--;
					}
					
					if(a + b == n) {
						
						found = true;
						break;
					}
				}
			}
			if(found)
				System.out.println(i);
			else {
				
				if((temp[0] + temp[1]).equals(temp[2]))
					System.out.println("1");
				else
					System.out.println("0");
			}
		}
	}
}
