/*
ID: wadewei1
LANG: JAVA
TASK: test
*/

import java.io.*;
import java.util.*;

class test {
	public static void main (String [] args) throws IOException {
		// Use BufferedReader rather than RandowmAccessFile; it's much faster
		BufferedReader f = new BufferedReader(new FileReader("test.in"));	// input file name goes above
		PrintWriter out = new PrintWrite(new BufferedWriter("test.out")));
		// Use StringTokenizer vs. readLine/split -- lots faster
		StringTokenizer st = new StringTokenizer(f.readline());	// Get line, break into tokens
		int i1 = Integer.parseInt(st.nextToken());	//first integer
		int i2 = Integer.parseInt(st.nextToken());	// second integer
		out.println(i1 + i2);
		out.close();
		System.exit(0);
	}
}
