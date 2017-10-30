package com.solution._748;

import java.util.*;
import java.math.*;

public class Main {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		
		BigDecimal b1;
		String str;
		int n, index;
		
		while(sc.hasNext()) {
			
			b1 = sc.nextBigDecimal();
			n = sc.nextInt();
			b1 = b1.pow(n);
			str = b1.stripTrailingZeros().toPlainString();
			
			if(str.charAt(0) == '0') {
				
				index = str.indexOf('.');
				str = str.substring(index, str.length());
			}
			System.out.println(str);
		}
	}
}
