package com.solution._10198;

import java.util.*;
import java.math.*;

public class Main {
	
	public final static int SIZE = 1001;

	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		
		BigInteger[] b1 = new BigInteger[SIZE];
		BigInteger b2, b3, b4;
		int i, n;
		
		b1[1] = new BigInteger("2");
		b1[2] = new BigInteger("5");
		b1[3] = new BigInteger("13");
		
		b4 = new BigInteger("2");
		
		for(i = 4; i < SIZE; i++) {
			
			b2 = b1[i - 2].add(b1[i - 3]);
			b3 = b1[i - 1].multiply(b4);
			b1[i] = b2.add(b3);
		}
		
		while(sc.hasNext()) {
		
			n = sc.nextInt();
			System.out.println(b1[n]);
		}
	}
}
