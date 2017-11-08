package com.solution._10551;

import java.util.*;
import java.math.*;

public class Main {

	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		BigInteger b1, b2, b, p, m, numberInBaseTen, mInBaseTen, remains;
		int i, len, pow;
		String temp;
		String[] st = new String[3];
		while(sc.hasNext()) {
			
			temp = sc.nextLine();
			if(temp.equals("0") == true)
				break;
			st = temp.split(" ");
			b = new BigInteger(st[0]);
			p = new BigInteger(st[1]);
			m = new BigInteger(st[2]);
			
			len = st[1].length();
			pow = len - 1;
			numberInBaseTen = BigInteger.ZERO;
			
			for(i = 0; i < len; i++) {
				
				temp = String.valueOf(st[1].charAt(i));
				b1 = new BigInteger(temp);
				b2 = b.pow(pow);
				numberInBaseTen = numberInBaseTen.add(b1.multiply(b2));
				pow--;
			}
			
			len = st[2].length();
			pow = len - 1;
			mInBaseTen = BigInteger.ZERO;
			
			for(i = 0; i < len; i++) {
				
				temp = String.valueOf(st[2].charAt(i));
				b1 = new BigInteger(temp);
				b2 = b.pow(pow);
				mInBaseTen = mInBaseTen.add(b1.multiply(b2));
				pow--;
			}
			remains = numberInBaseTen.remainder(mInBaseTen);
			System.out.println(remains.toString(Integer.parseInt(st[0])));
		}
	}
}
