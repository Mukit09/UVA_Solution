package com.solution._297;

import java.util.Scanner;

public class Main {
	
	public static int givePixelNumber(Node node, int pixels) {
		
		if(node == null)
			return 0;
		if(node.isBlack)
			return pixels * pixels;
		int i, sum=0;
		if(node.isParent) {
			
			for(i=0; i<4; i++) {
				
				sum+=givePixelNumber(node.nodeArray[i], pixels/2);
			}
		}
		return sum;
	}
	
	public static int getAnswer(Node node1, Node node2, int pixels) {
		
		if(node1 == null && node2 == null)
			return 0;
		if(node1 == null) {
			int pixelNumbers = givePixelNumber(node2, pixels);
			return pixelNumbers;
		}
		else if(node2 == null) {
			
			int pixelNumbers = givePixelNumber(node1, pixels);
			return pixelNumbers;
		}
		if(node1.isBlack || node2.isBlack) {
			return pixels * pixels;
		}
		
		int sum = 0, i;
		if(node1.isParent || node2.isParent) {
			
			for(i=0;i<4;i++) {
				
				sum += getAnswer(node1.nodeArray[i], node2.nodeArray[i], pixels/2);
			}
		}
		return sum;
	}
	
	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		int testCase, len1, len2, totalPixel;
		String st1, st2;
		
		testCase = sc.nextInt();
		sc.nextLine();
		while(testCase-->0) {
			
			totalPixel = 0;
			Node node1 = new Node();
			Node node2 = new Node();
			
			st1 = sc.nextLine();
			st2 = sc.nextLine();
			
			len1 = st1.length();
			len2 = st2.length();
			
			node1.buildTree(0, len1, st1, node1);
			node2.buildTree(0, len2, st2, node2);
			
			totalPixel = getAnswer(node1, node2, 32);
			System.out.println("There are " + totalPixel + " black pixels.");
		}
	}
}

class Node {
	
	Node nodeArray[] = new Node[4];
	public boolean isBlack, isParent;
	
	Node() {
		
		isBlack = isParent = false;
		for(int i=0;i<4;i++) {
			
			nodeArray[i] = null;
		}
	}
	
	public int buildTree(int index, int len, String st, Node node) {
		
		if(index >= len)
			return index;
		int tmpIndex, i;
		if(st.charAt(index) == 'p') {
			
			tmpIndex = index + 1;
			node.isParent = true;
			for(i = 0; i<4; i++) {
				
				node.nodeArray[i] = new Node();
				tmpIndex = buildTree(tmpIndex, len, st, node.nodeArray[i]);
			}
			return tmpIndex;
		}
		else {
			
			if(st.charAt(index) == 'f') {
				
				node.isBlack = true;
			}
			return index + 1;
		}
	}
}