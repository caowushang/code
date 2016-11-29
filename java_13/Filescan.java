/* ************************************************************************
	> File Name: Filescan.java
	> Author: caowushang
	> Mail: 15630929347@163.com 
	> Created Time: 2016年11月29日 星期二 18时32分22秒
 ************************************************************************/
import java.util.*;
import java.io.*;
public class Filescan{
	public static void main(String[] args)throws IOException{
		double sum=0;
		int cnt=0;
		FileReader fi=new FileReader("file.txt");
		Scanner scanner=new Scanner(fi);
		scanner.useDelimiter("\\D+");
		while(scanner.hasNext()){
				double x=scanner.nextDouble();
				System.out.println(x);
				sum=sum+x;
				cnt++;
		}
		fi.close();
		System.out.println("平均价格："+sum/cnt);
	}
}
