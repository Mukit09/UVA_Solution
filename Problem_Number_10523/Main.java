package com.solution._10523;

import java.util.*;
import java.math.*;

public class Main {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		BigInteger b1, b2, b3, b4, b5;
		
		int n, i, a;
		
		b1 = BigInteger.ONE;
		
		while(sc.hasNext()) {
			
			n = sc.nextInt();
			a = sc.nextInt();
			
			b3 = new BigInteger(Integer.toString(a));
			b2 = BigInteger.ONE;
			b5 = BigInteger.ZERO;
			
			for(i = 1; i <= n; i++) {
				
				b4 = b3.pow(i);
				b4 = b4.multiply(b2);
				b5 = b5.add(b4);
				b2 = b2.add(b1);
			}
			System.out.println(b5);
		}
	}
}
