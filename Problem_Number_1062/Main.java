package com.solution._1062;

import java.util.ArrayList;
import java.util.Scanner;
import java.util.Stack;

public class Main {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		Stack<String> stk;
		ArrayList<Stack<String>> arrayList = new ArrayList<>();
		String input, st;
		int len, i, j, ind = -1, testCase = 1;
		char ch, minChar;
		boolean found;
		
		while(sc.hasNext()) {
			
			input = sc.nextLine();
			if(input.equals("end") == true)
				break;
			
			len = input.length();
			for(i=0; i<len; i++) {
				
				found = false;
				ch = input.charAt(i);
				j = 0;
				minChar = 'a';
				for(Stack<String> tmpStack : arrayList) {
					
					st = tmpStack.peek();
					if(ch <= st.charAt(0) && minChar > st.charAt(0)) {
						
						ind = j;
						minChar = st.charAt(0);
						found = true;
					}
					j++;
				}
				
				st = "" + ch;
				if(found) {
					
					arrayList.get(ind).push(st);
				}
				else {
					
					stk = new Stack<>();
					stk.push(st);
					arrayList.add(stk);
				}
			}
			System.out.println("Case " + testCase + ": " + arrayList.size());
			arrayList.clear();
			testCase++;
		}		
	}

}
