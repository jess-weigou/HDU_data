package 文件和流;

import java.io.File;
import java.io.IOException;
import java.io.RandomAccessFile;
import java.util.RandomAccess;
import java.util.Scanner;

public class randomInsert {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        double doubelNum;
        String str;
        RandomAccessFile randomAccessFile = null;
        File file = new File("B.txt");
        try{

            randomAccessFile = new RandomAccessFile(file, "rw") ;
            for(int i=0;i<10;i++){
                doubelNum = sc.nextDouble();
                str = Double.toString(doubelNum)+'\n';
                randomAccessFile.writeBytes(str);
                if(i == 3){
                    randomAccessFile.writeBytes("1\n");
                }
            }
            randomAccessFile = new RandomAccessFile(file, "rw") ;
            while((str = randomAccessFile.readLine()) != null){
                System.out.println(str);
            }
        }catch(IOException e){
        }finally {
            try {
                if(randomAccessFile != null){
                    randomAccessFile.close();
                }
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }



}
