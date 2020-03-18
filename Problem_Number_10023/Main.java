package Problem_Number_10023;

import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int testCase = scanner.nextInt();
        BigInteger bigIntegerTwo = new BigInteger("2");

        while (testCase > 0) {
            testCase--;

            BigInteger number = scanner.nextBigInteger();
            if(number.compareTo(BigInteger.ONE) == 0) {
                System.out.println(1);
                if (testCase > 0)
                    System.out.println();
                continue;
            }
            BigInteger low = BigInteger.ZERO, high = number.subtract(BigInteger.ONE), mid = BigInteger.ONE, square;

            while (high.compareTo(low) > 0) {
                mid = low.add(high).divide(bigIntegerTwo);
                square = mid.multiply(mid);
                int checkValue = square.compareTo(number);
                if(checkValue == 0) {
                    break;
                } else if (checkValue > 0) {
                    high = mid;
                } else {
                    low = mid.add(BigInteger.ONE);
                }
            }
            System.out.println(mid);
            if (testCase > 0)
                System.out.println();
        }
    }
}
