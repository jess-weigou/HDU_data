package 文件和流;
import java.io.*;
import java.util.Scanner;

public class BufferTest {
    public static void main(String[] args) {
        String s1,s2;
        FileReader fr1 = null;
        FileReader fr2 = null;
        FileWriter fw = null;
        BufferedReader bf = null;
        BufferedWriter bw = null;
        Scanner sc = new Scanner(System.in);
        try{
            //input
            s1 = sc.nextLine();
            s2 = sc.nextLine();

            fr1 = new FileReader(s1);
            fr2 = new FileReader(s2);

            fw = new FileWriter("merge.txt");
            bw = new BufferedWriter(fw);
            String sentence;

            bf = new BufferedReader(fr1);
            while( (sentence = bf.readLine()) != null){
                bw.write(sentence);
            }

            bf = new BufferedReader(fr2);
            while( (sentence = bf.readLine()) != null){
                bw.write(sentence);
            }
            bw.close();
        }catch(FileNotFoundException e){
            System.out.println(e.toString());
        }catch (IOException e){
            System.out.println(e.toString());
        }finally {
            try {
                if(fr1 != null){
                    fr1.close();
                }
                if(fr2 != null){
                    fr2.close();
                }
                if(fw != null){
                    fw.close();
                }
                if(bf != null){
                    bf.close();
                }
            }catch (IOException e){

            }
        }
    }
}
