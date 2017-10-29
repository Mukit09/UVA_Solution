package com.solution._10567;

import java.util.*;

public class Main {

	public static final int STATE_NUMBER = 55;
	public static final int CANDIDATE_NUMBER = 1000010;
	
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		
		String st, ss;
		int n, i, ind, stLen, ssLen, lastFound, tempIndex, low, high, mid, startIndex, endIndex;
		int candidateNumberInState[] = new int[STATE_NUMBER];
		int candidateIndexesInState[][] = new int[STATE_NUMBER][CANDIDATE_NUMBER];
		boolean found;
		
		st = sc.nextLine();
		n = sc.nextInt();
		sc.nextLine();
		
		for(i = 0; i < STATE_NUMBER; i++) {
			
			candidateNumberInState[i] = 0;
		}
		
		stLen = st.length();
		
		for(i = 0; i < stLen; i++) {
			
			if(st.charAt(i) >= 65 && st.charAt(i) <= 90) 
				ind = st.charAt(i) - 65;
			else 
				ind = st.charAt(i) - 71;
			
			tempIndex = candidateNumberInState[ind];
			candidateIndexesInState[ind][tempIndex] = i;
			candidateNumberInState[ind]++;
		}
		
		while(n-->0) {
			
			lastFound = startIndex = endIndex = -1;
			found = true;
			
			ss = sc.nextLine();
			ssLen = ss.length();
			
			for(i = 0; i < ssLen; i++) {
				
				if(ss.charAt(i) >= 65 && ss.charAt(i) <= 90) 
					ind = ss.charAt(i) - 65;
				else 
					ind = ss.charAt(i) - 71;
				
				low = 0;
				high = candidateNumberInState[ind] - 1;
				tempIndex = -1;
				
				while(low<=high) {
					
					mid = (low + high)/2;
					if(candidateIndexesInState[ind][mid] > lastFound) {
						
						tempIndex = candidateIndexesInState[ind][mid];
						high = mid - 1;
					}
					else
						low = mid + 1;
				}
				
				if(tempIndex >= 0) {
					
					if(i == 0)
						startIndex = tempIndex;
					endIndex = lastFound = tempIndex;
				}
				else {
					
					found = false;
					break;
				}		
			}	
			if(found) 
				System.out.println("Matched " + startIndex + " " + endIndex);
			else
				System.out.println("Not matched");
		}
	}
}
