package com.solution._1226;

import java.util.*;
import java.math.*;

public class Main {

	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		BigInteger n, p;
		int testCase;
		
		testCase = sc.nextInt();
		
		while(testCase-- > 0) {
			
			n = sc.nextBigInteger();
			p = sc.nextBigInteger();
			
			System.out.println(p.remainder(n));
		}
	}

}
