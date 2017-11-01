package com.solution._10083;

import java.util.*;
import java.math.*;

public class Main {

	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		
		BigInteger tt, ta, tb, t0, t1, tResult, tRemainder;
		String st;
		int t, a, b;
		
		t0 = BigInteger.ZERO;
		t1 = BigInteger.ONE;
		
		while(sc.hasNext()) {
			
			t = sc.nextInt();
			a = sc.nextInt();
			b = sc.nextInt();
			
			st = "(" + Integer.toString(t) + "^" + Integer.toString(a) + "-1)";
			st = st.concat("/");
			st = st.concat("(" + Integer.toString(t) + "^" + Integer.toString(b) + "-1)");
			
			if(t == 1) {
				
				System.out.println(st + " " + "is not an integer with less than 100 digits.");
				continue;
			}
			
			if(a == b) {
				
				System.out.println(st + " 1");
				continue;
			}
			
			if(a%b != 0) {
				
				System.out.println(st + " " + "is not an integer with less than 100 digits.");
				continue;
			}
			
			if((a - b) * Math.log10(t) < 99) {
				
				tt = BigInteger.valueOf(t);
				ta = tt.pow(a);
				ta = ta.subtract(t1);
				tb = tt.pow(b);
				tb = tb.subtract(t1);
				
				tResult = ta.divide(tb);
				tRemainder = ta.remainder(tb);
				if(tRemainder.compareTo(t0) == 0 && tResult.toString().length() < 100) 
					System.out.println(st + " " + tResult);
				else
					System.out.println(st + " " + "is not an integer with less than 100 digits.");
			}
			else {
				
				System.out.println(st + " " + "is not an integer with less than 100 digits.");
			}
		}
	}
}
