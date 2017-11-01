package com.solution._10433;

import java.util.*;
import java.math.*;

public class Main {

	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		
		BigInteger b1, b2;
		String st1, st2, input;
		int len1, len2;
		
		while(sc.hasNext()) {
			
			input = sc.nextLine();
			b1 = new BigInteger(input);
			if(b1.compareTo(BigInteger.ONE) == 0 || b1.compareTo(BigInteger.ZERO) == 0) {
				
				System.out.println("Not an Automorphic number.");
				continue;
			}
			b2 = b1.pow(2);
			st1 = input;
			st2 = b2.toString();
			len1 = st1.length();
			len2 = st2.length();
			
			if(len2 <= len1) {
				
				System.out.println("Not an Automorphic number.");
				continue;
			}
			
			if(st1.compareTo(st2.substring(len2 - len1, len2)) == 0)
				System.out.println("Automorphic number of " + len1 + "-digit.");
			else
				System.out.println("Not an Automorphic number.");
		}
	}
}
