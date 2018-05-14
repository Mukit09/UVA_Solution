package com.solution._11287;

import java.util.*;
import java.math.*;

public class Main {
	
	public static BigInteger givePower(BigInteger tmp, BigInteger mod, long power) {
		
		if(power == 0)
			return BigInteger.ONE;
		BigInteger b = givePower(tmp, mod, power/2);
		b = b.multiply(b);
		if(power % 2 == 1)
			b = b.multiply(tmp);
		return b.remainder(mod);
	}

	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		BigInteger b1, b2, mod;
		long p, a;
		
		while(sc.hasNext()) {
			
			p = sc.nextLong();
			a = sc.nextLong();
			
			if(p == 0 && a == 0)
				break;

			mod = new BigInteger(Long.toString(p));
			b1 = new BigInteger(Long.toString(a));
			if(mod.isProbablePrime(1)) {
				
				System.out.println("no");
				continue;
			}
			b2 = givePower(b1, mod, p);
			if(b2.remainder(mod).equals(b1) == true)
				System.out.println("yes");
			else 
				System.out.println("no");
		}
	}
}
